// Generated from /pastry-2.1/src/rice/pastry/routing/InitiateRouteSetMaintenance.java
#include <rice/pastry/routing/InitiateRouteSetMaintenance.hpp>

#include <rice/pastry/routing/RouteProtocolAddress.hpp>

rice::pastry::routing::InitiateRouteSetMaintenance::InitiateRouteSetMaintenance(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::InitiateRouteSetMaintenance::InitiateRouteSetMaintenance() 
    : InitiateRouteSetMaintenance(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::routing::InitiateRouteSetMaintenance::ctor()
{
    super::ctor(RouteProtocolAddress::getCode());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::InitiateRouteSetMaintenance::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.InitiateRouteSetMaintenance", 47);
    return c;
}

java::lang::Class* rice::pastry::routing::InitiateRouteSetMaintenance::getClass0()
{
    return class_();
}

