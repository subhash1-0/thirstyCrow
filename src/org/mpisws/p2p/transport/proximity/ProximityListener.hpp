// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/proximity/ProximityListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::proximity::ProximityListener
    : public virtual ::java::lang::Object
{
    virtual void proximityChanged(::java::lang::Object* i, int32_t newProximity, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
