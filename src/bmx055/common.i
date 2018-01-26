/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "cpointer.i"
%{
#include "bma250e_defs.h"
#include "bmg160_defs.h"
#include "bmm150_defs.h"
#include "bmc150.hpp"
#include "bmx055.hpp"
#include "bmi055.hpp"
%}
%include "bmg160_defs.h"
%include "bmm150_defs.h"
%include "bma250e_defs.h"
%include "bmx055.hpp"
%include "bmi055.hpp"
%include "bmc150.hpp"
