// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/TransportLayerListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::TransportLayerListener
    : public virtual ::java::lang::Object
{
    virtual void wrote(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) = 0;
    virtual void read(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
