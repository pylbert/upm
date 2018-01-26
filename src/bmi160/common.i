/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "cpointer.i"
%include "std_string.i"

%{
#include "bmi160_defs.h"
#include "bmi160.hpp"
%}
%include "bmi160_defs.h"
%include "bmi160.hpp"
