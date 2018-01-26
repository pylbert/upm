/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%include "stdint.i"
%include "typemaps.i"

%rename("writeArray")  write(uint8_t *digits);
%rename("writeString") write(std::string digits);

%varargs(4, int digit = 0) write;
%apply uint8_t *INPUT { uint8_t *digits }

%{
#include "tm1637.hpp"
%}
%include "tm1637.hpp"
