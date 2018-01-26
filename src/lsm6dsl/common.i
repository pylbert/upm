/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "../upm_vectortypes.i"
%{
#include "lsm6dsl_defs.h"
#include "lsm6dsl.hpp"
%}
%include "lsm6dsl_defs.h"
%include "lsm6dsl.hpp"
