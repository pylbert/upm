/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "../upm_vectortypes.i"
%{
#include "lis2ds12.hpp"
%}
%include "lis2ds12_defs.h"
%include "lis2ds12.hpp"
