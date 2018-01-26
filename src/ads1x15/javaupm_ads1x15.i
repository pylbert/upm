/* Java-specific SWIG code */
%module javaupm_ads1x15

%include "typemaps.i"
%import "../interfaces/javaupm_iADC.i"
%typemap(javaimports) SWIGTYPE %{import upm_interfaces.*;%}

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ads1x15)
