// Generated from /pastry-2.1/src/rice/pastry/direct/BasicNetworkSimulator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator.hpp>
#include <org/mpisws/p2p/transport/direct/GenericNetworkSimulator.hpp>

struct default_init_tag;

class rice::pastry::direct::BasicNetworkSimulator
    : public ::org::mpisws::p2p::transport::direct::EventSimulator
    , public virtual ::org::mpisws::p2p::transport::direct::GenericNetworkSimulator
{

public:
    typedef ::org::mpisws::p2p::transport::direct::EventSimulator super;

public: /* package */
    ::java::util::Map* nodes {  };
    NetworkSimulator* sim {  };

public: /* protected */
    int32_t MIN_DELAY {  };
    int32_t maxDiameter {  };
    int32_t minDelay {  };
protected:
    void ctor(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, NetworkSimulator* sim);

private:
    void addTask(::rice::selector::TimerTask* dtt);

public:
    ::rice::p2p::commonapi::CancellableTask* enqueueDelivery(::org::mpisws::p2p::transport::direct::Delivery* d, int32_t delay) override;
    virtual ::rice::p2p::commonapi::Cancellable* deliverMessage(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from);
    ::rice::p2p::commonapi::Cancellable* deliverMessage(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from, int32_t delay) override;

public: /* package */
    virtual void notifySimulatorListenersReceived(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to);

public:
    virtual ::rice::p2p::commonapi::Cancellable* deliverMessageFixedRate(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from, int32_t delay, int32_t period);
    virtual ::rice::p2p::commonapi::Cancellable* deliverMessage(::java::lang::Object* msg, ::java::lang::Object* node, ::java::lang::Object* from, int32_t delay, int32_t period);
    virtual void registerIdentifier(::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* dtl, NodeRecord* record);
    void remove(::java::lang::Object* i) override;
    ::rice::environment::Environment* getEnvironment() override;
    ::rice::environment::Environment* getEnvironment(::java::lang::Object* i) override;
    ::rice::environment::random::RandomSource* getRandomSource() override;
    bool isAlive(::java::lang::Object* i) override;
    ::org::mpisws::p2p::transport::direct::DirectTransportLayer* getTL(::java::lang::Object* i) override;
    float networkDelay(::java::lang::Object* a, ::java::lang::Object* b) override;
    virtual float proximity(::java::lang::Object* a, ::java::lang::Object* b);
    virtual NodeRecord* getNodeRecord(DirectNodeHandle* handle);

public: /* package */
    ::java::util::List* livenessListeners {  };

public:
    void addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;
    bool removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name) override;

private:
    void notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options);

public:
    bool checkLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    int32_t getLiveness(::java::lang::Object* i, ::java::util::Map* options) override;
    void clearState(::java::lang::Object* i) override;

    // Generated
    BasicNetworkSimulator(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, NetworkSimulator* sim);
protected:
    BasicNetworkSimulator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void setFullSpeed();
    virtual void setMaxSpeed(float rate);
    virtual void start();
    virtual void stop();

private:
    virtual ::java::lang::Class* getClass0();
    friend class BasicNetworkSimulator_Tupel;
};
