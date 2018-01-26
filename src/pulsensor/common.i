/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "pulsensor.hpp"
%}
%include "pulsensor.hpp"
%include "Callback.hpp"
