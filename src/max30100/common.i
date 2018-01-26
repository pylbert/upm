/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "max30100.hpp"
#include "max30100_regs.h"
%}
%include "max30100.hpp"
%include "max30100_regs.h"
