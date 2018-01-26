/* Java-specific SWIG code */
%module javaupm_rpr220

/* Include the common swig file for this library */
%include "common.i"

JAVA_ADD_INSTALLISR(upm::RPR220)
JAVA_JNI_LOADLIBRARY(javaupm_rpr220)
