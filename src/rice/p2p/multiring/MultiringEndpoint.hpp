// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringEndpoint.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringEndpoint
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Endpoint
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    MultiringNode* node {  };
    ::rice::p2p::commonapi::Application* application {  };
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
protected:
    void ctor(MultiringNode* node, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::commonapi::Application* application);

public:
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options) override;
    ::rice::p2p::commonapi::NodeHandleSet* localLookup(::rice::p2p::commonapi::Id* id, int32_t num, bool safe) override;
    ::rice::p2p::commonapi::NodeHandleSet* neighborSet(int32_t num) override;
    ::rice::p2p::commonapi::NodeHandleSet* replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank) override;
    ::rice::p2p::commonapi::NodeHandleSet* replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank, ::rice::p2p::commonapi::NodeHandle* root, ::rice::p2p::commonapi::NodeHandleSet* set) override;
    ::rice::p2p::commonapi::IdRange* range(::rice::p2p::commonapi::NodeHandle* handle, int32_t rank, ::rice::p2p::commonapi::Id* lkey) override;
    ::rice::p2p::commonapi::IdRange* range(::rice::p2p::commonapi::NodeHandle* handle, int32_t rank, ::rice::p2p::commonapi::Id* lkey, bool cumulative) override;
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    ::rice::p2p::commonapi::CancellableTask* scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay) override;
    ::rice::p2p::commonapi::CancellableTask* scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period) override;
    ::rice::p2p::commonapi::CancellableTask* scheduleMessageAtFixedRate(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period) override;
    ::java::util::List* networkNeighbors(int32_t num) override;
    void process(::rice::Executable* task, ::rice::Continuation* command) override;

public: /* protected */
    virtual void deliver(RingId* id, ::rice::p2p::commonapi::Message* target);

public:
    ::java::lang::String* getInstance() override;
    ::rice::environment::Environment* getEnvironment() override;
    void connect(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout) override;
    void accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver) override;
    void setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) override;
    ::rice::p2p::commonapi::rawserialization::MessageDeserializer* getDeserializer() override;
    ::rice::p2p::commonapi::Id* readId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */ override;
    ::rice::p2p::commonapi::NodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    ::rice::p2p::commonapi::IdRange* readIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    ::rice::p2p::commonapi::NodeHandle* coalesce(::rice::p2p::commonapi::NodeHandle* handle) override;
    ::rice::p2p::commonapi::NodeHandleSet* readNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */ override;
    ::java::lang::String* toString() override;
    void register_() override;
    int32_t proximity(::rice::p2p::commonapi::NodeHandle* nh) override;
    bool isAlive(::rice::p2p::commonapi::NodeHandle* nh) override;
    void setConsistentRouting(bool val) override;
    bool routingConsistentFor(::rice::p2p::commonapi::Id* id) override;
    void setSendOptions(::java::util::Map* options) override;

    // Generated

public: /* protected */
    MultiringEndpoint(MultiringNode* node, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::commonapi::Application* application);
protected:
    MultiringEndpoint(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
