/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "ms5803_defs.h"
#include "ms5803.hpp"
%}
%include "ms5803_defs.h"
%include "ms5803.hpp"
