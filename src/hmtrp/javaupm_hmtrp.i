%module javaupm_hmtrp

%include "stdint.i"
%include "typemaps.i"
%include "../java_buffer.i"
%include "../java_exceptions.i"

%apply uint32_t *OUTPUT { uint32_t *freq, uint32_t *dataRate };
%apply uint16_t *OUTPUT { uint16_t *rxBandwidth };
%apply uint8_t *OUTPUT { uint8_t *modulation, uint8_t *txPower };
%apply uint32_t *OUTPUT { uint32_t *uartBaud };
%apply uint8_t *OUTPUT { uint8_t *strength };

%ignore getRFSignalStrength(uint8_t *strength);
READDATA_EXCEPTION(getRFSignalStrength())

%ignore getModSignalStrength(uint8_t *strength);
READDATA_EXCEPTION(getModSignalStrength())

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_hmtrp)
