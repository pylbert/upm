%module javaupm_lsm303d
%include "typemaps.i"
%include "../upm_javastdvector.i"

%ignore getMagnetometer(float *, float *, float *);
%ignore getAccelerometer(float *, float *, float *);

%typemap(javaimports) SWIGTYPE %{
import java.util.AbstractList;
import java.lang.Float;
%}

%typemap(javaout) SWIGTYPE {
    return new $&javaclassname($jnicall, true);
}
%typemap(javaout) std::vector<float> {
    return (AbstractList<Float>)(new $&javaclassname($jnicall, true));
}
%typemap(jstype) std::vector<float> "AbstractList<Float>"

%template(floatVector) std::vector<float>;

%include "common.i"

JAVA_JNI_LOADLIBRARY(javaupm_lsm303d)
