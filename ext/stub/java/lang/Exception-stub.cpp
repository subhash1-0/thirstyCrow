// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Exception.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Exception::Exception(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Exception::Exception()
    : Exception(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Exception::Exception(String* arg0)
    : Exception(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Exception::Exception(Throwable* arg0)
    : Exception(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Exception::Exception(String* arg0, Throwable* arg1)
    : Exception(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::Exception::Exception(String* arg0, Throwable* arg1, bool arg2, bool arg3)
    : Exception(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}

constexpr int64_t java::lang::Exception::serialVersionUID;

void ::java::lang::Exception::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Exception::ctor()");
}

void ::java::lang::Exception::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Exception::ctor(String* arg0)");
}

void ::java::lang::Exception::ctor(Throwable* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Exception::ctor(Throwable* arg0)");
}

void ::java::lang::Exception::ctor(String* arg0, Throwable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Exception::ctor(String* arg0, Throwable* arg1)");
}

void ::java::lang::Exception::ctor(String* arg0, Throwable* arg1, bool arg2, bool arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Exception::ctor(String* arg0, Throwable* arg1, bool arg2, bool arg3)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Exception::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Exception", 19);
    return c;
}

java::lang::Class* java::lang::Exception::getClass0()
{
    return class_();
}

