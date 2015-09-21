// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/TransportLayerCallback.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::TransportLayerCallback
    : public virtual ::java::lang::Object
{
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */ = 0;
    virtual void incomingSocket(P2PSocket* s) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
