/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%include "carrays.i"
%{
#include "xbee.hpp"
%}
%include "xbee.hpp"
%array_class(char, charArray);
