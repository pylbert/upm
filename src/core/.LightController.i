%include ".Sensor.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::LightController);
#endif
#endif

%{
#include "LightController.hpp"
%}
%include "LightController.hpp"
