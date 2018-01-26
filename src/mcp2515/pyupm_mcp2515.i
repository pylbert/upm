/* Python-specific SWIG code */
%module pyupm_mcp2515

%include "stdint.i"
%include "../carrays_uint8_t.i"
%include "cpointer.i"
%pointer_functions(float, floatp);

/* Include the common swig file for this library */
%include "common.i"
