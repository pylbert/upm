/* Java-specific SWIG code */
%module javaupm_led

%apply int {mraa::Edge}

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_led)
