// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getUpperIdentityLayer_7.hpp>

#include <org/mpisws/p2p/transport/identity/UpperIdentity.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

rice::pastry::socket::SocketPastryNodeFactory_getUpperIdentityLayer_7::SocketPastryNodeFactory_getUpperIdentityLayer_7(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::identity::UpperIdentity* upperIdentityLayer)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
    , upperIdentityLayer(upperIdentityLayer)
{
    clinit();
    ctor();
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory_getUpperIdentityLayer_7::getTransportLayer()
{
    return upperIdentityLayer;
}

org::mpisws::p2p::transport::proximity::ProximityProvider* rice::pastry::socket::SocketPastryNodeFactory_getUpperIdentityLayer_7::getProximityProvider()
{
    return upperIdentityLayer;
}

org::mpisws::p2p::transport::liveness::LivenessProvider* rice::pastry::socket::SocketPastryNodeFactory_getUpperIdentityLayer_7::getLivenessProvider()
{
    return upperIdentityLayer;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getUpperIdentityLayer_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getUpperIdentityLayer_7::getClass0()
{
    return class_();
}

