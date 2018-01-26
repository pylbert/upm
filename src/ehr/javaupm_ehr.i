/* Java-specific SWIG code */
%module javaupm_ehr

%ignore beatISR;

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ehr)
