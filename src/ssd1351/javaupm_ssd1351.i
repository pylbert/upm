/* Java-specific SWIG code */
%module javaupm_ssd1351

%include "stdint.i"
%include "typemaps.i"
%ignore font;
%ignore m_map;

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_ssd1351)
