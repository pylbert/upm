%module javaupm_si7005

%include "common.i"

%pragma(java) jniclasscode=%{
    static {
        try {
            System.loadLibrary("javaupm_si7005");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Native code library failed to load. \n" + e);
            System.exit(1);
        }
    }
%}

