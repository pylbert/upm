%module pyupm_curieimu
%include "common.i"
%include "../carrays_int16_t.i"
%include "stdint.i"

%typemap(out) int16_t* {
  $result = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_int16Array, 0 |  0 );
}
