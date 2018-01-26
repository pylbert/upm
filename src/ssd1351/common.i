/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "ssd1351.hpp"
#include "ssd1351_gfx.hpp"
%}
%include "ssd1351_gfx.hpp"
%include "ssd1351.hpp"
