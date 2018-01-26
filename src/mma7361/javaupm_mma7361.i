%module javaupm_mma7361

%include "typemaps.i"
%include "arrays_java.i";
%include "../java_buffer.i"

%apply int *OUTPUT { int *x, int *y, int *z };
%apply float *OUTPUT { float *ax, float *ay, float *az  };

%typemap(jni) float* "jfloatArray"
%typemap(jstype) float* "float[]"
%typemap(jtype) float* "float[]"

%typemap(javaout) float* {
    return $jnicall;
}

%typemap(out) float *getAcceleration {
    $result = JCALL1(NewFloatArray, jenv, 3);
    JCALL4(SetFloatArrayRegion, jenv, $result, 0, 3, $1);
}

%typemap(out) float *getVolts {
    $result = JCALL1(NewFloatArray, jenv, 3);
    JCALL4(SetFloatArrayRegion, jenv, $result, 0, 3, $1);
}

%typemap(out) float *getNormalized {
    $result = JCALL1(NewFloatArray, jenv, 3);
    JCALL4(SetFloatArrayRegion, jenv, $result, 0, 3, $1);
}

%ignore getNormalized(float *, float *, float *);
%ignore getAcceleration(float *, float *, float *);
%ignore getVolts(float *, float *, float *);

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_mma7361)
