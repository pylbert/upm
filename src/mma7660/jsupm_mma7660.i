/* Javascript-specific SWIG code */
%module jsupm_mma7660

/* Send "int *" and "float *" to JavaScript as intp and floatp */
%pointer_functions(int, intp);
%pointer_functions(float, floatp);

/* Include the common swig file for this library */
%include "common.i"
