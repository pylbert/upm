/* Java-specific SWIG code */
%module javaupm_bacnetmstp

%include "../carrays_uint32_t.i"
%include "typemaps.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_bacnetmstp)
