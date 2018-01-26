/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "../carrays_uint8_t.i"
%include "../carrays_uint16_t.i"

%{
#include "wt5001.hpp"
speed_t int_B9600 = B9600;
%}
%include "wt5001.hpp"
speed_t int_B9600 = B9600;
