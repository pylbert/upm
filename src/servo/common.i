/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "es08a.hpp"
#include "servo.hpp"
#include "es9257.hpp"
%}
%include "servo.hpp"
%include "es9257.hpp"
%include "es08a.hpp"
