// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayerListener.hpp>

struct org::mpisws::p2p::transport::priority::PriorityTransportLayerListener
    : public virtual ::org::mpisws::p2p::transport::TransportLayerListener
{
    virtual void enqueued(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) = 0;
    virtual void dropped(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
