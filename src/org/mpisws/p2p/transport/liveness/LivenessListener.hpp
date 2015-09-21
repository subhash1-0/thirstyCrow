// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>

struct org::mpisws::p2p::transport::liveness::LivenessListener
    : public virtual LivenessTypes
{
    virtual void livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
