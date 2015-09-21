// Generated from /pastry-2.1/src/rice/pastry/transport/TransportPastryNodeFactory.java
#include <rice/pastry/transport/TransportPastryNodeFactory_getProximityNeighborSelector_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/util/Collection.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/transport/TransportPastryNodeFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::transport::TransportPastryNodeFactory_getProximityNeighborSelector_1::TransportPastryNodeFactory_getProximityNeighborSelector_1(TransportPastryNodeFactory *TransportPastryNodeFactory_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , TransportPastryNodeFactory_this(TransportPastryNodeFactory_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Cancellable* rice::pastry::transport::TransportPastryNodeFactory_getProximityNeighborSelector_1::getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe)
{
    npc(deliverResultToMe)->receiveResult(bootHandles);
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::TransportPastryNodeFactory_getProximityNeighborSelector_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::transport::TransportPastryNodeFactory_getProximityNeighborSelector_1::getClass0()
{
    return class_();
}

