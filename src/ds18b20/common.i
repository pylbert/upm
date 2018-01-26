/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_string.i"
%include "carrays.i"
%{
#include "ds18b20_defs.h"
#include "ds18b20.hpp"
%}
%include "ds18b20_defs.h"
%include "ds18b20.hpp"
%array_class(char, charArray);
