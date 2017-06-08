%module pyupm_bmp280

/* Include doxygen-generated documentation */
%include "pyupm_doxy2swig.i"

#ifdef DOXYGEN
%include "bmp280_doc.i"
#endif

%include "iHumiditySensor.hpp"
%include "iPressureSensor.hpp"
%include "iTemperatureSensor.hpp"

%include "common.i"
