// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/CantVerifyConnectivityException.java
#include <org/mpisws/p2p/transport/networkinfo/CantVerifyConnectivityException.hpp>

org::mpisws::p2p::transport::networkinfo::CantVerifyConnectivityException::CantVerifyConnectivityException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::networkinfo::CantVerifyConnectivityException::CantVerifyConnectivityException(::java::lang::String* s) 
    : CantVerifyConnectivityException(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

void org::mpisws::p2p::transport::networkinfo::CantVerifyConnectivityException::ctor(::java::lang::String* s)
{
    super::ctor(s);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::CantVerifyConnectivityException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.networkinfo.CantVerifyConnectivityException", 68);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::CantVerifyConnectivityException::getClass0()
{
    return class_();
}

