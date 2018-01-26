%module pyupm_bma250e

%include "cpointer.i"
%include "../upm_vectortypes.i"

/* Send "int *" and "float *" to python as intp and floatp */
%pointer_functions(int, intp);
%pointer_functions(float, floatp);

%include "common.i"
