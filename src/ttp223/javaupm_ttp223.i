%module (docstring="TTP223 Touch Sensor") javaupm_ttp223

%apply int {mraa::Edge}

%include "common.i"

JAVA_ADD_INSTALLISR_EDGE(upm::TTP223)

JAVA_JNI_LOADLIBRARY(javaupm_ttp223)
