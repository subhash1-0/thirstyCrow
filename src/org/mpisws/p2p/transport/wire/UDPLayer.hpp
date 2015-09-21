// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>

struct org::mpisws::p2p::transport::wire::UDPLayer
    : public virtual ::rice::Destructable
{
    virtual void acceptMessages(bool b) = 0;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
