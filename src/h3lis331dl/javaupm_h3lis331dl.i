/* Java-specific SWIG code */
%module javaupm_h3lis331dl

%include "typemaps.i"
%include "std_vector.i"

%apply float *OUTPUT { float *aX, float *aY, float *aZ  };
%apply int *OUTPUT { int *x, int *y, int*z };

%ignore i2cContext;

%template(IntVector) std::vector<int>;
%template(FloatVector) std::vector<float>;

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_h3lis331dl)
