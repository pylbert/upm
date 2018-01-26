/* Java-specific SWIG code */
%module javaupm_ili9341

%include "stdint.i"
%include "typemaps.i"

%apply uint8_t *INPUT { uint8_t *addr }

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ili9341)
