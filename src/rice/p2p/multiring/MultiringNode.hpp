// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNode.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringNode
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Node
    , public virtual ::rice::p2p::scribe::ScribeClient
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Node* node {  };
    ::rice::p2p::commonapi::Id* ringId {  };
    ::rice::p2p::scribe::Scribe* scribe {  };
    MultiringNodeCollection* collection {  };
    ::java::util::Hashtable* endpoints {  };
    MultiringIdFactory* factory {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node);
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node, MultiringNode* existing);

public:
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    ::rice::p2p::commonapi::Endpoint* registerApplication(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance) override;
    ::rice::p2p::commonapi::Endpoint* buildEndpoint(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance) override;
    ::rice::p2p::commonapi::Id* getId() override;
    virtual ::rice::p2p::commonapi::Id* getRingId();
    virtual ::rice::p2p::commonapi::Id* getNodeId();
    virtual ::rice::p2p::commonapi::Node* getNode();
    virtual MultiringNodeCollection* getCollection();
    ::rice::p2p::commonapi::IdFactory* getIdFactory() override;

public: /* protected */
    virtual void nodeAdded(::rice::p2p::commonapi::Id* otherRingId);

public: /* package */
    virtual ::rice::p2p::commonapi::MessageReceipt* route(RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options);

private:
    ::rice::p2p::commonapi::Id* getTarget(RingId* id);
    ::rice::p2p::commonapi::Id* makeTarget(RingId* id, int32_t length);

public:
    bool anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void subscribeFailed(::rice::p2p::scribe::Topic* topic) override;
    ::java::lang::String* toString() override;
    ::rice::environment::Environment* getEnvironment() override;
    ::java::lang::String* printRouteState() override;

    // Generated
    MultiringNode(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node);
    MultiringNode(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node, MultiringNode* existing);
protected:
    MultiringNode(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiringNode_MultiringNode_1;
    friend class MultiringNode_route_2;
};
