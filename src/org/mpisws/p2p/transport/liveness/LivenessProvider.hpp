// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessProvider.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>

struct org::mpisws::p2p::transport::liveness::LivenessProvider
    : public virtual LivenessTypes
{
    virtual int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) = 0;
    virtual bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) = 0;
    virtual void addLivenessListener(LivenessListener* name) = 0;
    virtual bool removeLivenessListener(LivenessListener* name) = 0;
    virtual void clearState(::java::lang::Object* i) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
