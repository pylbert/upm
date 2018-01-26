/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "cpointer.i"
%{
#include "mma7660_regs.h"
#include "mma7660.hpp"
%}
%include "mma7660_regs.h"
%include "mma7660.hpp"
