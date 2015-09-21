// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::RendezvousStrategy
    : public virtual ::java::lang::Object
{
    static constexpr int32_t SUCCESS { int32_t(1) };
    virtual ::rice::p2p::commonapi::Cancellable* openChannel(::java::lang::Object* target, ::java::lang::Object* rendezvous, ::java::lang::Object* source, int32_t uid, ::rice::Continuation* deliverResultToMe, ::java::util::Map* options) = 0;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) = 0;
    virtual void setTransportLayer(RendezvousTransportLayer* ret) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
