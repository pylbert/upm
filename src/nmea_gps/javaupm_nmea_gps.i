/* Java-specific SWIG code */
%module javaupm_nmea_gps

%include "stdint.i"
%include "typemaps.i"

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_nmea_gps)
