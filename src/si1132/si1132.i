%include "../common_top.i"
%include "Light.i"

/* BEGIN Java syntax  ------------------------------------------------------- */
#ifdef SWIGJAVA
#ifndef ANDROID
    %module(directors="1") javaupm_si1132
#endif

JAVA_JNI_LOADLIBRARY(javaupm_si1132)
#endif
/* END Java syntax */

/* BEGIN Common SWIG syntax ------------------------------------------------- */
%{
#include "si1132.hpp"
%}
%include "si1132.hpp"
/* END Common SWIG syntax */
