// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1.hpp>

#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2.hpp>

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1(AppSocketPastryNodeFactory_getLivenessTransportLayer_2 *AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this(AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this)
{
    clinit();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
}

bool rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::checkLiveness(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, ::java::util::Map* options)
{
    return false;
}

bool rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::checkLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return checkLiveness(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), options);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::clearState(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i)
{
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::clearState(::java::lang::Object* i)
{ 
    clearState(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i));
}

int32_t rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::getLiveness(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, ::java::util::Map* options)
{
    return ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_ALIVE;
}

int32_t rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::getLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return getLiveness(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), options);
}

bool rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1::getClass0()
{
    return class_();
}

