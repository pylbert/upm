#include "Pressure.hpp"

using namespace upm;

std::map <std::string, float> Pressure::PressureAll ()
{return PressureForSources(Sources());}

float Pressure::PressureForSource (std::string source)
{
    std::map<std::string, float> vals = PressureForSources(std::vector<std::string>(1, source));

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

Pressure::Pressure ()
{
    AddValueSerializer(this, &_JsonPressure);
}

std::string Pressure::JsonPressure () const
{
    return "{" + _JsonPressure((Pressure*)this) + "}";
}

std::string Pressure::_JsonPressure (Gadget * inst)
{
    std::stringstream ss;

    /* Downcast to reference (throws if cast fails) */
    Pressure& ref = dynamic_cast<Pressure&>(*inst);

    std::map<std::string, float> data = ref.PressureAll();

    for (std::map<std::string, float>::const_iterator it = data.begin();
            it != data.end();)
    {
        ss << "\"" << it->first << "\" : {\"value\" : " << it->second
            << ", \"units\" : \"" << ref.Unit(it->first) << "\"}";
        if (++it != data.end()) ss << "," << std::endl;
    }

    return ss.str();
}
