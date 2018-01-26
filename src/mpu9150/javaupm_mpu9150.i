%module javaupm_mpu9150

%include "typemaps.i"
%include "std_vector.i"
%include "arrays_java.i"
%include "../java_buffer.i"

%template(FloatVector) std::vector<float>;

%apply int {mraa::Edge};

%define GETTER get_gpioIRQ()
%enddef

%include "common.i"

JAVA_ADD_INSTALLISR_GPIO(upm::MPU60X0)

JAVA_JNI_LOADLIBRARY(javaupm_mpu9150)
