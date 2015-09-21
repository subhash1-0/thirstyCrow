// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/GenericNetworkSimulator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>

struct org::mpisws::p2p::transport::direct::GenericNetworkSimulator
    : public virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider
{
    virtual ::rice::environment::Environment* getEnvironment() = 0;
    virtual ::rice::environment::Environment* getEnvironment(::java::lang::Object* i) = 0;
    virtual float networkDelay(::java::lang::Object* a, ::java::lang::Object* b) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* deliverMessage(::java::lang::Object* msg, ::java::lang::Object* to, ::java::lang::Object* from, int32_t delay) = 0;
    virtual ::rice::p2p::commonapi::CancellableTask* enqueueDelivery(Delivery* del, int32_t delay) = 0;
    virtual DirectTransportLayer* getTL(::java::lang::Object* i) = 0;
    virtual bool isAlive(::java::lang::Object* i) = 0;
    virtual void remove(::java::lang::Object* i) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void setMaxSpeed(float rate) = 0;
    virtual void setFullSpeed() = 0;
    virtual ::rice::environment::random::RandomSource* getRandomSource() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
