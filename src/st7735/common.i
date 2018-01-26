/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "st7735_gfx.hpp"
#include "st7735.hpp"
%}
%include "st7735_gfx.hpp"
%include "st7735.hpp"
