/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "hmtrp.hpp"
speed_t int_B9600 = B9600;
%}
%include "hmtrp.hpp"

speed_t int_B9600 = B9600;
