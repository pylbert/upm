/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "lsm303d_defs.h"
#include "lsm303d.hpp"
%}
%include "lsm303d_defs.h"
%include "lsm303d.hpp"
