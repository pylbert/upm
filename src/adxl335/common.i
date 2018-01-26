/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "cpointer.i"
%{
#include "adxl335.hpp"
%}
%include "adxl335.hpp"
