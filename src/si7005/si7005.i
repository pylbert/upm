%include "../common_top.i"
%include "Mraa.i"
%include "Humidity.i"
%include "Temperature.i"

/* BEGIN Java syntax  ------------------------------------------------------- */
#ifdef SWIGJAVA
%include "arrays_java.i";
%include "../java_buffer.i"
JAVA_JNI_LOADLIBRARY(javaupm_si7005)
#endif
/* END Java syntax */

/* BEGIN Common SWIG syntax ------------------------------------------------- */
%{
#include "si7005.hpp"
%}
%include "si7005.hpp"
/* END Common SWIG syntax */
