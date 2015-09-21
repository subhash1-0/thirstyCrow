// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/MessageCallback.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::MessageCallback
    : public virtual ::java::lang::Object
{
    virtual void ack(MessageRequestHandle* msg) = 0;
    virtual void sendFailed(MessageRequestHandle* msg, ::java::lang::Exception* reason) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
