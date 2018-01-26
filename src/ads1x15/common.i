/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "ads1x15.hpp"
#include "ads1015.hpp"
#include "ads1115.hpp"
%}
%include "ads1x15.hpp"
%include "ads1115.hpp"
%include "ads1015.hpp"
