/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%include "carrays.i"
%{
#include "grovegprs.hpp"
%}
%include "grovegprs.hpp"
%array_class(char, charArray);
