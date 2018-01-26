/* Javascript-specific SWIG code */
%module jsupm_bmp280

%include "iTemperatureSensor.hpp"
%include "iModuleStatus.hpp"
%include "iPressureSensor.hpp"
%include "iHumiditySensor.hpp"

/* Include the common swig file for this library */
%include "common.i"
