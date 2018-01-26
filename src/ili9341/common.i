/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "ili9341_gfx.hpp"
#include "ili9341.hpp"
%}
%include "ili9341_gfx.hpp"
%include "ili9341.hpp"
