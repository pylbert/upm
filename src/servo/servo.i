%include "Mraa.i"
%include "ServoController.i"

/* BEGIN Java syntax  ------------------------------------------------------- */
#ifdef SWIGJAVA
JAVA_JNI_LOADLIBRARY(javaupm_servo)
#endif
/* END Java syntax */

/* BEGIN Common SWIG syntax ------------------------------------------------- */
%{
#include "servo.hpp"
#include "es08a.hpp"
#include "es9257.hpp"
%}
%include "servo.hpp"
%include "es9257.hpp"
%include "es08a.hpp"
/* END Common SWIG syntax */
