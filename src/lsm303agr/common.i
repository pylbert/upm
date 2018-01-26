/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "lsm303agr_defs.h"
#include "lsm303agr.hpp"
%}
%include "lsm303agr_defs.h"
%include "lsm303agr.hpp"
