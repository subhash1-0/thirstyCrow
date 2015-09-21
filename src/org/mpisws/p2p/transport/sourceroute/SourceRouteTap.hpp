// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTap.java

#pragma once

#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::sourceroute::SourceRouteTap
    : public virtual ::java::lang::Object
{
    virtual void receivedMessage(::java::nio::ByteBuffer* m, SourceRoute* path) = 0;
    virtual void socketOpened(SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b) = 0;
    virtual void socketClosed(SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b) = 0;
    virtual void receivedBytes(::java::nio::ByteBuffer* m, SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
