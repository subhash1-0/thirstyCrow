// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/replication/Replication.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/Destructable.hpp>

struct default_init_tag;

class rice::p2p::replication::ReplicationImpl
    : public virtual ::java::lang::Object
    , public virtual Replication
    , public virtual ::rice::p2p::commonapi::Application
    , public virtual ::rice::Destructable
{

public:
    typedef ::java::lang::Object super;
    int32_t MAINTENANCE_INTERVAL {  };
    int32_t MAX_KEYS_IN_MESSAGE {  };

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::commonapi::NodeHandle* handle {  };
    ::rice::p2p::commonapi::IdFactory* factory {  };
    ReplicationClient* client {  };
    ReplicationPolicy* policy {  };
    int32_t replicationFactor {  };
    ::java::lang::String* instance {  };

public: /* package */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance);
    void ctor(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance, ReplicationPolicy* policy);

public:
    static ::rice::p2p::commonapi::IdSet* merge(::rice::p2p::commonapi::IdFactory* factory, ::rice::p2p::commonapi::IdSet* a, ::rice::p2p::commonapi::IdSet* b);

public: /* protected */
    virtual ::rice::p2p::commonapi::IdRange* getTotalRange();

private:
    void updateClient();

public:
    void replicate() override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;

public: /* protected */
    bool destroyed {  };

public:
    void destroy() override;

    // Generated
    ReplicationImpl(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance);
    ReplicationImpl(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance, ReplicationPolicy* policy);
protected:
    ReplicationImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationImpl_ReplicationImpl_1;
    friend class ReplicationImpl_replicate_2;
    friend class ReplicationImpl_replicate_2_receiveResult_2_1;
    friend class ReplicationImpl_deliver_3;
    friend class ReplicationImpl_deliver_4;
    friend class ReplicationImpl_BloomFilterExecutable;
};
