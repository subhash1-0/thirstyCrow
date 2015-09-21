// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/SocketCallback.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::SocketCallback
    : public virtual ::java::lang::Object
{
    virtual void receiveResult(SocketRequestHandle* cancellable, P2PSocket* sock) = 0;
    virtual void receiveException(SocketRequestHandle* s, ::java::lang::Exception* ex) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
