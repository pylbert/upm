/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "sht1x_defs.h"
#include "sht1x.hpp"
%}
%include "sht1x_defs.h"
%include "sht1x.hpp"
