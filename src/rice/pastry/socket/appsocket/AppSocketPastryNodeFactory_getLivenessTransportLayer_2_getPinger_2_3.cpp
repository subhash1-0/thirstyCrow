// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3.hpp>

#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2.hpp>

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3(AppSocketPastryNodeFactory_getLivenessTransportLayer_2 *AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this(AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this)
{
    clinit();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3::addPingListener(::org::mpisws::p2p::transport::liveness::PingListener* name)
{
}

bool rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3::ping(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, ::java::util::Map* options)
{
    return false;
}

bool rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3::ping(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return ping(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), options);
}

bool rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3::removePingListener(::org::mpisws::p2p::transport::liveness::PingListener* name)
{
    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3::getClass0()
{
    return class_();
}

