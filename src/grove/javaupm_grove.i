/* Java-specific SWIG code */
%module javaupm_grove

%apply int {mraa::Edge}

/* Include the common swig file for this library */
%include "common.i"

JAVA_ADD_INSTALLISR_EDGE(upm::GroveButton)
JAVA_JNI_LOADLIBRARY(javaupm_grove)
