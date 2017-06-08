#include "Moisture.hpp"

using namespace upm;

std::map <std::string, float> Moisture::MoistureAll ()
{return MoistureForSources(Sources());}

std::map <std::string, float> Moisture::MoistureForSource (std::string source)
{ return MoistureForSources(std::vector<std::string>(1, source)); }

Moisture::Moisture ()
{
    AddValueSerializer(this, &_JsonMoisture);
}

std::string Moisture::JsonMoisture () const
{
    return "{" + _JsonMoisture((Moisture*)this) + "}";
}

std::string Moisture::_JsonMoisture (Gadget * inst)
{
    std::stringstream ss;

    /* Downcast to reference (throws if cast fails) */
    Moisture& ref = dynamic_cast<Moisture&>(*inst);

    std::map<std::string, float> data = ref.MoistureAll();

    for (std::map<std::string, float>::const_iterator it = data.begin();
            it != data.end();)
    {
        ss << "\"" << it->first << "\" : {\"value\" : " << it->second
            << ", \"units\" : \"" << ref.Unit(it->first) << "\"}";
        if (++it != data.end()) ss << "," << std::endl;
    }

    return ss.str();
}
