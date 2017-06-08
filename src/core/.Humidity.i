%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::Humidity);
#endif
#endif

%{
#include "Humidity.hpp"
%}
%include "Humidity.hpp"


/* FOR JAVASCRIPT ONLY!
If there's a better way to allow multiple inheritance w/javascript, the
following macro definitions can go away.
    usage: INHERIT_HUMIDITY(upm::MySensorClass)
*/
%define INHERIT_HUMIDITY(YourClassName)
%extend YourClassName {
/*using upm::Sensor::JsonDefinition;*/
/*using upm::Sensor::JsonValues;*/
using upm::Humidity::JsonHumidity;
using upm::Humidity::HumidityAll;
using upm::Humidity::HumidityForSources;
}
%enddef
