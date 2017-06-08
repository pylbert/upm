#include "Humidity.hpp"

using namespace upm;

std::map <std::string, float> Humidity::HumidityAll ()
{return HumidityForSources(Sources());}

float Humidity::HumidityForSource (std::string source)
{
    std::map<std::string, float> vals = HumidityForSources(std::vector<std::string>(1, source));

    if (vals.empty())
    {
        std::stringstream ss;
        ss << __FUNCTION__ << " sensor does not provide source: '"
            << source << ".  Valid sources are: {";
        std::copy(Sources().begin(), Sources().end() - 1,
                std::ostream_iterator<std::string>(ss, ", "));
        ss << Sources().back() << "}";
        throw std::invalid_argument(ss.str());
    }

    return vals[source];
}
Humidity::Humidity ()
{
    AddValueSerializer(this, &_JsonHumidity);
}
std::string Humidity::JsonHumidity () const
{
    return "{" + _JsonHumidity((Humidity*)this) + "}";
}
std::string Humidity::_JsonHumidity (Gadget * inst)
{
    std::stringstream ss;

    /* Downcast to reference (throws if cast fails) */
    Humidity& ref = dynamic_cast<Humidity&>(*inst);

    std::map<std::string, float> data = ref.HumidityAll();

    for (std::map<std::string, float>::const_iterator it = data.begin();
            it != data.end();)
    {
        ss << "\"" << it->first << "\" : {\"value\" : " << it->second
            << ", \"units\" : \"" << ref.Unit(it->first) << "\"}";
        if (++it != data.end()) ss << "," << std::endl;
    }

    return ss.str();
}
