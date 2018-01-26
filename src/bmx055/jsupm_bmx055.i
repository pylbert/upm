%module jsupm_bmx055

%include "../upm_vectortypes.i"

/* Send "int *" and "float *" to JavaScript as intp and floatp */
%pointer_functions(int, intp);
%pointer_functions(float, floatp);

%include "common.i"
