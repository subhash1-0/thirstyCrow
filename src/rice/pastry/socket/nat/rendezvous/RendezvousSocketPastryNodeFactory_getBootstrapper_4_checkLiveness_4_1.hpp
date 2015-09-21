// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1(RendezvousSocketPastryNodeFactory_getBootstrapper_4 *RendezvousSocketPastryNodeFactory_getBootstrapper_4_this, ::java::util::ArrayList* closeMeWhenReady, ::boolArray* booted, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::rice::pastry::socket::SocketNodeHandle* h);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    RendezvousSocketPastryNodeFactory_getBootstrapper_4 *RendezvousSocketPastryNodeFactory_getBootstrapper_4_this;
    ::java::util::ArrayList* closeMeWhenReady;
    ::boolArray* booted;
    ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager;
    ::rice::pastry::socket::SocketNodeHandle* h;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousSocketPastryNodeFactory;
    friend class RendezvousSocketPastryNodeFactory_getContactDeserializer_1;
    friend class RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_3;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4;
};
