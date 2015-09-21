// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>

struct default_init_tag;

class rice::pastry::commonapi::PastryEndpoint
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::rice::p2p::commonapi::Endpoint
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

public: /* protected */
    ::rice::p2p::commonapi::Application* application {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, bool register_);
    void ctor(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, int32_t address, bool register_);

public: /* package */
    ::rice::p2p::commonapi::rawserialization::MessageDeserializer* appDeserializer {  };

public:
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::NodeHandle* hint) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::Message* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::rawserialization::RawMessage* msg, ::rice::p2p::commonapi::NodeHandle* hint) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::rawserialization::RawMessage* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe) override;
    ::rice::p2p::commonapi::MessageReceipt* route(::rice::p2p::commonapi::Id* key, ::rice::p2p::commonapi::rawserialization::RawMessage* msg, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options) override;

private:
    ::rice::p2p::commonapi::MessageReceipt* routeHelper(::rice::p2p::commonapi::Id* key, PastryEndpointMessage* pm, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options);

public:
    ::rice::p2p::commonapi::CancellableTask* scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay) override;
    ::rice::p2p::commonapi::CancellableTask* scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period) override;
    ::rice::p2p::commonapi::CancellableTask* scheduleMessageAtFixedRate(::rice::p2p::commonapi::Message* msg, int64_t delay, int64_t period) override;
    ::rice::p2p::commonapi::NodeHandleSet* localLookup(::rice::p2p::commonapi::Id* key, int32_t num, bool safe) override;
    ::rice::p2p::commonapi::NodeHandleSet* neighborSet(int32_t num) override;
    ::rice::p2p::commonapi::NodeHandleSet* replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank) override;
    ::rice::p2p::commonapi::NodeHandleSet* replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank, ::rice::p2p::commonapi::NodeHandle* root, ::rice::p2p::commonapi::NodeHandleSet* set) override;
    ::rice::p2p::commonapi::IdRange* range(::rice::p2p::commonapi::NodeHandle* n, int32_t r, ::rice::p2p::commonapi::Id* key, bool cumulative) override;
    ::rice::p2p::commonapi::IdRange* range(::rice::p2p::commonapi::NodeHandle* n, int32_t r, ::rice::p2p::commonapi::Id* key) override;
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    bool enrouteMessage(::rice::pastry::messaging::Message* msg, ::rice::pastry::Id* key, ::rice::pastry::NodeHandle* nextHop, ::rice::pastry::routing::SendOptions* opt) override;
    void leafSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded) override;
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;
    void process(::rice::Executable* task, ::rice::Continuation* command) override;
    ::java::lang::String* getInstance() override;
    ::rice::environment::Environment* getEnvironment() override;
    ::java::lang::String* toString() override;
    void setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) override;
    ::rice::p2p::commonapi::rawserialization::MessageDeserializer* getDeserializer() override;
    ::rice::p2p::commonapi::Id* readId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */ override;
    ::rice::p2p::commonapi::NodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    ::rice::p2p::commonapi::IdRange* readIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    ::rice::p2p::commonapi::NodeHandle* coalesce(::rice::p2p::commonapi::NodeHandle* newHandle) override;
    ::rice::p2p::commonapi::NodeHandleSet* readNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */ override;
    ::java::util::List* networkNeighbors(int32_t num) override;
    void destroy() override;
    int32_t proximity(::rice::p2p::commonapi::NodeHandle* nh) override;
    bool isAlive(::rice::p2p::commonapi::NodeHandle* nh) override;
    virtual int32_t getAppId();

public: /* package */
    bool consistentRouting {  };

public:
    void setConsistentRouting(bool val) override;
    bool deliverWhenNotReady() override;
    bool routingConsistentFor(::rice::p2p::commonapi::Id* id) override;
    void setSendOptions(::java::util::Map* options) override;

    // Generated
    PastryEndpoint(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, bool register_);
    PastryEndpoint(::rice::pastry::PastryNode* pn, ::rice::p2p::commonapi::Application* application, ::java::lang::String* instance, int32_t address, bool register_);
protected:
    PastryEndpoint(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver);
    virtual void connect(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout);
    virtual void register_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryEndpoint_PEDeserializer;
    friend class PastryEndpoint_routeHelper_1;
    friend class PastryEndpoint_routeHelper_2;
    friend class PastryEndpoint_networkNeighbors_3;
};
