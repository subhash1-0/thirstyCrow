// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_getJoinRequest_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* result);

    // Generated
    RendezvousJoinProtocol_getJoinRequest_1(RendezvousJoinProtocol *RendezvousJoinProtocol_this, ::rice::Continuation* deliverJRToMe, RendezvousSocketNodeHandle* bootstrap);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    RendezvousJoinProtocol *RendezvousJoinProtocol_this;
    ::rice::Continuation* deliverJRToMe;
    RendezvousSocketNodeHandle* bootstrap;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousJoinProtocol;
    friend class RendezvousJoinProtocol_RCJPDeserializer;
};
