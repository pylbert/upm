%module jsupm_apa102

%inline %{
    #include <node_buffer.h>
%}

%typemap(in) (uint8_t *colors) {
  if (!node::Buffer::HasInstance($input)) {
      SWIG_exception_fail(SWIG_ERROR, "Expected a node Buffer");
  }
  $1 = (uint8_t*) node::Buffer::Data($input);
}

%include "common.i"
