/* Python-specific SWIG code */
%module pyupm_h3lis331dl

/* Send "int *" and "float *" to python as intp and floatp */
%pointer_functions(int, intp);
%pointer_functions(float, floatp);

/* Include the common swig file for this library */
%include "common.i"
