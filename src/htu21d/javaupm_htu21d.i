/* Java-specific SWIG code */
%module javaupm_htu21d

%include "typemaps.i"
%ignore getHumidityData(float*, float*, float*);

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_htu21d)
