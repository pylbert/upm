/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%include "carrays.i"
%{
#include "nlgpio16.hpp"
%}
%include "nlgpio16.hpp"
%array_class(char, charArray);
