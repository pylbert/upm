#include "Temperature.hpp"
#include "external/json/json.hpp"

using namespace upm;

typedef struct
{
    std::string unit;
    float min;
    float max;
    float accuracy;
} SensorSource ;

std::map <std::string, float> Temperature::TemperatureAll ()
{return TemperatureForSources(Sources());}

float Temperature::TemperatureForSource (std::string source)
{
    std::map<std::string, float> vals = TemperatureForSources(std::vector<std::string>(1, source));

    if (vals.empty())
    {
        std::stringstream ss;
        ss << __FUNCTION__ << " sensor does not provide source: '"
            << source << "'.  Valid sources are: {";
        std::copy(Sources().begin(), Sources().end() - 1,
                std::ostream_iterator<std::string>(ss, ", "));
        ss << Sources().back() << "}";
        throw std::invalid_argument(ss.str());
    }

    return vals[source];
}

Temperature::Temperature ()
{
    AddValueSerializer(this, &_JsonTemperature);
    AddJsonDeserializer(this, &_DeserializeTemperatureSources);
}

std::string Temperature::JsonTemperature () const
{
    return "{" + _JsonTemperature((Temperature*)this) + "}";
}

std::string Temperature::_JsonTemperature (Gadget * inst)
{
    std::stringstream ss;

    /* Downcast to reference (throws if cast fails) */
    Temperature& ref = dynamic_cast<Temperature&>(*inst);

    std::map<std::string, float> data = ref.TemperatureAll();

    for (std::map<std::string, float>::const_iterator it = data.begin();
            it != data.end();)
    {
        ss << "\"" << it->first << "\" : {\"value\" : " << it->second
            << ", \"units\" : \"" << ref.Unit(it->first) << "\"}";
        if (++it != data.end()) ss << "," << std::endl;
    }

    return ss.str();
}

std::string Temperature::_DeserializeTemperatureSources (Gadget * inst)
{
    /* Downcast to reference (throws if cast fails) */
    Temperature& ref = dynamic_cast<Temperature&>(*inst);

    /* Make sure the derived class name (from std::type_info) matches a JSON sensor class name */
    std::string classname_derived = ref.DerivedClassName();

    /* Get a reference to the object */
    nlohmann::json jsrs = ref.LibraryJson()["Sensor Class"][classname_derived]["Sources"];

    /* Deserialize to a temperature source map */
    std::map<std::string, upm::SensorSource<float>> sources = jsrs;

    /* Assign to this instance */
    ref._temp_sources = sources;

    /* Add all sources to Sensor's source vector */
    for (std::map<std::string, upm::SensorSource<float>>::const_iterator it = ref._temp_sources.begin();
         it != ref._temp_sources.end(); ++it)
        ref.AddSource(it->first, it->second.unit);

    /* Return a string */
    return jsrs.dump();
}
