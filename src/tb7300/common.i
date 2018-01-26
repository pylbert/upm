/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "bacnetmstp.hpp"
#include "bacnetutil.hpp"
#include "tb7300.hpp"
%}
%include "bacnetmstp.hpp"
%include "bacnetutil.hpp"
%include "tb7300.hpp"
