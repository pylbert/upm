/* Java-specific SWIG code */
%module javaupm_mcp2515

%include "arrays_java.i"
%include "typemaps.i"
%include "../java_buffer.i"

%ignore installISR(int pin, void *, void *);

/* Include the common swig file for this library */
%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_mcp2515)
JAVA_ADD_INSTALLISR_PIN(upm::MCP2515)
