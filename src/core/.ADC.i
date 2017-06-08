%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::ADC);
#endif
#endif

%{
#include "ADC.hpp"
%}
%include "ADC.hpp"
