/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%{
#include "mcp2515_regs.h"
#include "mcp2515.hpp"
%}
%include "mcp2515_regs.h"
%include "mcp2515.hpp"
