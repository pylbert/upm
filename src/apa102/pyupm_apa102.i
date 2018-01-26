%module pyupm_apa102

// setLeds
%typemap(in) (uint8_t *colors) {
  if (PyByteArray_Check($input)) {
    $1 = (uint8_t*) PyByteArray_AsString($input);
  } else {
    PyErr_SetString(PyExc_ValueError, "bytearray expected");
    return NULL;
  }
}

%include "common.i"
