/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "rn2903_defs.h"
#include "rn2903.hpp"
%}
%include "rn2903_defs.h"
%include "rn2903.hpp"
