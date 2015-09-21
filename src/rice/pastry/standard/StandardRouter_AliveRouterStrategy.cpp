// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java
#include <rice/pastry/standard/StandardRouter_AliveRouterStrategy.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/SendOptions.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::StandardRouter_AliveRouterStrategy::StandardRouter_AliveRouterStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardRouter_AliveRouterStrategy::StandardRouter_AliveRouterStrategy()
    : StandardRouter_AliveRouterStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::NodeHandle* rice::pastry::standard::StandardRouter_AliveRouterStrategy::pickNextHop(::rice::pastry::routing::RouteMessage* msg, ::java::util::Iterator* i)
{
    auto first = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
    if(npc(first)->getLiveness() < ::rice::pastry::NodeHandle::LIVENESS_SUSPECTED) {
        return first;
    }
    while (npc(i)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
        if(npc(nh)->getLiveness() < ::rice::pastry::NodeHandle::LIVENESS_SUSPECTED) {
            return nh;
        }
        if(npc(first)->getLiveness() > npc(nh)->getLiveness())
            first = nh;

    }
    if(npc(first)->getLiveness() >= ::rice::pastry::NodeHandle::LIVENESS_DEAD) {
        return nullptr;
    }
    npc(npc(msg)->getOptions())->setRerouteIfSuspected(false);
    return first;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouter_AliveRouterStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardRouter.AliveRouterStrategy", 55);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardRouter_AliveRouterStrategy::getClass0()
{
    return class_();
}

