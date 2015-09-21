// Generated from /pastry-2.1/src/rice/pastry/routing/RouteProtocolAddress.java
#include <rice/pastry/routing/RouteProtocolAddress.hpp>

rice::pastry::routing::RouteProtocolAddress::RouteProtocolAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::RouteProtocolAddress::RouteProtocolAddress()
    : RouteProtocolAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::pastry::routing::RouteProtocolAddress::myCode;

int32_t rice::pastry::routing::RouteProtocolAddress::getCode()
{
    clinit();
    return myCode;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RouteProtocolAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.RouteProtocolAddress", 40);
    return c;
}

java::lang::Class* rice::pastry::routing::RouteProtocolAddress::getClass0()
{
    return class_();
}

