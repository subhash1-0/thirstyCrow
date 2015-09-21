// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/UnknownHostException.hpp>

extern void unimplemented_(const char16_t* name);
java::net::UnknownHostException::UnknownHostException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::UnknownHostException::UnknownHostException()
    : UnknownHostException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::net::UnknownHostException::UnknownHostException(::java::lang::String* arg0)
    : UnknownHostException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::net::UnknownHostException::serialVersionUID;

void ::java::net::UnknownHostException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::UnknownHostException::ctor()");
}

void ::java::net::UnknownHostException::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::UnknownHostException::ctor(::java::lang::String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::UnknownHostException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.UnknownHostException", 29);
    return c;
}

java::lang::Class* java::net::UnknownHostException::getClass0()
{
    return class_();
}

