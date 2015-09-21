// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/SocketAddress.hpp>

extern void unimplemented_(const char16_t* name);
java::net::SocketAddress::SocketAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::SocketAddress::SocketAddress()
    : SocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int64_t java::net::SocketAddress::serialVersionUID;

void ::java::net::SocketAddress::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::SocketAddress::ctor()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::SocketAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.SocketAddress", 22);
    return c;
}

java::lang::Class* java::net::SocketAddress::getClass0()
{
    return class_();
}

