#include "Temperature.hpp"
#include "external/json/json.hpp"

#include <locale>

using namespace upm;


std::map<std::string, TemperatureType> _str2temptype = {{"C", TemperatureType::Celsius},
                                                        {"c", TemperatureType::Celsius},
                                                       {"celsius", TemperatureType::Celsius},
                                                       {"CELSIUS", TemperatureType::Celsius},
                                                        {"F", TemperatureType::Fahrenheit},
                                                        {"f", TemperatureType::Fahrenheit},
                                                        {"Fahrenheit", TemperatureType::Fahrenheit},
                                                        {"fahrenheit", TemperatureType::Fahrenheit},
                                                        {"K", TemperatureType::Kelvin},
                                                        {"k", TemperatureType::Kelvin},
                                                        {"Kelvin", TemperatureType::Kelvin},
                                                        {"kelvin", TemperatureType::Kelvin}};

std::string TemperatureTypeToString(TemperatureType type_enum)
{
    for (std::map<std::string, TemperatureType>::const_iterator it = _str2temptype.begin();
         it != _str2temptype.end(); ++it)
        if (it->second == type_enum) return it->first;

    return "unknown";
}

TemperatureType StringToTemperatureType(std::string type_string)
{
    /* Enforce TemperatureType units */
    if (_str2temptype.find(type_string) != _str2temptype.end())
        return _str2temptype[type_string];
    else
    {
        std::stringstream ss;
        ss << "'" << type_string << "' is not a valid Temperature unit.  Valid units are: {";
        for (std::map<std::string, TemperatureType>::const_iterator it = _str2temptype.begin();
             it != _str2temptype.end(); )
        {
            ss << it->first;
            if (++it != _str2temptype.end()) ss << ", ";
        }
        ss << "}";
        throw std::invalid_argument(ss.str());
    }
}

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

float Temperature::TemperatureAs(std::string source, TemperatureType unit)
{
    return Convert(TemperatureForSource(source), StringToTemperatureType(Unit(source)), unit);
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

std::map<std::string, SensorSource<float, TemperatureType>>& Temperature::TemperatureSources()
{
    /* Check if there are Sensor-level sources... */
    Sources();

    return _temp_sources;
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

    /* Get a reference to the sources */
    nlohmann::json jsrs = ref.LibraryJson()["Sensor Class"][classname_derived]["Sources"];

    for (nlohmann::json::iterator it = jsrs.begin(); it != jsrs.end(); ++it)
    {
      if ((*it).at("type") == "temperature")
      {
          /* Test the deserialization of the source, use the original unit string */
          SensorSource<float, TemperatureType> this_src = *it;
          ref._temp_sources[it.key()] = *it;
          ref.AddSource(it.key(), (*it).at("unit"));
      }
    }

    /* Return a string */
    return jsrs.dump();
}

void upm::to_json(nlohmann::json& j, const SensorSource<float, TemperatureType>& p)
{
    j = nlohmann::json{{"unit", TemperatureTypeToString(p.unit)}, {"type", p.type}, {"min", p.min}, {"max", p.max}, {"accuracy", p.accuracy}};
}

void upm::from_json(const nlohmann::json& j, SensorSource<float, TemperatureType>& p)
{
    p.type = j.at("type").get<std::string>();
    p.unit = StringToTemperatureType(j.at("unit").get<std::string>());
    p.min = j.at("min").get<float>();
    p.max = j.at("max").get<float>();
    p.accuracy = j.at("accuracy").get<float>();
}

float Temperature::Convert(float value, TemperatureType from, TemperatureType to)
{
    /* If the caller is requesting the native type, return it */
    if (from == to) return value;

    /* Convert F->C */
    if ((from == TemperatureType::Fahrenheit) && (to == TemperatureType::Celsius))
        value = (value - 32) * 5/9.0;
    /* Convert F->K */
    else if ((from == TemperatureType::Fahrenheit) && (to == TemperatureType::Kelvin))
        value = (value + 459.67) * 5/9.0;
    /* Convert K->F */
    else if ((from == TemperatureType::Kelvin) && (to == TemperatureType::Fahrenheit) )
        value = value * 9/5.0 - 459.67;
    /* Convert K->C */
    else if ((from == TemperatureType::Kelvin) && (to == TemperatureType::Celsius) )
        value = value - 273.15;
    /* Convert C->F */
    else if ((from == TemperatureType::Celsius) && (to == TemperatureType::Fahrenheit) )
        value = value * 9/5.0 + 32;
    /* Convert C->K */
    else if ((from == TemperatureType::Celsius) && (to == TemperatureType::Kelvin) )
        value = value + 273.15;

    return value;
}
