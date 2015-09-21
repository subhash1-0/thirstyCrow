// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketOpeningTransportLayer.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::wire::SocketOpeningTransportLayer
    : public virtual ::java::lang::Object
{
    virtual void addSocketCountListener(::org::mpisws::p2p::transport::SocketCountListener* listener) = 0;
    virtual void removeSocketCountListener(::org::mpisws::p2p::transport::SocketCountListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
