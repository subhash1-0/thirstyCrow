// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2.hpp>

#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2.hpp>

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2(AppSocketPastryNodeFactory_getLivenessTransportLayer_2 *AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this(AppSocketPastryNodeFactory_getLivenessTransportLayer_2_this)
{
    clinit();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2::setLiveness(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t liveness, ::java::util::Map* options)
{
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2::setLiveness(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options)
{ 
    setLiveness(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), liveness, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2::getClass0()
{
    return class_();
}

