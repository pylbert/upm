/* Java-specific SWIG code */
%module javaupm_bmpx8x

%import "../interfaces/javaupm_iPressureSensor.i"
%typemap(javaimports) SWIGTYPE %{import upm_interfaces.*;%}
%import "../interfaces/javaupm_iTemperatureSensor.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_bmpx8x)
