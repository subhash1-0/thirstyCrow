// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/replication/manager/ReplicationManager.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::ReplicationManagerImpl
    : public virtual ::java::lang::Object
    , public virtual ReplicationManager
    , public virtual ::rice::p2p::replication::ReplicationClient
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;
    int32_t FETCH_DELAY {  };
    int32_t TIMEOUT_DELAY {  };
    int32_t NUM_DELETE_AT_ONCE {  };

public: /* protected */
    ::rice::p2p::commonapi::IdFactory* factory {  };
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::replication::ReplicationImpl* replication {  };
    ReplicationManagerClient* client {  };
    ReplicationManagerImpl_ReplicationManagerHelper* helper {  };
    ReplicationManagerImpl_ReplicationManagerDeleter* deleter {  };
    ::java::lang::String* instance {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance);
    void ctor(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance, ::rice::p2p::replication::ReplicationPolicy* policy);

public: /* protected */
    virtual ::rice::p2p::commonapi::IdSet* clone(::rice::p2p::commonapi::IdSet* keySet);
    virtual void informClient(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint);
    virtual void scheduleNext();

public:
    void fetch(::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void setRange(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    ::rice::p2p::replication::Replication* getReplication() override;

    // Generated
    ReplicationManagerImpl(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance);
    ReplicationManagerImpl(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance, ::rice::p2p::replication::ReplicationPolicy* policy);
protected:
    ReplicationManagerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* protected */
    virtual ::java::lang::Object* clone();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerImpl_informClient_1;
    friend class ReplicationManagerImpl_ReplicationManagerHelper;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1;
    friend class ReplicationManagerImpl_ReplicationManagerDeleter_go_1_receiveResult_1_1;
};
