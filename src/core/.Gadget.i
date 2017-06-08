%include "../common_top.i"

%include "std_vector.i"
%include "std_map.i"

/* Using the JAVA class types outside the core package requires
   getCPtr to be public, modify that here */
%typemap(javabody) SWIGTYPE %{
private long swigCPtr;
protected boolean swigCMemOwn;
public $javaclassname(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
}
public static long getCPtr($javaclassname obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
}
%}

typedef std::vector<std::string> vec_str;
%template(vec_str) std::vector<std::string>;

typedef std::map<std::string, float> map_str_float;
%template(map_str_float) std::map<std::string, float>;

typedef std::map<std::string, std::string> map_str_str;
%template(map_str_str) std::map<std::string, std::string>;

/* Any java package including an interface .i will import the
   upm_core java package in the JAVA source */
%typemap(javaimports) SWIGTYPE %{
import upm_core.*;
%}

#if (SWIGJAVA)


#if SWIG_VERSION >= 0x030009
%include "swiginterface.i"
%interface_impl(upm::Gadget);
#endif
#endif

%{
#include "Gadget.hpp"
%}
%include "Gadget.hpp"

/* FOR JAVASCRIPT ONLY!
   If there's a better way to allow multiple inheritance w/javascript, the
   following macro definitions can go away.
   usage: INHERIT_GADGET(upm::MySensorClass)
*/
%define INHERIT_GADGET(YourClassName)
%extend YourClassName {
using upm::Gadget::Description;
using upm::Gadget::JsonDefinition;
using upm::Gadget::Name;
using upm::Gadget::initFromJsonLibDesc;
using upm::Gadget::DataDirectory;
using upm::Gadget::DerivedClassName;
using upm::Gadget::LibraryAbsolutePath;
using upm::Gadget::LibraryBaseName;
using upm::Gadget::LibraryJsonFilename;
using upm::Gadget::LibraryJsonRaw;
using upm::Gadget::LibraryVersion;
}
%enddef
