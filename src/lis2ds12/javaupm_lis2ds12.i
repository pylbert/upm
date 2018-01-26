%module javaupm_lis2ds12

%include "typemaps.i"

%ignore getAccelerometer(float *, float *, float *);
#%ignore installISR(LIS2DS12_INTERRUPT_PINS_T , int ,  mraa::Edge, void *, void *);

%include "common.i"

%define INTERRUPT LIS2DS12_INTERRUPT_PINS_T
%enddef
JAVA_ADD_INSTALLISR_INTERRUPT(upm::LIS2DS12)

JAVA_JNI_LOADLIBRARY(javaupm_lis2ds12)
