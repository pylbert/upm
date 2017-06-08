%include ".Gadget.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface(upm::Sensor);
#endif
%ignore upm::Gadget::JsonDefinition;
#endif

%{
#include "Sensor.hpp"
%}
%include "Sensor.hpp"
