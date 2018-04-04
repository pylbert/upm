%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::Temperature);
#endif
#endif

%{
#include "Temperature.hpp"
%}
%include "Temperature.hpp"

/* Add proxy types for handling TemperatureType */
typedef upm::SensorSource<float, enum upm::TemperatureType> TemperatureSource;
%template(TemperatureSource) upm::SensorSource<float, enum upm::TemperatureType>;
typedef std::map<std::string, upm::SensorSource<float, enum upm::TemperatureType>> TemperatureSourceMap;
%template(TemperatureSourceMap) std::map<std::string, upm::SensorSource<float, enum upm::TemperatureType>>;

/* FOR JAVASCRIPT ONLY!
If there's a better way to allow multiple inheritance w/javascript, the
following macro definitions can go away.
    usage: INHERIT_TEMPERATURE(upm::MySensorClass)
*/
%define INHERIT_TEMPERATURE(YourClassName)
%extend YourClassName {
/*using upm::Sensor::JsonDefinition;*/
/*using upm::Sensor::JsonValues;*/
using upm::Temperature::JsonTemperature;
using upm::Temperature::TemperatureAll;
using upm::Temperature::TemperatureForSources;
}
%enddef
