#ifdef ANDROID
    %module javaupm_pulsensor
#else
    %module(directors="1") javaupm_pulsensor
#endif
%include "arrays_java.i"

#ifndef ANDROID
    %feature("director") Callback;
    SWIG_DIRECTOR_OWNED(Callback)
#endif

%ignore sample_thread;
%ignore pin_ctx;
%ignore do_sample;
%ignore callback;

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_pulsensor)
