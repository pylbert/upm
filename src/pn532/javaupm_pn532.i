/* Java-specific SWIG code */
%module javaupm_pn532

%include "arrays_java.i"
%include "typemaps.i"
%ignore i2cContext;
%apply signed char[] {uint8_t *};
%apply unsigned char *OUTPUT {uint8_t *uidLength};
%apply unsigned char *INOUT {uint8_t *responseLength};

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_pn532)
