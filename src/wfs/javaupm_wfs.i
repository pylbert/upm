/* Java-specific SWIG code */
%module javaupm_wfs

%ignore flowISR;

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_wfs)
