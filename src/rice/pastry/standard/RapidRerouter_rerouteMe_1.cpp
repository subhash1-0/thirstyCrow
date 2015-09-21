// Generated from /pastry-2.1/src/rice/pastry/standard/RapidRerouter.java
#include <rice/pastry/standard/RapidRerouter_rerouteMe_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/standard/RapidRerouter.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::RapidRerouter_rerouteMe_1::RapidRerouter_rerouteMe_1(RapidRerouter *RapidRerouter_this, ::rice::pastry::routing::RouteMessage* rm)
    : super(*static_cast< ::default_init_tag* >(0))
    , RapidRerouter_this(RapidRerouter_this)
    , rm(rm)
{
    clinit();
    ctor();
}

void rice::pastry::standard::RapidRerouter_rerouteMe_1::run()
{
    npc(npc(rm)->getOptions())->setRerouteIfSuspected(::rice::pastry::routing::SendOptions::defaultRerouteIfSuspected);
    RapidRerouter_this->route(rm);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::RapidRerouter_rerouteMe_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::RapidRerouter_rerouteMe_1::getClass0()
{
    return class_();
}

