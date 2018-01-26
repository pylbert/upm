/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "../upm_vectortypes.i"
%{
#include "lsm6ds3h_defs.h"
#include "lsm6ds3h.hpp"
%}
%include "lsm6ds3h_defs.h"
%include "lsm6ds3h.hpp"
