// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/NoSuchProviderException.hpp>

extern void unimplemented_(const char16_t* name);
java::security::NoSuchProviderException::NoSuchProviderException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::NoSuchProviderException::NoSuchProviderException()
    : NoSuchProviderException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::security::NoSuchProviderException::NoSuchProviderException(::java::lang::String* arg0)
    : NoSuchProviderException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::security::NoSuchProviderException::serialVersionUID;

void ::java::security::NoSuchProviderException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::NoSuchProviderException::ctor()");
}

void ::java::security::NoSuchProviderException::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::NoSuchProviderException::ctor(::java::lang::String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::NoSuchProviderException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.NoSuchProviderException", 37);
    return c;
}

java::lang::Class* java::security::NoSuchProviderException::getClass0()
{
    return class_();
}

