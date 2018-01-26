/* Java-specific SWIG code */
%module javaupm_ds1808lc

%include "arrays_java.i";
%include "typemaps.i"
%include "../java_buffer.i"
%include "cpointer.i"
%typemap(javaimports) SWIGTYPE %{import upm_interfaces.*;%}
%import "../interfaces/javaupm_iLightController.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ds1808lc)
