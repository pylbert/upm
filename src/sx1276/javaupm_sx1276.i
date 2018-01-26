/* Java-specific SWIG code */
%module javaupm_sx1276

%include "arrays_java.i";
%include "typemaps.i"
%include "../java_buffer.i"

%ignore getRxBuffer();
%ignore send(uint8_t *buffer, uint8_t size, int txTimeout);

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_sx1276)
