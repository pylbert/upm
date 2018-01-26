/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "bh1750_defs.h"
#include "bh1750.hpp"
%}
%include "bh1750_defs.h"
%include "bh1750.hpp"
