/* Python-specific SWIG code */
%module pyupm_ms5803

%include "stdint.i"
%include "cpointer.i"
%pointer_functions(float, floatp);

/* Include the common swig file for this library */
%include "common.i"
