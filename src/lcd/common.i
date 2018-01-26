/* SWIG items common to all language extensions */

/* Include UPM top-level common file */
%include "../common_top.i"

%{
#include "lcd.hpp"
#include "eboled.hpp"
#include "ssd1306.hpp"
#include "ssd1308.hpp"
#include "ssd1327.hpp"
%}

%include "lcd.hpp"
%include "eboled.hpp"
%include "ssd1306.hpp"
%include "ssd1308.hpp"
%include "ssd1327.hpp"
%include "ssd.hpp"
