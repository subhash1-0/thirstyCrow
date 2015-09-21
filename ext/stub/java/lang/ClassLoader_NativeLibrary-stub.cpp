// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ClassLoader_NativeLibrary.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ClassLoader_NativeLibrary::ClassLoader_NativeLibrary(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ClassLoader_NativeLibrary::ClassLoader_NativeLibrary(Class* arg0, String* arg1, bool arg2)
    : ClassLoader_NativeLibrary(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::lang::ClassLoader_NativeLibrary::ctor(Class* arg0, String* arg1, bool arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassLoader_NativeLibrary::ctor(Class* arg0, String* arg1, bool arg2)");
}

void java::lang::ClassLoader_NativeLibrary::finalize()
{ /* stub */
    unimplemented_(u"void java::lang::ClassLoader_NativeLibrary::finalize()");
}

java::lang::Class* java::lang::ClassLoader_NativeLibrary::getFromClass()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader_NativeLibrary::getFromClass()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ClassLoader_NativeLibrary::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ClassLoader.NativeLibrary", 35);
    return c;
}

java::lang::Class* java::lang::ClassLoader_NativeLibrary::getClass0()
{
    return class_();
}

