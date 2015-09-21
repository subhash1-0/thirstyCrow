// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Observer.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_3
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Observer
{

public:
    typedef ::java::lang::Object super;
    void update(::java::util::Observable* o, ::java::lang::Object* arg) override;

    // Generated
    RendezvousSocketPastryNodeFactory_getBootstrapper_3(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this, ::java::util::ArrayList* closeMeWhenReady, ::boolArray* booted, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager);
    static ::java::lang::Class *class_();
    RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this;
    ::java::util::ArrayList* closeMeWhenReady;
    ::boolArray* booted;
    ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousSocketPastryNodeFactory;
    friend class RendezvousSocketPastryNodeFactory_getContactDeserializer_1;
    friend class RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1;
};
