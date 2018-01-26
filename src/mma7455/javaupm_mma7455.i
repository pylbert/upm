/* Java-specific SWIG code */
%module javaupm_mma7455

%include "arrays_java.i";
%include "typemaps.i"
%include "../java_buffer.i"
%include "std_vector.i"
%apply short *OUTPUT { short * ptrX, short * ptrY, short * ptrZ };
%template(ShortVector) std::vector<short>;

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_mma7455)
