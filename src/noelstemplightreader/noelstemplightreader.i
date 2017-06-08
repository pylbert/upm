%include "../common_top.i"
%include "Mraa.i"
%include "Light.i"
%include "Temperature.i"

/* BEGIN Java syntax  ------------------------------------------------------- */
#ifdef SWIGJAVA
JAVA_JNI_LOADLIBRARY(javaupm_noelstemplightreader)
#endif
/* END Java syntax */

/* BEGIN Common SWIG syntax ------------------------------------------------- */
%{
#include "noelstemplightreader.hpp"
%}
%include "noelstemplightreader.hpp"
/* END Common SWIG syntax */
