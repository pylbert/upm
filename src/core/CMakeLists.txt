# Create a source file for constants
configure_file (Gadget_generated.cxx.in Gadget_generated.cxx @ONLY)

upm_mixed_module_init (NAME core
    DESCRIPTION "CXX Interface Library"
    CPP_HDR ADC.hpp
            Gas.hpp
            Humidity.hpp
            LightController.hpp
            Light.hpp
            Moisture.hpp
            Mraa.hpp
            Pressure.hpp
            Sensor.hpp
            Actuator.hpp
            ServoController.hpp
            Temperature.hpp
            Gadget.hpp
    CPP_SRC "${CMAKE_CURRENT_BINARY_DIR}/Gadget_generated.cxx"
            ADC.cxx
            Gas.cxx
            Humidity.cxx
            LightController.cxx
            Light.cxx
            Moisture.cxx
            Mraa.cxx
            Pressure.cxx
            Sensor.cxx
            Actuator.cxx
            ServoController.cxx
            Temperature.cxx
            Gadget.cxx
    REQUIRES mraa utilities-c)

# Add a PUBLIC include directory to the CMAKE src dir
target_include_directories (core
    PUBLIC ${CMAKE_SOURCE_DIR}/src
           ${CMAKE_BINARY_DIR}/src)
