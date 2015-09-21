// Generated from /pastry-2.1/src/rice/pastry/routing/RouterAddress.java
#include <rice/pastry/routing/RouterAddress.hpp>

rice::pastry::routing::RouterAddress::RouterAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::RouterAddress::RouterAddress()
    : RouterAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::pastry::routing::RouterAddress::myCode;

int32_t rice::pastry::routing::RouterAddress::getCode()
{
    clinit();
    return myCode;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RouterAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.RouterAddress", 33);
    return c;
}

java::lang::Class* rice::pastry::routing::RouterAddress::getClass0()
{
    return class_();
}

