// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/StandardJoinProtocol.hpp>
#include <java/util/Observer.hpp>
#include <rice/pastry/NodeSetListener.hpp>
#include <rice/selector/LoopObserver.hpp>

struct default_init_tag;

class rice::pastry::standard::ConsistentJoinProtocol
    : public StandardJoinProtocol
    , public virtual ::java::util::Observer
    , public virtual ::rice::pastry::NodeSetListener
    , public virtual ::rice::selector::LoopObserver
{

public:
    typedef StandardJoinProtocol super;

public: /* protected */
    int32_t MAX_TIME_TO_BE_SCHEDULED {  };
    static constexpr int32_t MAX_NUM_TO_HEAR_FROM { int32_t(8) };
    bool tryingToGoReady {  };

public: /* package */
    ::java::util::Map* gotResponse {  };
    ::java::util::HashMap* failed {  };
    ::rice::selector::TimerTask* cleanupTask {  };
    int32_t failedNodeExpirationTime {  };
    int32_t maxFailedEntries {  };
    ::java::util::HashSet* observing {  };

public:
    int32_t RETRY_INTERVAL {  };
protected:
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy);
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);

public: /* protected */
    void setReady() override;

public:
    virtual void addToLeafSet(::rice::pastry::NodeHandle* nh);

public: /* package */
    ::rice::selector::TimerTask* retryTask {  };

public:
    virtual void requestFromEveryoneWeHaventHeardFrom();
    virtual void otherNodesMaySuspectFaulty(int32_t timeNotScheduled);
    virtual ::java::util::Collection* whoDoWeNeedAResponseFrom();
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;

public: /* package */
    ::rice::pastry::ReadyStrategy* nextReadyStrategy {  };
    virtual void doneProbing();

public:
    virtual void sendTheMessage(::rice::pastry::NodeHandle* nh, bool reply);
    void nodeSetUpdate(::rice::pastry::NodeSetEventSource* set, ::rice::pastry::NodeHandle* handle, bool added) override;
    void update(::java::util::Observable* arg0, ::java::lang::Object* arg) override;
    int32_t delayInterest() override;
    void loopTime(int32_t loopTime) override;
    void destroy() override;

    // Generated
    ConsistentJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy);
    ConsistentJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);
protected:
    ConsistentJoinProtocol(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class ConsistentJoinProtocol_FailedTime;
    friend class ConsistentJoinProtocol_CJPDeserializer;
    friend class ConsistentJoinProtocol_ConsistentJoinProtocol_1;
    friend class ConsistentJoinProtocol_RequestFromEveryoneMsg;
};
