/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "groveledbar.hpp"
#include "my9221.hpp"
#include "grovecircularled.hpp"
%}
%include "my9221.hpp"
%include "groveledbar.hpp"
%include "grovecircularled.hpp"
