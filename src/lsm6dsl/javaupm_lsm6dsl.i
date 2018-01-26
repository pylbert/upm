%module javaupm_lsm6dsl
%include "typemaps.i"
%include "../upm_vectortypes.i"

%ignore getAccelerometer(float *, float *, float *);
%ignore getGyroscope(float *, float *, float *);

%ignore installISR(LSM6DSL_INTERRUPT_PINS_T , int ,  mraa::Edge ,  void *, void *);

%include "common.i"

%define INTERRUPT LSM6DSL_INTERRUPT_PINS_T
%enddef

JAVA_ADD_INSTALLISR_INTERRUPT(upm::LSM6DSL)
JAVA_JNI_LOADLIBRARY(javaupm_lsm6dsl)
