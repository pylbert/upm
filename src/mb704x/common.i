/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "mb704x.hpp"
%}
%include "mb704x.hpp"
