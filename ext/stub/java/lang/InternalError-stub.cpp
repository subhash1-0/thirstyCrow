// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/InternalError.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::InternalError::InternalError(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::InternalError::InternalError()
    : InternalError(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::InternalError::InternalError(String* arg0)
    : InternalError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::InternalError::InternalError(Throwable* arg0)
    : InternalError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::InternalError::InternalError(String* arg0, Throwable* arg1)
    : InternalError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::lang::InternalError::serialVersionUID;

void ::java::lang::InternalError::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::InternalError::ctor()");
}

void ::java::lang::InternalError::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::InternalError::ctor(String* arg0)");
}

void ::java::lang::InternalError::ctor(Throwable* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::InternalError::ctor(Throwable* arg0)");
}

void ::java::lang::InternalError::ctor(String* arg0, Throwable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::InternalError::ctor(String* arg0, Throwable* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::InternalError::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.InternalError", 23);
    return c;
}

java::lang::Class* java::lang::InternalError::getClass0()
{
    return class_();
}

