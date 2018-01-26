/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "std_vector.i"
%include "cpointer.i"
%include "stdint.i"

%{
#include "mpu60x0.hpp"
#include "mpu9150.hpp"
#include "mpu9250.hpp"
#include "ak8975.hpp"
%}
%include "mpu60x0.hpp"
%include "mpu9150.hpp"
%include "mpu9250.hpp"
%include "ak8975.hpp"
