// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/maintenance/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/maintenance/MaintainableScribe.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <java/util/Observer.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::Topic, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > TopicArray;
        } // scribe
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::scribe::ScribeImpl
    : public virtual ::java::lang::Object
    , public virtual Scribe
    , public virtual ::rice::p2p::scribe::maintenance::MaintainableScribe
    , public virtual ::rice::p2p::commonapi::Application
    , public virtual ::java::util::Observer
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t INFO_2 { int32_t(850) };
    int32_t MAINTENANCE_INTERVAL {  };
    int32_t MESSAGE_TIMEOUT {  };
    ::java::util::Hashtable* topicManagers {  };

public: /* protected */
    ScribePolicy* policy {  };

private:
    ::rice::p2p::scribe::maintenance::ScribeMaintenancePolicy* maintenancePolicy {  };

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::p2p::commonapi::NodeHandle* localHandle {  };

private:
    ::java::util::HashMap* subscribeLostMessages {  };
    int32_t id {  };

public: /* package */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };

private:
    ::java::lang::String* instance {  };

public: /* protected */
    ::rice::p2p::commonapi::Node* node {  };

public:
    ::java::util::HashMap* allChildren {  };
    ::java::util::HashMap* allParents {  };
    ::java::util::Set* roots {  };
    ::java::util::Set* pending {  };

public: /* package */
    ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* contentDeserializer {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance);
    void ctor(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance);
    void ctor(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance, ::rice::p2p::scribe::maintenance::ScribeMaintenancePolicy* maintenancePolicy);

public:
    ::rice::environment::Environment* getEnvironment() override;
    ScribePolicy* getPolicy() override;
    void setPolicy(ScribePolicy* policy) override;
    virtual ::rice::p2p::commonapi::Id* getId();
    int32_t numChildren(Topic* topic) override;
    bool containsTopic(Topic* topic) override;
    ::java::util::Collection* getClients(Topic* topic) override;
    ::java::util::Collection* getClientsByTopic(Topic* topic) override;

public: /* protected */
    virtual ::java::util::Collection* getSimpleClients(::java::util::Collection* multi);

private:
    ::java::util::Map* clientConverters {  };

public: /* protected */
    virtual ScribeMultiClient* getMultiClient(ScribeClient* client);

public:
    ::rice::p2p::commonapi::NodeHandleArray* getChildren(Topic* topic) override;
    ::java::util::Collection* getChildrenOfTopic(Topic* topic) override;
    ::rice::p2p::commonapi::NodeHandle* getParent(Topic* topic) override;
    bool isRoot(Topic* topic) override;
    ::rice::p2p::commonapi::NodeHandle* getRoot(Topic* topic) override;

private:
    void sendSubscribe(Topic* topic, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint);
    void sendSubscribe(::java::util::List* topics, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint);
    ::java::util::HashMap* buildManifests(::java::util::List* topics);

public: /* protected */
    virtual void ackMessageReceived(::rice::p2p::scribe::messaging::SubscribeAckMessage* message);

private:
    void failedMessageReceived(::rice::p2p::scribe::messaging::SubscribeFailedMessage* message);
    void lostMessageReceived(::rice::p2p::scribe::messaging::SubscribeLostMessage* message);

public:
    bool containsChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    virtual void subscribe(::java::util::Collection* topics);
    virtual void subscribe(Topic* topic, ScribeMultiClient* client);
    void subscribe(Topic* topic, ScribeClient* client) override;
    void subscribe(Topic* topic, ScribeClient* client, ScribeContent* content) override;
    void subscribe(Topic* topic, ScribeClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void subscribe(Topic* topic, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) override;
    void subscribe(Topic* topic, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void subscribe(::java::util::Collection* theTopics, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void subscribe(::java::util::Collection* theTopics, ScribeClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void subscribe(Topic* topic, ScribeMultiClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void subscribe(Topic* topic, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void subscribe(::java::util::Collection* theTopics, ScribeMultiClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void subscribe(::java::util::Collection* theTopics, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;

public: /* protected */
    virtual ::rice::p2p::scribe::rawserialization::RawScribeContent* toRawScribeContent(ScribeContent* content);
    virtual void doSubscribe(::java::util::Collection* theTopics, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint);

public:
    void unsubscribe(Topic* topic, ScribeClient* client) override;
    void unsubscribe(Topic* topic, ScribeMultiClient* client) override;
    void unsubscribe(::java::util::Collection* topicsToUnsubscribe, ScribeMultiClient* client) override;
    void publish(Topic* topic, ScribeContent* content) override;
    void publish(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) override;
    void anycast(Topic* topic, ScribeContent* content) override;
    void anycast(Topic* topic, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void anycast(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) override;
    void anycast(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) override;
    void addChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void setParent(Topic* topic, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::List* pathToRoot) override;
    virtual ScribeImpl_TopicManager* getTopicManager(Topic* topic);

public: /* protected */
    virtual bool addChildHelper(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child);

public:
    void removeChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;

public: /* protected */
    virtual void removeChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child, bool sendDrop);

public:
    ::java::util::Collection* getTopicsByClient(ScribeClient* client) override;
    ::java::util::Collection* getTopicsByClient(ScribeMultiClient* client) override;
    TopicArray* getTopics(ScribeClient* client) override;

public: /* protected */
    virtual void recvAnycastFail(Topic* topic, ::rice::p2p::commonapi::NodeHandle* failedAtNode, ScribeContent* content);
    virtual void addToAllChildren(Topic* t, ::rice::p2p::commonapi::NodeHandle* child);
    virtual void removeFromAllChildren(Topic* t, ::rice::p2p::commonapi::NodeHandle* child);
    virtual void addToAllParents(Topic* t, ::rice::p2p::commonapi::NodeHandle* parent);
    virtual void removeFromAllParents(Topic* t, ::rice::p2p::commonapi::NodeHandle* parent);

public:
    virtual bool allParentsContains(Topic* t, ::rice::p2p::commonapi::NodeHandle* parent);
    virtual bool allParentsContainsParent(::rice::p2p::commonapi::NodeHandle* parent);
    virtual void printAllParentsDataStructure();
    virtual void printAllChildrenDataStructure();
    ::java::util::Collection* getTopicsByParent(::rice::p2p::commonapi::NodeHandle* parent) override;
    ::java::util::Collection* getTopicsByChild(::rice::p2p::commonapi::NodeHandle* child) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;

public: /* protected */
    virtual bool handleForwardSubscribeMessage(::rice::p2p::scribe::messaging::SubscribeMessage* sMessage);

public:
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;

public: /* protected */
    virtual ::rice::p2p::scribe::rawserialization::RawScribeContent* convert(ScribeContent* content);

public:
    void update(::java::util::Observable* o, ::java::lang::Object* arg) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    ::java::lang::String* toString() override;
    void destroy() override;
    ::rice::p2p::commonapi::Endpoint* getEndpoint() override;
    void setContentDeserializer(::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* deserializer) override;
    ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* getContentDeserializer() override;
    ::java::util::Collection* getTopics() override;
    ::java::util::List* getPathToRoot(Topic* topic) override;

    // Generated
    ScribeImpl(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance);
    ScribeImpl(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance);
    ScribeImpl(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance, ::rice::p2p::scribe::maintenance::ScribeMaintenancePolicy* maintenancePolicy);
protected:
    ScribeImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class ScribeImpl_ScribeImpl_1;
    friend class ScribeImpl_ScribeClientConverter;
    friend class ScribeImpl_TopicManager;
    friend class ScribeImpl_destroy_2;
};
