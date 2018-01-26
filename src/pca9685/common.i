/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "cpointer.i"

%{
#include "pca9685.hpp"
%}
%include "pca9685.hpp"
