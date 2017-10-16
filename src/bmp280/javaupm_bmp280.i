%module javaupm_bmp280

%include "typemaps.i"
%include "arrays_java.i";
%include "../java_buffer.i"

%typemap(javaimports) SWIGTYPE %{
    import upm_interfaces.*;
%}

%include "common.i"

%pragma(java) jniclasscode=%{
    static {
        try {
            System.loadLibrary("javaupm_bmp280");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load. \n" + e);
            System.exit(1);
        }
    }
%}
