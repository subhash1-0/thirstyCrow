// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ClassNotFoundException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ClassNotFoundException::ClassNotFoundException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ClassNotFoundException::ClassNotFoundException()
    : ClassNotFoundException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::ClassNotFoundException::ClassNotFoundException(String* arg0)
    : ClassNotFoundException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::ClassNotFoundException::ClassNotFoundException(String* arg0, Throwable* arg1)
    : ClassNotFoundException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::lang::ClassNotFoundException::serialVersionUID;

void ::java::lang::ClassNotFoundException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassNotFoundException::ctor()");
}

void ::java::lang::ClassNotFoundException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassNotFoundException::ctor(String* arg0)");
}

void ::java::lang::ClassNotFoundException::ctor(String* arg0, Throwable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassNotFoundException::ctor(String* arg0, Throwable* arg1)");
}

java::lang::Throwable* java::lang::ClassNotFoundException::getCause()
{ /* stub */
    unimplemented_(u"java::lang::Throwable* java::lang::ClassNotFoundException::getCause()");
    return 0;
}

java::lang::Throwable* java::lang::ClassNotFoundException::getException()
{ /* stub */
    unimplemented_(u"java::lang::Throwable* java::lang::ClassNotFoundException::getException()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ClassNotFoundException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ClassNotFoundException", 32);
    return c;
}

java::lang::Class* java::lang::ClassNotFoundException::getClass0()
{
    return class_();
}

