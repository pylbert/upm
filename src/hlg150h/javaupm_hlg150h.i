%module javaupm_hlg150h

%typemap(javaimports) SWIGTYPE %{
import upm_interfaces.*;
%}

%include "common.i"

%pragma(java) jniclasscode=%{
    static {
        try {
            System.loadLibrary("javaupm_hlg150h");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load. \n" + e);
            System.exit(1);
        }
    }
%}
