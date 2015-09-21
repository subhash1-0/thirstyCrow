// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getBootstrapper_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDirectStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotManager.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4::RendezvousSocketPastryNodeFactory_getBootstrapper_4(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::java::util::ArrayList* closeMeWhenReady, ::boolArray* booted, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::pastry::socket::SocketNodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns)
    : super(RendezvousSocketPastryNodeFactory_this, *static_cast< ::default_init_tag* >(0))
    , RendezvousSocketPastryNodeFactory_this(RendezvousSocketPastryNodeFactory_this)
    , manager(manager)
    , closeMeWhenReady(closeMeWhenReady)
    , booted(booted)
{
    clinit();
    ctor(pn, tl, handleFactory, pns);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4::checkLiveness(::rice::pastry::socket::SocketNodeHandle* h, ::java::util::Map* options)
{
    auto contactStrat = java_cast< ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(RendezvousSocketPastryNodeFactory::RENDEZVOUS_CONTACT_DIRECT_STRATEGY())));
    auto rsnh = java_cast< RendezvousSocketNodeHandle* >(h);
    if(!npc(rsnh)->canContactDirect() && npc(contactStrat)->canContactDirect(rsnh)) {
        super::checkLiveness(h, options);
        return;
    }
    npc(manager)->openPilot(java_cast< RendezvousSocketNodeHandle* >(h), new RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1(this, closeMeWhenReady, booted, manager, h));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4::getClass0()
{
    return class_();
}

