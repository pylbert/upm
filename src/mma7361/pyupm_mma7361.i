%module pyupm_mma7361

/* Send "int *" and "float *" to python as intp and floatp */
%pointer_functions(int, intp);
%pointer_functions(float, floatp);

%include "common.i"
