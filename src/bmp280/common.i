/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "cpointer.i"
%{
#include "bmp280_regs.h"
#include "bmp280.hpp"
#include "bme280.hpp"
%}
%include "bmp280_regs.h"
%include "bmp280.hpp"
%include "bme280.hpp"
