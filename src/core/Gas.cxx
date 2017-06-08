#include "Gas.hpp"

using namespace upm;

std::map <std::string, float> Gas::GasAll ()
{return GasForSources(Sources());}

float Gas::GasForSource(std::string source)
{
    std::map<std::string, float> vals = GasForSources(std::vector<std::string>(1, source));

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

Gas::Gas ()
{
    AddValueSerializer(this, &_JsonGas);
}

std::string Gas::JsonGas () const
{
    return "{" + _JsonGas((Gas*)this) + "}";
}

std::string Gas::_JsonGas (Gadget * inst)
{
    std::stringstream ss;

    /* Downcast to reference (throws if cast fails) */
    Gas& ref = dynamic_cast<Gas&>(*inst);

    std::map<std::string, float> data = ref.GasAll();

    for (std::map<std::string, float>::const_iterator it = data.begin();
            it != data.end();)
    {
        ss << "\"" << it->first << "\" : {\"value\" : " << it->second
            << ", \"units\" : \"" << ref.Unit(it->first) << "\"}";
        if (++it != data.end()) ss << "," << std::endl;
    }

    return ss.str();
}
