// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4
    : public ::rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper super;

public: /* protected */
    void checkLiveness(::rice::pastry::socket::SocketNodeHandle* h, ::java::util::Map* options) override;

    // Generated

public:
    RendezvousSocketPastryNodeFactory_getBootstrapper_4(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::java::util::ArrayList* closeMeWhenReady, ::boolArray* booted, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::pastry::socket::SocketNodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns);
    static ::java::lang::Class *class_();
    RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this;
    ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager;
    ::java::util::ArrayList* closeMeWhenReady;
    ::boolArray* booted;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousSocketPastryNodeFactory;
    friend class RendezvousSocketPastryNodeFactory_getContactDeserializer_1;
    friend class RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_3;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1;
};
