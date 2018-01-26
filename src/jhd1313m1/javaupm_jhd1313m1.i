/* Java-specific SWIG code */
%module javaupm_jhd1313m1

%include "stdint.i"
%include "typemaps.i"
%include "std_vector.i"
%template(byteVector) std::vector<uint8_t>;

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_jhd1313m1)
