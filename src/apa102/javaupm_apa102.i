%module javaupm_apa102

%include "typemaps.i"

%typemap(jtype) (uint8_t *colors) "byte[]"
%typemap(jstype) (uint8_t *colors) "byte[]"
%typemap(jni) (uint8_t *colors) "jbyteArray"
%typemap(javain) (uint8_t *colors) "$javainput"

%typemap(in) (uint8_t *colors) {
  $1 = (uint8_t*)JCALL2(GetByteArrayElements, jenv, $input, NULL);
}

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_apa102)
