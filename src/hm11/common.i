/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "carrays.i"

%{
#include "hm11.hpp"
speed_t int_B9600 = B9600;
%}
%include "hm11.hpp"

%array_class(char, charArray);

speed_t int_B9600 = B9600;
