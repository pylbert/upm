%include ".Actuator.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::ServoController);
#endif
#endif

%{
#include "ServoController.hpp"
%}
%include "ServoController.hpp"
