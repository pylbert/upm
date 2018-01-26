/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "stdint.i"

%{
#include "bacnetmstp.hpp"
#include "bacnetutil.hpp"
#include "t8100.hpp"
%}
%include "bacnetmstp.hpp"
%include "bacnetutil.hpp"
%include "t8100.hpp"
