#ifdef ANDROID
    %module javaupm_max30100
#else
    %module(directors="1", threads="1") javaupm_max30100
#endif

#ifndef ANDROID
    %feature("director") upm::Callback;
#endif

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_max30100)
