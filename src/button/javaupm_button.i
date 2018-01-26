%module javaupm_button

%apply int {mraa::Edge}

%include "common.i"

JAVA_ADD_INSTALLISR_EDGE(upm::Button)

JAVA_JNI_LOADLIBRARY(javaupm_button)
