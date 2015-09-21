// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/standard/ProximityNeighborSelector.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::standard::ProximityNeighborSelector
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Cancellable* getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe) override;

    // Generated
    RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this);
    static ::java::lang::Class *class_();
    RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousSocketPastryNodeFactory;
    friend class RendezvousSocketPastryNodeFactory_getContactDeserializer_1;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_3;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1;
};
