/* Java-specific SWIG code */
%module javaupm_ms5611

%import "../interfaces/javaupm_iTemperatureSensor.i"
%import "../interfaces/javaupm_iPressureSensor.i"
%typemap(javaimports) SWIGTYPE %{import upm_interfaces.*;%}

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ms5611)
