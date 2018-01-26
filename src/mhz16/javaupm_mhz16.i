%module javaupm_mhz16

%include "typemaps.i"
%include "arrays_java.i";
%include "../java_buffer.i"

%apply int *OUTPUT { int *gas, int *temp };

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_mhz16)
