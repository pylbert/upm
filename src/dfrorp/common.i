/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%include "cpointer.i"
%{
#include "dfrorp.hpp"
%}
%include "dfrorp.hpp"
