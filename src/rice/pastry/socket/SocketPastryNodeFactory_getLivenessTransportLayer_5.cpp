// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getLivenessTransportLayer_5.hpp>

#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5::SocketPastryNodeFactory_getLivenessTransportLayer_5(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl* ltl)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
    , ltl(ltl)
{
    clinit();
    ctor();
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5::getTransportLayer()
{
    return ltl;
}

org::mpisws::p2p::transport::liveness::LivenessProvider* rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5::getLivenessProvider()
{
    return ltl;
}

org::mpisws::p2p::transport::liveness::OverrideLiveness* rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5::getOverrideLiveness()
{
    return ltl;
}

org::mpisws::p2p::transport::liveness::Pinger* rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5::getPinger()
{
    return ltl;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getLivenessTransportLayer_5::getClass0()
{
    return class_();
}

