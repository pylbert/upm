%include ".Gadget.i"

#if (SWIGJAVA)
#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface(upm::Actuator);
#endif
%ignore upm::Gadget::JsonDefinition;
#endif

%{
#include "Actuator.hpp"
%}
%include "Actuator.hpp"
