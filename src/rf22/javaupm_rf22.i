#ifdef ANDROID
    %module javaupm_rf22
#else
    %module(directors="1") javaupm_rf22
#endif

%include "arrays_java.i"
%include "typemaps.i"

%apply uint8_t *INOUT { uint8_t* len };
%apply signed char[] {uint8_t*};

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_rf22)
