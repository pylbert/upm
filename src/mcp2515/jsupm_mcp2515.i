/* Javascript-specific SWIG code */
%module jsupm_mcp2515

%include "../carrays_uint8_t.i"
%include "cpointer.i"

%pointer_functions(float, floatp);

/* Include the common swig file for this library */
%include "common.i"
