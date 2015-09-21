// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getSourceRouteManagerLayer_6.hpp>

#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManager.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

rice::pastry::socket::SocketPastryNodeFactory_getSourceRouteManagerLayer_6::SocketPastryNodeFactory_getSourceRouteManagerLayer_6(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManager* srm)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
    , srm(srm)
{
    clinit();
    ctor();
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory_getSourceRouteManagerLayer_6::getTransportLayer()
{
    return srm;
}

org::mpisws::p2p::transport::proximity::ProximityProvider* rice::pastry::socket::SocketPastryNodeFactory_getSourceRouteManagerLayer_6::getProximityProvider()
{
    return srm;
}

org::mpisws::p2p::transport::liveness::LivenessProvider* rice::pastry::socket::SocketPastryNodeFactory_getSourceRouteManagerLayer_6::getLivenessProvider()
{
    return srm;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getSourceRouteManagerLayer_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getSourceRouteManagerLayer_6::getClass0()
{
    return class_();
}

