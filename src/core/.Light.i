%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::Light);
#endif
#endif

%{
#include "Light.hpp"
%}
%include "Light.hpp"
