// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/util/Collection.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2::RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousSocketPastryNodeFactory_this(RendezvousSocketPastryNodeFactory_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2::getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe)
{
    npc(deliverResultToMe)->receiveResult(bootHandles);
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2::getClass0()
{
    return class_();
}

