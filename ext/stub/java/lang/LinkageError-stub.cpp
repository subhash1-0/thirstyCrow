// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/LinkageError.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::LinkageError::LinkageError(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::LinkageError::LinkageError()
    : LinkageError(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::LinkageError::LinkageError(String* arg0)
    : LinkageError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::LinkageError::LinkageError(String* arg0, Throwable* arg1)
    : LinkageError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::lang::LinkageError::serialVersionUID;

void ::java::lang::LinkageError::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::LinkageError::ctor()");
}

void ::java::lang::LinkageError::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::LinkageError::ctor(String* arg0)");
}

void ::java::lang::LinkageError::ctor(String* arg0, Throwable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::LinkageError::ctor(String* arg0, Throwable* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::LinkageError::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.LinkageError", 22);
    return c;
}

java::lang::Class* java::lang::LinkageError::getClass0()
{
    return class_();
}

