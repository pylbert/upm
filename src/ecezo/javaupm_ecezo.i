/* Java-specific SWIG code */
%module javaupm_ecezo

%include "stdint.i"
%include "typemaps.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ecezo)
