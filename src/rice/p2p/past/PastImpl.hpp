// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
typedef ::SubArray< ::rice::Continuation, ::java::lang::ObjectArray > ContinuationArray;
} // rice

struct default_init_tag;

class rice::p2p::past::PastImpl
    : public virtual ::java::lang::Object
    , public virtual Past
    , public virtual ::rice::p2p::commonapi::Application
    , public virtual ::rice::p2p::replication::manager::ReplicationManagerClient
{

public:
    typedef ::java::lang::Object super;
    int32_t MESSAGE_TIMEOUT {  };
    double SUCCESSFUL_INSERT_THRESHOLD {  };

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::persistence::StorageManager* storage {  };
    ::rice::persistence::StorageManager* trash {  };
    ::rice::persistence::Cache* backup {  };
    int32_t replicationFactor {  };
    ::rice::p2p::replication::manager::ReplicationManager* replicaManager {  };
    ::rice::persistence::LockManager* lockManager {  };
    PastPolicy* policy {  };

private:
    int32_t id {  };
    ::java::util::Hashtable* outstanding {  };
    ::java::util::Hashtable* timers {  };

public: /* protected */
    ::rice::p2p::commonapi::IdFactory* factory {  };
    ::java::lang::String* instance {  };

public:
    int32_t inserts {  };
    int32_t lookups {  };
    int32_t fetchHandles {  };
    int32_t other {  };

public: /* protected */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::p2p::past::rawserialization::PastContentDeserializer* contentDeserializer {  };
    ::rice::p2p::past::rawserialization::PastContentHandleDeserializer* contentHandleDeserializer {  };

public:
    ::rice::p2p::past::rawserialization::SocketStrategy* socketStrategy {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance);
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy);
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash);
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, bool useOwnSocket);
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, ::rice::p2p::past::rawserialization::SocketStrategy* strategy);

public:
    ::java::lang::String* toString() override;
    ::rice::environment::Environment* getEnvironment() override;

public: /* protected */
    virtual ::rice::p2p::replication::manager::ReplicationManager* buildReplicationManager(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance);

public:
    virtual ::rice::ContinuationArray* getOutstandingMessages();
    virtual ::rice::p2p::commonapi::Endpoint* getEndpoint();

public: /* protected */
    virtual int32_t getUID();
    virtual ::rice::Continuation* getResponseContinuation(::rice::p2p::past::messaging::PastMessage* msg);
    virtual ::rice::Continuation* getFetchResponseContinuation(::rice::p2p::past::messaging::PastMessage* msg);

public: /* package */
    ::java::util::WeakHashMap* pendingSocketTransactions {  };

private:
    void sendViaSocket(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::past::messaging::PastMessage* m, ::rice::Continuation* c);

public: /* protected */
    virtual void sendRequest(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::messaging::PastMessage* message, ::rice::Continuation* command);
    virtual void sendRequest(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::past::messaging::PastMessage* message, ::rice::Continuation* command);
    virtual void sendRequest(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::messaging::PastMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command);

private:
    void insertPending(int32_t uid, ::rice::p2p::commonapi::CancellableTask* timer, ::rice::Continuation* command);
    ::rice::Continuation* removePending(int32_t uid);
    void handleResponse(::rice::p2p::past::messaging::PastMessage* message);

public: /* protected */
    virtual void getHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command);

private:
    void cache(PastContent* content);

public:
    virtual void cache(PastContent* content, ::rice::Continuation* command);

public: /* protected */
    virtual void doInsert(::rice::p2p::commonapi::Id* id, PastImpl_MessageBuilder* builder, ::rice::Continuation* command, bool useSocket);

public:
    void insert(PastContent* obj, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command) override;
    void lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command) override;
    void lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command) override;
    void fetch(PastContentHandle* handle, ::rice::Continuation* command) override;
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    int32_t getReplicationFactor() override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    void fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command) override;
    void remove(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    virtual ::rice::p2p::commonapi::IdSet* scan();
    bool exists(::rice::p2p::commonapi::Id* id) override;
    void existsInOverlay(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void reInsert(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    virtual ::rice::p2p::replication::Replication* getReplication();
    virtual ::rice::persistence::StorageManager* getStorageManager();
    ::java::lang::String* getInstance() override;
    void setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer) override;
    void setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer) override;

    // Generated
    PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance);
    PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy);
    PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash);
    PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, bool useOwnSocket);
    PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, ::rice::p2p::past::rawserialization::SocketStrategy* strategy);
protected:
    PastImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class PastImpl_PastDeserializer;
    friend class PastImpl_PastImpl_1;
    friend class PastImpl_getResponseContinuation_2;
    friend class PastImpl_getFetchResponseContinuation_3;
    friend class PastImpl_sendViaSocket_4;
    friend class PastImpl_getHandles_5;
    friend class PastImpl_doInsert_6;
    friend class PastImpl_doInsert_6_receiveResult_6_1;
    friend class PastImpl_insert_7;
    friend class PastImpl_insert_8;
    friend class PastImpl_insert_8_receiveResult_8_1;
    friend class PastImpl_lookup_9;
    friend class PastImpl_lookup_9_receiveResult_9_1;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1;
    friend class PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1_receiveResult_9_1_2_1_1;
    friend class PastImpl_lookupHandles_10;
    friend class PastImpl_lookupHandles_10_receiveResult_10_1;
    friend class PastImpl_deliver_11;
    friend class PastImpl_deliver_11_receiveResult_11_1;
    friend class PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1;
    friend class PastImpl_deliver_12;
    friend class PastImpl_deliver_13;
    friend class PastImpl_fetch_14;
    friend class PastImpl_remove_15;
    friend class PastImpl_remove_15_receiveResult_15_1;
    friend class PastImpl_existsInOverlay_16;
    friend class PastImpl_reInsert_17;
    friend class PastImpl_reInsert_17_receiveResult_17_1;
    friend class PastImpl_MessageBuilder;
};
