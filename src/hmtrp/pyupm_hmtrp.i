%module pyupm_hmtrp

%include "../carrays_uint8_t.i"
%include "../carrays_uint16_t.i"
%include "../carrays_uint32_t.i"

%rename("getModSignalStrengthNoParam")  getModSignalStrength();
%rename("getRFSignalStrengthNoParam") getRFSignalStrength();

%array_class(char, charArray);

%include "common.i"
