/* Python-specific SWIG code */
%module pyupm_bmp280

%include "stdint.i"
%include "iTemperatureSensor.hpp"
%include "iModuleStatus.hpp"
%include "iPressureSensor.hpp"
%include "iHumiditySensor.hpp"

/* Include the common swig file for this library */
%include "common.i"
