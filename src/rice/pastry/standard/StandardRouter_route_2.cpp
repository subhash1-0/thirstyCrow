// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java
#include <rice/pastry/standard/StandardRouter_route_2.hpp>

#include <rice/pastry/standard/StandardRouter.hpp>

rice::pastry::standard::StandardRouter_route_2::StandardRouter_route_2(StandardRouter *StandardRouter_this, ::rice::pastry::routing::RouteMessage* rm)
    : super(*static_cast< ::default_init_tag* >(0))
    , StandardRouter_this(StandardRouter_this)
    , rm(rm)
{
    clinit();
    ctor();
}

void rice::pastry::standard::StandardRouter_route_2::run()
{
    StandardRouter_this->route(rm);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouter_route_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardRouter_route_2::getClass0()
{
    return class_();
}

