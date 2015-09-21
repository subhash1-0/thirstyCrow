// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/SecurityException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::SecurityException::SecurityException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::SecurityException::SecurityException()
    : SecurityException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::SecurityException::SecurityException(String* arg0)
    : SecurityException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::SecurityException::SecurityException(Throwable* arg0)
    : SecurityException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::SecurityException::SecurityException(String* arg0, Throwable* arg1)
    : SecurityException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::lang::SecurityException::serialVersionUID;

void ::java::lang::SecurityException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::SecurityException::ctor()");
}

void ::java::lang::SecurityException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::SecurityException::ctor(String* arg0)");
}

void ::java::lang::SecurityException::ctor(Throwable* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::SecurityException::ctor(Throwable* arg0)");
}

void ::java::lang::SecurityException::ctor(String* arg0, Throwable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::SecurityException::ctor(String* arg0, Throwable* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::SecurityException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.SecurityException", 27);
    return c;
}

java::lang::Class* java::lang::SecurityException::getClass0()
{
    return class_();
}

