#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <iostream>
#include <vector>
#include <map>

#include "upm.h"
#include "upm_controller_servo.h"
#include "upm_sensor_temperature.h"
#include "upm_sensor_pressure.h"
#include "upm_sensor_ph.h"

#define SENSOR_LIB_DIR "/tmp/upm/install/lib"

std::ostream& operator<<(std::ostream& os, const upm_sensor_descriptor& usd)
{
    os << "\tname: " << usd.name << std::endl
        << "\tdesc: " << usd.description << std::endl
        << "\tfunctions: ";

    for (int i = 0; (i < upm_sensor_category_size)
            && (usd.category[i] != UPM_INVALID); i++)
        os << to_char(usd.category[i]) << "(" << usd.category[i] << ") ";
    os << std::endl;
}

bool endswith(const std::string &str, const std::string &suffix)
{
    return str.size() >= suffix.size() &&
        str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

// Return vector of full-path to files matchine ext
std::vector<std::string> get_files_endswith(std::string lib_path = ".", std::string ext = ".so")
{
    DIR* dir;
    dirent* pdir;
    std::vector<std::string> files;

    // If the directory doesn't exist, return an empty vector
    struct stat buf;
    if (stat(lib_path.c_str(), &buf) == 0 && S_ISDIR(buf.st_mode))
    {
        dir = opendir(lib_path.c_str());

        while (pdir = readdir(dir))
            if (endswith(pdir->d_name, ext))
            {
                char *real_path = realpath((lib_path + pdir->d_name).c_str(), NULL);
                if (real_path != NULL)
                {
                    files.push_back(real_path);
                    free(real_path);
                }
            }
    }
    else
        std::cerr << "Not a valid directory: " << lib_path << std::endl;
    return files;
}


int main(int argc, char* argv[])
{
    void *handle = 0;
    void *handles[100];
    char *error;

    std::map<void *, std::string> handle2name;

    std::map<std::string, upm_ft_pressure> fts_pressure;
    std::map<std::string, upm_ft_servo> fts_servo;
    std::map<std::string, upm_ft_temperature> fts_temperature;
    std::map<std::string, upm_ft_ph> fts_ph;

    // Did the user provide a library directory?
    std::string path_lib_search = SENSOR_LIB_DIR;
    if (argc == 2)
        path_lib_search = argv[1];
    else if (argc == 1) {}
    else
    {
        std::cerr << "Usage: " << argv[0] << " (upm_lib_path)" << std::endl;
        return -1;
    }

    // Retrieve a list of library files ()
    std::cout << "Searching for sensor drivers: " << path_lib_search
        << std::endl;
    std::vector<std::string> libs = get_files_endswith(path_lib_search);

    std::cout << "Found " << libs.size() << " libraries" << std::endl;

    // Loop over each so in a directory
    for (std::vector<std::string>::const_iterator it = libs.begin();
            it != libs.end(); ++it)
    {
        std::cout << "." << std::flush;

        dlerror();
        handle = dlopen(it->c_str(), RTLD_LAZY);
        // Skip if unable to open library
        if ((error = dlerror()) != NULL)
        {
//            std::cerr << "Failed to open: " << *it << std::endl
//                << "Reason: " << error << std::endl;
            continue;
        }

        func_get_upm_descriptor get_descriptor =
            (func_get_upm_descriptor)dlsym(handle, "get_upm_descriptor");

        // Skip if library does NOT contain "get_upm_descriptor"
        if ((error = dlerror()) != NULL)
        {
            dlclose(handle);
            continue;
        }

        // Sensor descriptor struct
        upm_sensor_descriptor sensor_desc = {0};
        get_descriptor(&sensor_desc);

        for (int i = 0; (i < upm_sensor_category_size)
                && (sensor_desc.category[i] != UPM_INVALID); i++)
            switch(sensor_desc.category[i])
            {
                case UPM_PRESSURE:
                    {
                        // Retrieve generic pressure function table
                        func_get_upm_ft_pressure get_ft =
                            (func_get_upm_ft_pressure)dlsym(handle, "upm_get_pressure_ft");
                        if ((error = dlerror()) == NULL)
                            fts_pressure[sensor_desc.name] = get_ft();
                        break;
                    }
                case UPM_SERVO:
                    {
                        // Retrieve generic servo function table
                        func_get_upm_ft_servo get_ft = (func_get_upm_ft_servo)dlsym(handle, "upm_get_servo_ft");
                        if ((error = dlerror()) == NULL)
                            fts_servo[sensor_desc.name] = get_ft();
                        break;
                    }
                case UPM_TEMPERATURE:
                    {
                        // Retrieve generic temperature function table
                        func_get_upm_ft_temperature get_ft =
                            (func_get_upm_ft_temperature)dlsym(handle, "upm_get_temperature_ft");
                        if ((error = dlerror()) == NULL)
                            fts_temperature[sensor_desc.name] = get_ft();
                        break;
                    }
                case UPM_PH:
                    {
                        // Retrieve generic ph function table
                        func_get_upm_ft_ph get_ft =
                            (func_get_upm_ft_ph)dlsym(handle, "upm_get_ph_ft");
                        if ((error = dlerror()) == NULL)
                            fts_ph[sensor_desc.name] = get_ft();
                        break;
                    }
                default:
                    break;
            }

        std::cout << std::endl
            << "Found upm sensor lib: " << *it << std::endl << sensor_desc;

        handle2name[handle] = sensor_desc.name;
    }

    std::cout << std::endl << "Found "
        << handle2name.size() << " sensor "
        << (handle2name.size() == 1 ? "library" : "libraries")
        << std::endl;

    // For each sensor which provides pressure functionality
    if (!fts_pressure.empty())
    {
        std::cout << "[Pressure Sensors]" << std::endl;
        for(std::map<std::string, upm_ft_pressure>::const_iterator cit = fts_pressure.begin();
                cit != fts_pressure.end(); ++cit)
        {
            cit->second.upm_pressure_init(0, 1, 2, 3);
        }
    }

    // For each sensor which provides servo functionality
    if (!fts_servo.empty())
    {
        std::cout << "[Servos]" << std::endl;
        for(std::map<std::string, upm_ft_servo>::const_iterator cit = fts_servo.begin();
                cit != fts_servo.end(); ++cit)
        {
            cit->second.upm_servo_init(0, 1, 2, 3);
        }
    }

    // For each sensor which provides temperature functionality
    if (!fts_temperature.empty())
    {
        std::cout << "[Temperature Sensors]" << std::endl;
        for(std::map<std::string, upm_ft_temperature>::const_iterator cit = fts_temperature.begin();
                cit != fts_temperature.end(); ++cit)
        {
            cit->second.upm_temperature_init(0, 1, 2, 3);
        }
    }
    // For each sensor which provides temperature functionality
    if (!fts_ph.empty())
    {
        std::cout << "[pH Sensors]" << std::endl;
        for(std::map<std::string, upm_ft_ph>::const_iterator cit = fts_ph.begin();
                cit != fts_ph.end(); ++cit)
        {
            std::cout << "pH sensor: " << cit->first << std::endl;

            void *dev_ph = cit->second.upm_ph_init(0, 5.0);
            if (dev_ph == NULL) 
            {
                std::cerr << "Failed to initialize pH sensor, skipping "
                    << cit->first << std::endl;
                continue;
            }
            float ph = 0.0;
            std::cout <<"XXX after init" << std::endl;
            cit->second.upm_ph_get_value(dev_ph, &ph, UPM_PH_RAW);
            std::cout << cit->first << " Raw: " << ph << std::endl;
            cit->second.upm_ph_get_value(dev_ph, &ph, UPM_PH_NORMALIZED);
            std::cout << cit->first << " Normalized: " << ph << std::endl;
            cit->second.upm_ph_get_value(dev_ph, &ph, UPM_PH_PH);
            std::cout << cit->first << " PH: " << ph << std::endl;
        }
    }

    // Call dlclose for all open libraries
    if (!handle2name.empty())
    {
        std::cout << "Closing sensor libraries..." << std::endl;
        for (std::map<void *, std::string>::const_iterator cit = handle2name.begin();
                cit != handle2name.end(); ++cit)
        {
            std::cout << "Closing " << cit->second << std::endl;
            dlclose(handle);
        }
        std::cout << std::endl << "Close complete" << std::endl;
    }

    return 0;
}
