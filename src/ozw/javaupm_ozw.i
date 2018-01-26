/* Java-specific SWIG code */
%module javaupm_ozw

%include "arrays_java.i";
%include "typemaps.i"
%include "../java_buffer.i"
%apply unsigned char *OUTPUT { uint8_t *val };

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ozw)
