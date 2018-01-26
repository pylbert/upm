/* Java-specific SWIG code */
%module javaupm_ms5803

%include "arrays_java.i"
%include "typemaps.i"
%include "../java_buffer.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ms5803)
