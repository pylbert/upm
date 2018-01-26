/* Java-specific SWIG code */
%module javaupm_rhusb

%include "arrays_java.i";
%include "typemaps.i"
%include "../java_buffer.i"
%include "cpointer.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_rhusb)
