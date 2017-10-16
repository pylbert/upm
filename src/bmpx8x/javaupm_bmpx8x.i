%module javaupm_bmpx8x

%typemap(javaimports) SWIGTYPE %{
import upm_interfaces.*;
%}

%include "common.i"

%pragma(java) jniclasscode=%{
    static {
        try {
            System.loadLibrary("javaupm_bmpx8x");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load. \n" + e);
            System.exit(1);
        }
    }
%}
