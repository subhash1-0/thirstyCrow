// Generated from /pastry-2.1/src/rice/pastry/direct/NetworkSimulatorImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>

struct default_init_tag;

class rice::pastry::direct::NetworkSimulatorImpl
    : public virtual ::java::lang::Object
    , public virtual NetworkSimulator
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    BasicNetworkSimulator* simulator {  };
    ::rice::environment::random::RandomSource* random {  };
    ProximityGenerator* generator {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider {  };
protected:
    void ctor(::rice::environment::Environment* env, ProximityGenerator* generator);

public:
    ::rice::environment::Environment* getEnvironment() override;
    void setFullSpeed() override;
    void setMaxSpeed(float rate) override;
    void start() override;
    void stop() override;

private:
    TestRecord* testRecord {  };

public:
    TestRecord* getTestRecord() override;
    void setTestRecord(TestRecord* tr) override;

public: /* package */
    ::java::util::List* listeners {  };

public:
    bool addSimulatorListener(GenericSimulatorListener* sl) override;
    bool removeSimulatorListener(GenericSimulatorListener* sl) override;
    void notifySimulatorListenersSent(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to, int32_t delay) override;
    void notifySimulatorListenersReceived(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to) override;
    void destroy(DirectPastryNode* dpn) override;
    ::rice::p2p::commonapi::CancellableTask* enqueueDelivery(::org::mpisws::p2p::transport::direct::Delivery* del, int32_t delay) override;
    NodeRecord* generateNodeRecord() override;
    DirectNodeHandle* getClosest(DirectNodeHandle* nh) override;
    bool isAlive(::java::lang::Object* nh) override;
    float networkDelay(::java::lang::Object* a, ::java::lang::Object* b) override;
    float proximity(::java::lang::Object* a, ::java::lang::Object* b) override;
    void removeNode(::rice::pastry::PastryNode* node) override;
    NodeRecord* getNodeRecord(DirectNodeHandle* handle) override;
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* getLivenessProvider() override;
    ::org::mpisws::p2p::transport::direct::GenericNetworkSimulator* getGenericSimulator() override;
    void registerNode(::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* dtl, NodeRecord* nr) override;

    // Generated
    NetworkSimulatorImpl(::rice::environment::Environment* env, ProximityGenerator* generator);
protected:
    NetworkSimulatorImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
