/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "ecezo_defs.h"
#include "ecezo.hpp"
%}
%include "ecezo_defs.h"
%include "ecezo.hpp"
