// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2.hpp>

#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2::AppSocketPastryNodeFactory_getLivenessTransportLayer_2(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::TransportLayer* tl)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_this(AppSocketPastryNodeFactory_this)
    , tl(tl)
{
    clinit();
    ctor();
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2::getTransportLayer()
{
    return tl;
}

org::mpisws::p2p::transport::liveness::LivenessProvider* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2::getLivenessProvider()
{
    return new AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1(this);
}

org::mpisws::p2p::transport::liveness::OverrideLiveness* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2::getOverrideLiveness()
{
    return new AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2(this);
}

org::mpisws::p2p::transport::liveness::Pinger* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2::getPinger()
{
    return new AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3(this);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2::getClass0()
{
    return class_();
}

