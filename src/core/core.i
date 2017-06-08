%include "../common_top.i"

#ifdef SWIGJAVA
JAVA_JNI_LOADLIBRARY(javaupm_core)

/* JAVA has multiple define collisions once these get flattened out,
   so ignore the base implementation */
%ignore "upm::Gadget::JsonDefinition";
#endif

%include ".Gadget.i"
%include ".Sensor.i"
%include ".Temperature.i"
%include ".Humidity.i"
%include ".Mraa.i"
%include ".ADC.i"
%include ".Pressure.i"
%include ".Moisture.i"
%include ".Light.i"
%include ".LightController.i"
%include ".Gas.i"

/* Actuator types */
%include ".Actuator.i"
%include ".ServoController.i"
