%include "../common_top.i"
%include "Mraa.i"
%include "Light.i"
%include "Moisture.i"
%include "Temperature.i"

/* BEGIN Java syntax  ------------------------------------------------------- */
#ifdef SWIGJAVA
JAVA_JNI_LOADLIBRARY(javaupm_ims)
#endif
/* END Java syntax */

/* BEGIN Common SWIG syntax ------------------------------------------------- */
%{
#include "ims_defs.h"
#include "ims.hpp"
%}
%include "ims_defs.h"
%include "ims.hpp"
/* END Common SWIG syntax */
