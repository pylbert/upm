/* Java-specific SWIG code */
%module javaupm_mma7660

%include "arrays_java.i";
%include "typemaps.i"
%include "../java_buffer.i"
%include "std_vector.i"

%apply float *OUTPUT { float *ax, float *ay, float *az  };
%apply int *OUTPUT { int *x, int *y, int *z };
%ignore installISR(int , void *, void *);

%template(IntVector) std::vector<int>;
%template(FloatVector) std::vector<float>;

/* Include the common swig file for this library */
%include "common.i"

JAVA_ADD_INSTALLISR_PIN(upm::MMA7660)
JAVA_JNI_LOADLIBRARY(javaupm_mma7660)
