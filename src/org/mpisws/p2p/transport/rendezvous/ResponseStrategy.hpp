// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/ResponseStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::rendezvous::ResponseStrategy
    : public virtual ::java::lang::Object
{
    virtual bool sendDirect(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) = 0;
    virtual void messageSent(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) = 0;
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
