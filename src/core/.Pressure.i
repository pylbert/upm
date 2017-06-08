%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::Pressure);
#endif
#endif

%{
#include "Pressure.hpp"
%}
%include "Pressure.hpp"
