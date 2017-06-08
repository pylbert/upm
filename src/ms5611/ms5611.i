%include "../common_top.i"
%include "Pressure.i"
%include "Temperature.i"

/* BEGIN Java syntax  ------------------------------------------------------- */
#ifdef SWIGJAVA
JAVA_JNI_LOADLIBRARY(javaupm_ms5611)
#endif
/* END Java syntax */

/* BEGIN Common SWIG syntax ------------------------------------------------- */
%{
#include "ms5611.hpp"
%}
%include "ms5611.hpp"
/* END Common SWIG syntax */
