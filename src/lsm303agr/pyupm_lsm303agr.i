// Include doxygen-generated documentation
%include "pyupm_doxy2swig.i"
%module pyupm_lsm303agr
%include "../upm.i"
%include "../upm_vectortypes.i"

%include "lsm303agr_defs.h"
%include "lsm303agr.hpp"
%{
    #include "lsm303agr.hpp"
%}
