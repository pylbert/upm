/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "cpointer.i"
%{
#include "ozwinterface.hpp"
#include "ozw.hpp"
#include "aeotecdsb09104.hpp"
#include "aeotecdw2e.hpp"
#include "aeotecsdg2.hpp"
#include "aeotecss6.hpp"
#include "ozwdump.hpp"
#include "tzemt400.hpp"
%}
%include "ozwinterface.hpp"
%include "ozw.hpp"
%include "aeotecdsb09104.hpp"
%include "aeotecdw2e.hpp"
%include "aeotecsdg2.hpp"
%include "aeotecss6.hpp"
%include "ozwdump.hpp"
%include "tzemt400.hpp"
