// Generated from /pastry-2.1/src/rice/pastry/direct/NetworkSimulator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::direct::NetworkSimulator
    : public virtual ::java::lang::Object
{
    virtual ::rice::environment::Environment* getEnvironment() = 0;
    virtual bool isAlive(::java::lang::Object* nh) = 0;
    virtual float proximity(::java::lang::Object* a, ::java::lang::Object* b) = 0;
    virtual float networkDelay(::java::lang::Object* a, ::java::lang::Object* b) = 0;
    virtual void setTestRecord(TestRecord* tr) = 0;
    virtual TestRecord* getTestRecord() = 0;
    virtual DirectNodeHandle* getClosest(DirectNodeHandle* nh) = 0;
    virtual void destroy(DirectPastryNode* dpn) = 0;
    virtual NodeRecord* generateNodeRecord() = 0;
    virtual void removeNode(::rice::pastry::PastryNode* node) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual ::rice::p2p::commonapi::CancellableTask* enqueueDelivery(::org::mpisws::p2p::transport::direct::Delivery* del, int32_t delay) = 0;
    virtual void setMaxSpeed(float rate) = 0;
    virtual void setFullSpeed() = 0;
    virtual void notifySimulatorListenersSent(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to, int32_t delay) = 0;
    virtual void notifySimulatorListenersReceived(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to) = 0;
    virtual bool addSimulatorListener(GenericSimulatorListener* sl) = 0;
    virtual bool removeSimulatorListener(GenericSimulatorListener* sl) = 0;
    virtual NodeRecord* getNodeRecord(DirectNodeHandle* handle) = 0;
    virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider* getLivenessProvider() = 0;
    virtual ::org::mpisws::p2p::transport::direct::GenericNetworkSimulator* getGenericSimulator() = 0;
    virtual void registerNode(::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* dtl, NodeRecord* nr) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
