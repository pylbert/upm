/* Java-specific SWIG code */
%module javaupm_lp8860

%typemap(javaimports) SWIGTYPE %{import upm_interfaces.*;%}
%import "../interfaces/javaupm_iLightController.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_lp8860)
