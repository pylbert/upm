/* Include global UPM interface file */
%include "../common_top.i"

%{
    /* SWIG preprocessor copies this directly to the output wrapper*/
    #include "sensortemplate.hpp"
%}

/* %include is a SWIG directive.  SWIG will wrap types exposed in this
 * header to the target language. */
%include "sensortemplate.hpp"
