%module javaupm_bmi160

%include "typemaps.i"
%include "arrays_java.i"
%include "../java_buffer.i"

%typemap(jni) float * "jfloatArray"
%typemap(jstype) float * "float[]"
%typemap(jtype) float * "float[]"

%typemap(javaout) float * {
    return $jnicall;
}

%typemap(out) float * {
    $result = JCALL1(NewFloatArray, jenv, 3);
    JCALL4(SetFloatArrayRegion, jenv, $result, 0, 3, $1);
}

%ignore getAccelerometer(float *, float *, float *);
%ignore getGyroscope(float *, float *, float *);
%ignore getMagnetometer(float *, float *, float *);

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_bmi160)
