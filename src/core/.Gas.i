%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::Gas);
#endif
#endif

%{
#include "Gas.hpp"
%}
%include "Gas.hpp"
