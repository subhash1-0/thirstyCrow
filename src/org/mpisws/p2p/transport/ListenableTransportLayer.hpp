// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ListenableTransportLayer.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::ListenableTransportLayer
    : public virtual ::java::lang::Object
{
    virtual void addTransportLayerListener(TransportLayerListener* listener) = 0;
    virtual void removeTransportLayerListener(TransportLayerListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
