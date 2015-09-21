// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::liveness::LivenessStrategy
    : public virtual ::java::lang::Object
{
    virtual void checkLiveness(::java::lang::Object* i, ::rice::Continuation* c) = 0;
    virtual int32_t getLiveness(::java::lang::Object* identity) = 0;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m) = 0;
    virtual void socketConnected(::java::lang::Object* i) = 0;
    virtual void socketAccepted(::java::lang::Object* i) = 0;
    virtual void socketFailed(::java::lang::Object* i) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
