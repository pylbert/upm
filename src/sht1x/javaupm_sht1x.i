/* Java-specific SWIG code */
%module javaupm_sht1x

%include "stdint.i"
%include "typemaps.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_sht1x)
