/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "uartat_defs.h"
#include "uartat.hpp"
%}
%include "uartat_defs.h"
%include "uartat.hpp"
