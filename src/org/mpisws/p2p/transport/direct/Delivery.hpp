// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/Delivery.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::direct::Delivery
    : public virtual ::java::lang::Object
{
    virtual void deliver() = 0;
    virtual int32_t getSeq() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
