/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "../upm_vectortypes.i"
%{
#include "lis3dh_defs.h"
#include "lis3dh.hpp"
%}
%include "lis3dh_defs.h"
%include "lis3dh.hpp"
