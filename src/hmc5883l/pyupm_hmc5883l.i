%module pyupm_hmc5883l

%include "../carrays_int16_t.i"

%typemap(out) int16_t* {
  $result = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_int16Array, 0 |  0 );
}

%include "common.i"
