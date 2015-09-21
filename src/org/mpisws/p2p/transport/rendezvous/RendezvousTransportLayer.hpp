// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayer
    : public virtual ::java::lang::Object
{
    static constexpr int32_t SUCCESS { int32_t(1) };
    virtual void openChannel(::java::lang::Object* requestor, ::java::lang::Object* middleMan, int32_t uid) = 0;
    virtual void messageReceivedFromOverlay(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
