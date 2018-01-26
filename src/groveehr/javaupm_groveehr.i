/* Java-specific SWIG code */
%module javaupm_groveehr

%ignore beatISR;

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_groveehr)
