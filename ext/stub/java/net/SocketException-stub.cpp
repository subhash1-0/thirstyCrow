// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/SocketException.hpp>

extern void unimplemented_(const char16_t* name);
java::net::SocketException::SocketException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::SocketException::SocketException()
    : SocketException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::net::SocketException::SocketException(::java::lang::String* arg0)
    : SocketException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::net::SocketException::serialVersionUID;

void ::java::net::SocketException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::SocketException::ctor()");
}

void ::java::net::SocketException::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::SocketException::ctor(::java::lang::String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::SocketException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.SocketException", 24);
    return c;
}

java::lang::Class* java::net::SocketException::getClass0()
{
    return class_();
}

