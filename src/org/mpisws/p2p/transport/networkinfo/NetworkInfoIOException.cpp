// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoIOException.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoIOException.hpp>

#include <java/lang/Exception.hpp>

org::mpisws::p2p::transport::networkinfo::NetworkInfoIOException::NetworkInfoIOException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoIOException::NetworkInfoIOException(::java::lang::Exception* e) 
    : NetworkInfoIOException(*static_cast< ::default_init_tag* >(0))
{
    ctor(e);
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoIOException::ctor(::java::lang::Exception* e)
{
    super::ctor();
    initCause(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoIOException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.networkinfo.NetworkInfoIOException", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoIOException::getClass0()
{
    return class_();
}

