/* Java-specific SWIG code */
%module javaupm_grovescam

%include "../java_buffer.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_grovescam)
