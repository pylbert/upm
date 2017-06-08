%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::Moisture);
#endif
#endif

%{
#include "Moisture.hpp"
%}
%include "Moisture.hpp"
