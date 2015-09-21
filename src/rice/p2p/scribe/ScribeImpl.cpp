// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java
#include <rice/p2p/scribe/ScribeImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Set.hpp>
#include <java/util/Vector.hpp>
#include <java/util/WeakHashMap.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/ScribeImpl_ScribeImpl_1.hpp>
#include <rice/p2p/scribe/ScribeImpl_destroy_2.hpp>
#include <rice/p2p/scribe/ScribeImpl_ScribeClientConverter.hpp>
#include <rice/p2p/scribe/ScribeImpl_TopicManager.hpp>
#include <rice/p2p/scribe/ScribeMultiClient.hpp>
#include <rice/p2p/scribe/ScribePolicy_DefaultScribePolicy.hpp>
#include <rice/p2p/scribe/ScribePolicy.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/javaserialized/JavaScribeContentDeserializer.hpp>
#include <rice/p2p/scribe/maintenance/ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy.hpp>
#include <rice/p2p/scribe/maintenance/ScribeMaintenancePolicy.hpp>
#include <rice/p2p/scribe/messaging/AnycastFailureMessage.hpp>
#include <rice/p2p/scribe/messaging/AnycastMessage.hpp>
#include <rice/p2p/scribe/messaging/DropMessage.hpp>
#include <rice/p2p/scribe/messaging/MaintenanceMessage.hpp>
#include <rice/p2p/scribe/messaging/PublishMessage.hpp>
#include <rice/p2p/scribe/messaging/PublishRequestMessage.hpp>
#include <rice/p2p/scribe/messaging/ScribeMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeAckMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeFailedMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeLostMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeMessage.hpp>
#include <rice/p2p/scribe/messaging/UnsubscribeMessage.hpp>
#include <rice/p2p/scribe/rawserialization/JavaSerializedScribeContent.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>
#include <rice/p2p/scribe/rawserialization/ScribeContentDeserializer.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::p2p::scribe::ScribeImpl::ScribeImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::ScribeImpl::ScribeImpl(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance) 
    : ScribeImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,instance);
}

rice::p2p::scribe::ScribeImpl::ScribeImpl(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance) 
    : ScribeImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,policy,instance);
}

rice::p2p::scribe::ScribeImpl::ScribeImpl(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance, ::rice::p2p::scribe::maintenance::ScribeMaintenancePolicy* maintenancePolicy) 
    : ScribeImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,policy,instance,maintenancePolicy);
}

void rice::p2p::scribe::ScribeImpl::init()
{
    roots = new ::java::util::HashSet();
    pending = new ::java::util::HashSet();
    clientConverters = new ::java::util::WeakHashMap();
}

constexpr int32_t rice::p2p::scribe::ScribeImpl::INFO_2;

void rice::p2p::scribe::ScribeImpl::ctor(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance)
{
    ctor(node, new ScribePolicy_DefaultScribePolicy(npc(node)->getEnvironment()), instance);
}

void rice::p2p::scribe::ScribeImpl::ctor(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance)
{
    ctor(node, policy, instance, new ::rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy(npc(node)->getEnvironment()));
}

void rice::p2p::scribe::ScribeImpl::ctor(::rice::p2p::commonapi::Node* node, ScribePolicy* policy, ::java::lang::String* instance, ::rice::p2p::scribe::maintenance::ScribeMaintenancePolicy* maintenancePolicy)
{
    super::ctor();
    init();
    this->environment = npc(node)->getEnvironment();
    this->node = node;
    logger = npc(npc(environment)->getLogManager())->getLogger(ScribeImpl::class_(), instance);
    auto p = npc(environment)->getParameters();
    MAINTENANCE_INTERVAL = npc(p)->getInt(u"p2p_scribe_maintenance_interval"_j);
    MESSAGE_TIMEOUT = npc(p)->getInt(u"p2p_scribe_message_timeout"_j);
    this->allChildren = new ::java::util::HashMap();
    this->allParents = new ::java::util::HashMap();
    this->instance = instance;
    this->endpoint = npc(node)->buildEndpoint(this, instance);
    this->contentDeserializer = new ::rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer();
    npc(this->endpoint)->setDeserializer(new ScribeImpl_ScribeImpl_1(this));
    this->topicManagers = new ::java::util::Hashtable();
    this->subscribeLostMessages = new ::java::util::HashMap();
    this->policy = policy;
    this->maintenancePolicy = maintenancePolicy;
    this->localHandle = npc(endpoint)->getLocalNodeHandle();
    this->id = ::java::lang::Integer::MIN_VALUE;
    npc(endpoint)->register_();
    npc(endpoint)->scheduleMessage(new ::rice::p2p::scribe::messaging::MaintenanceMessage(), npc(npc(environment)->getRandomSource())->nextInt(MAINTENANCE_INTERVAL), MAINTENANCE_INTERVAL);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(u"Starting up Scribe"_j);

}

rice::environment::Environment* rice::p2p::scribe::ScribeImpl::getEnvironment()
{
    return environment;
}

rice::p2p::scribe::ScribePolicy* rice::p2p::scribe::ScribeImpl::getPolicy()
{
    return policy;
}

void rice::p2p::scribe::ScribeImpl::setPolicy(ScribePolicy* policy)
{
    this->policy = policy;
}

rice::p2p::commonapi::Id* rice::p2p::scribe::ScribeImpl::getId()
{
    return npc(endpoint)->getId();
}

int32_t rice::p2p::scribe::ScribeImpl::numChildren(Topic* topic)
{
    if(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))) != nullptr) {
        return npc((java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))))))->numChildren();
    }
    return 0;
}

bool rice::p2p::scribe::ScribeImpl::containsTopic(Topic* topic)
{
    if(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))) != nullptr) {
        return true;
    } else {
        return false;
    }
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getClients(Topic* topic)
{
    auto manager = java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic)));
    if(manager != nullptr) {
        return getSimpleClients(npc(manager)->getClients());
    }
    return new ::java::util::ArrayList();
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getClientsByTopic(Topic* topic)
{
    auto manager = java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic)));
    if(manager != nullptr) {
        return npc(manager)->getClients();
    }
    return new ::java::util::ArrayList();
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getSimpleClients(::java::util::Collection* multi)
{
    auto ret = new ::java::util::ArrayList(npc(multi)->size());
    for (auto _i = npc(multi)->iterator(); _i->hasNext(); ) {
        ScribeMultiClient* client = java_cast< ScribeMultiClient* >(_i->next());
        {
            if(dynamic_cast< ScribeImpl_ScribeClientConverter* >(client) != nullptr) {
                auto theClient = java_cast< ScribeClient* >(npc(java_cast< ::java::lang::ref::WeakReference* >(npc((java_cast< ScribeImpl_ScribeClientConverter* >(client)))->client))->get());
                if(theClient != nullptr) {
                    npc(ret)->add(static_cast< ::java::lang::Object* >(theClient));
                }
            } else {
                npc(ret)->add(static_cast< ::java::lang::Object* >(client));
            }
        }
    }
    return ret;
}

rice::p2p::scribe::ScribeMultiClient* rice::p2p::scribe::ScribeImpl::getMultiClient(ScribeClient* client)
{
    if(dynamic_cast< ScribeMultiClient* >(client) != nullptr) {
        return java_cast< ScribeMultiClient* >(client);
    } else {
        {
            synchronized synchronized_0(clientConverters);
            {
                auto scc = java_cast< ScribeImpl_ScribeClientConverter* >(npc(clientConverters)->get(client));
                if(scc == nullptr || java_cast< ScribeClient* >(npc(npc(scc)->client)->get()) == nullptr) {
                    scc = new ScribeImpl_ScribeClientConverter(client);
                    npc(clientConverters)->put(client, scc);
                }
                return scc;
            }
        }
    }
}

rice::p2p::commonapi::NodeHandleArray* rice::p2p::scribe::ScribeImpl::getChildren(Topic* topic)
{
    if(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))) != nullptr) {
        return java_cast< ::rice::p2p::commonapi::NodeHandleArray* >(npc(npc((java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))))))->getChildren())->toArray_(new ::rice::p2p::commonapi::NodeHandleArray(int32_t(0))));
    }
    return new ::rice::p2p::commonapi::NodeHandleArray(int32_t(0));
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getChildrenOfTopic(Topic* topic)
{
    auto manager = java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic)));
    if(manager != nullptr) {
        return npc(manager)->getChildren();
    }
    return new ::java::util::ArrayList(int32_t(0));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::ScribeImpl::getParent(Topic* topic)
{
    if(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))) != nullptr) {
        return npc((java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))))))->getParent();
    }
    return nullptr;
}

bool rice::p2p::scribe::ScribeImpl::isRoot(Topic* topic)
{
    auto set = npc(endpoint)->replicaSet(npc(topic)->getId(), 1);
    if(npc(set)->size() == 0)
        return false;
    else
        return npc(npc(npc(set)->getHandle(int32_t(0)))->getId())->equals(npc(endpoint)->getId());
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::ScribeImpl::getRoot(Topic* topic)
{
    auto set = npc(endpoint)->replicaSet(npc(topic)->getId(), 1);
    if(npc(set)->size() == 0)
        return nullptr;
    else
        return npc(set)->getHandle(int32_t(0));
}

void rice::p2p::scribe::ScribeImpl::sendSubscribe(Topic* topic, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    sendSubscribe(::java::util::Collections::singletonList(topic), client, content, hint);
}

void rice::p2p::scribe::ScribeImpl::sendSubscribe(::java::util::List* topics, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    npc(pending)->addAll(static_cast< ::java::util::Collection* >(topics));
    int32_t theId;
    {
        synchronized synchronized_1(this);
        {
            id++;
            if(id == MAINTENANCE_ID)
                id++;

            theId = id;
        }
    }
    if(npc(topics)->size() > 1) {
        ::java::util::Collections::sort(topics);
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendSubscribe("_j)->append(static_cast< ::java::lang::Object* >(topics))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(client))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(content))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(hint))
            ->append(u") theId:"_j)
            ->append(theId)->toString());

    auto slm = new ::rice::p2p::scribe::messaging::SubscribeLostMessage(localHandle, topics, theId, client);
    auto task = npc(endpoint)->scheduleMessage(slm, MESSAGE_TIMEOUT);
    npc(slm)->putTask(task);
    npc(subscribeLostMessages)->put(::java::lang::Integer::valueOf(theId), static_cast< ::java::lang::Object* >(slm));
    if(hint == nullptr) {
        auto manifest = buildManifests(topics);
        for (auto _i = npc(npc(manifest)->keySet())->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::NodeHandle* nextHop = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
            {
                auto theTopics = java_cast< ::java::util::List* >(npc(manifest)->get(static_cast< ::java::lang::Object* >(nextHop)));
                auto msg = new ::rice::p2p::scribe::messaging::SubscribeMessage(localHandle, theTopics, theId, convert(npc(policy)->divideContent(theTopics, content)));
                auto set = npc(endpoint)->replicaSet(npc(npc(msg)->getTopic())->getId(), 2);
                if(npc(set)->size() > 1 && npc(set)->getHandle(int32_t(1)) == localHandle) {
                    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(msg), nextHop);
                } else {
                    npc(endpoint)->route(npc(npc(msg)->getTopic())->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(msg), nextHop);
                }
            }
        }
    } else {
        auto msg = new ::rice::p2p::scribe::messaging::SubscribeMessage(localHandle, topics, theId, content);
        auto set = npc(endpoint)->replicaSet(npc(npc(msg)->getTopic())->getId(), 2);
        if(npc(set)->size() > 1 && npc(set)->getHandle(int32_t(1)) == localHandle) {
            npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(msg), hint);
        } else {
            npc(endpoint)->route(npc(npc(msg)->getTopic())->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(msg), hint);
        }
    }
}

java::util::HashMap* rice::p2p::scribe::ScribeImpl::buildManifests(::java::util::List* topics)
{
    auto manifest = new ::java::util::HashMap();
    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        Topic* topic = java_cast< Topic* >(_i->next());
        {
            auto handleSet = npc(endpoint)->replicaSet(npc(topic)->getId(), 1);
            if(npc(handleSet)->size() == 0) {
                handleSet = npc(endpoint)->localLookup(npc(topic)->getId(), 1, false);
            }
            ::rice::p2p::commonapi::NodeHandle* handle = nullptr;
            if(npc(handleSet)->size() > 0)
                handle = npc(handleSet)->getHandle(int32_t(0));

            if(handle == nullptr) {
                handle = this->localHandle;
                if(!isRoot(topic)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING) {
                        npc(logger)->log(::java::lang::StringBuilder().append(u"buildManifests("_j)->append(static_cast< ::java::lang::Object* >(topics))
                            ->append(u") did not receive a next hop for topic "_j)
                            ->append(static_cast< ::java::lang::Object* >(topic))
                            ->append(u" but we are not the root of the topic. isRoot = "_j)
                            ->append(isRoot(topic))->toString());
                        npc(logger)->log(::java::lang::StringBuilder().append(u"handle set:"_j)->append(static_cast< ::java::lang::Object* >(handleSet))->toString());
                        npc(logger)->log(npc(node)->printRouteState());
                    }
                }
            }
            auto theTopics = java_cast< ::java::util::List* >(npc(manifest)->get(static_cast< ::java::lang::Object* >(handle)));
            if(theTopics == nullptr) {
                theTopics = new ::java::util::ArrayList();
                npc(manifest)->put(static_cast< ::java::lang::Object* >(handle), static_cast< ::java::lang::Object* >(theTopics));
            }
            npc(theTopics)->add(static_cast< ::java::lang::Object* >(topic));
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        npc(logger)->log(u"buildManifest()"_j);
        for (auto _i = npc(npc(manifest)->keySet())->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::NodeHandle* node = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
            {
                npc(logger)->log(::java::lang::StringBuilder().append(u"  "_j)->append(static_cast< ::java::lang::Object* >(node))
                    ->append(u" "_j)
                    ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::util::List* >(npc(manifest)->get(static_cast< ::java::lang::Object* >(node)))))->toString());
            }
        }
    }
    return manifest;
}

void rice::p2p::scribe::ScribeImpl::ackMessageReceived(::rice::p2p::scribe::messaging::SubscribeAckMessage* message)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"ackMessageReceived("_j)->append(static_cast< ::java::lang::Object* >(message))
            ->append(u")"_j)->toString());

    auto slm = java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(npc(subscribeLostMessages)->get(::java::lang::Integer::valueOf(npc(message)->getId())));
    if(slm == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"ackMessageReceived("_j)->append(static_cast< ::java::lang::Object* >(message))
                ->append(u") for unknown id"_j)->toString());

    } else {
        auto multiClient = npc(slm)->getClient();
        if(multiClient != nullptr)
            npc(multiClient)->subscribeSuccess(npc(message)->getTopics());

        if(npc(slm)->topicsAcked(npc(message)->getTopics())) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
                npc(logger)->log(::java::lang::StringBuilder().append(u"Removing client "_j)->append(static_cast< ::java::lang::Object* >(npc(slm)->getClient()))
                    ->append(u" from list of outstanding for ack "_j)
                    ->append(npc(message)->getId())->toString());
            }
            npc(java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(npc(subscribeLostMessages)->remove(::java::lang::Integer::valueOf(npc(message)->getId()))))->cancel();
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
                auto topics = npc(slm)->getTopics();
                auto numTopics = npc(topics)->size();
                npc(logger)->log(::java::lang::StringBuilder().append(u"Still waiting for SubscribeAck from "_j)->append((numTopics == 1 ? ::java::lang::StringBuilder().append(u" topic "_j)->append(static_cast< ::java::lang::Object* >(java_cast< Topic* >(npc(npc(topics)->iterator())->next())))
                    ->append(u"."_j)->toString() : ::java::lang::StringBuilder().append(numTopics)->append(u" topics."_j)->toString()))->toString());
            }
        }
    }
}

void rice::p2p::scribe::ScribeImpl::failedMessageReceived(::rice::p2p::scribe::messaging::SubscribeFailedMessage* message)
{
    auto slm = java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(npc(subscribeLostMessages)->get(::java::lang::Integer::valueOf(npc(message)->getId())));
    if(slm == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"received unexpected subscribe failed message, ignoring:"_j)->append(static_cast< ::java::lang::Object* >(message))->toString());

        return;
    }
    if(npc(slm)->topicsAcked(npc(message)->getTopics())) {
        npc(java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(npc(subscribeLostMessages)->remove(::java::lang::Integer::valueOf(npc(message)->getId()))))->cancel();
    }
    auto client = npc(slm)->getClient();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Telling client "_j)->append(static_cast< ::java::lang::Object* >(client))
            ->append(u" about FAILURE for outstanding ack "_j)
            ->append(npc(message)->getId())->toString());

    if(client != nullptr) {
        npc(client)->subscribeFailed(static_cast< ::java::util::Collection* >(npc(message)->getTopics()));
    } else {
        npc(maintenancePolicy)->subscribeFailed(this, npc(message)->getTopics());
    }
}

void rice::p2p::scribe::ScribeImpl::lostMessageReceived(::rice::p2p::scribe::messaging::SubscribeLostMessage* message)
{
    auto slm = java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(npc(subscribeLostMessages)->remove(::java::lang::Integer::valueOf(npc(message)->getId())));
    auto client = npc(slm)->getClient();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Telling client "_j)->append(static_cast< ::java::lang::Object* >(client))
            ->append(u" about LOSS for outstanding ack "_j)
            ->append(npc(message)->getId())->toString());

    auto failedTopics = new ::java::util::ArrayList();
    for (auto _i = npc(npc(message)->getTopics())->iterator(); _i->hasNext(); ) {
        Topic* topic = java_cast< Topic* >(_i->next());
        {
            auto parent = getParent(topic);
            if(!isRoot(topic) && (parent == nullptr))
                npc(failedTopics)->add(static_cast< ::java::lang::Object* >(topic));

        }
    }
    if(!npc(failedTopics)->isEmpty()) {
        if(client != nullptr) {
            npc(client)->subscribeFailed(static_cast< ::java::util::Collection* >(failedTopics));
        } else {
            npc(maintenancePolicy)->subscribeFailed(this, failedTopics);
        }
    }
}

bool rice::p2p::scribe::ScribeImpl::containsChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
    if(manager == nullptr) {
        return false;
    } else {
        return npc(manager)->containsChild(child);
    }
}

void rice::p2p::scribe::ScribeImpl::subscribe(::java::util::Collection* topics)
{
    doSubscribe(topics, nullptr, nullptr, nullptr);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeMultiClient* client)
{
    doSubscribe(::java::util::Collections::singletonList(topic), client, nullptr, nullptr);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeClient* client)
{
    doSubscribe(::java::util::Collections::singletonList(topic), getMultiClient(client), nullptr, nullptr);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeClient* client, ScribeContent* content)
{
    doSubscribe(::java::util::Collections::singletonList(topic), getMultiClient(client), toRawScribeContent(content), nullptr);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(::java::util::Collections::singletonList(topic), getMultiClient(client), toRawScribeContent(content), hint);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    doSubscribe(::java::util::Collections::singletonList(topic), getMultiClient(client), content, nullptr);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(::java::util::Collections::singletonList(topic), getMultiClient(client), content, hint);
}

void rice::p2p::scribe::ScribeImpl::subscribe(::java::util::Collection* theTopics, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(theTopics, getMultiClient(client), content, hint);
}

void rice::p2p::scribe::ScribeImpl::subscribe(::java::util::Collection* theTopics, ScribeClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(theTopics, getMultiClient(client), toRawScribeContent(content), hint);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeMultiClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(::java::util::Collections::singletonList(topic), client, toRawScribeContent(content), hint);
}

void rice::p2p::scribe::ScribeImpl::subscribe(Topic* topic, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(::java::util::Collections::singletonList(topic), client, content, hint);
}

void rice::p2p::scribe::ScribeImpl::subscribe(::java::util::Collection* theTopics, ScribeMultiClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(theTopics, client, toRawScribeContent(content), hint);
}

void rice::p2p::scribe::ScribeImpl::subscribe(::java::util::Collection* theTopics, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    doSubscribe(theTopics, client, content, hint);
}

rice::p2p::scribe::rawserialization::RawScribeContent* rice::p2p::scribe::ScribeImpl::toRawScribeContent(ScribeContent* content)
{
    return dynamic_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) != nullptr ? java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) : static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(content));
}

void rice::p2p::scribe::ScribeImpl::doSubscribe(::java::util::Collection* theTopics, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Subscribing client "_j)->append(static_cast< ::java::lang::Object* >(client))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(theTopics))
            ->append(u"."_j)->toString());

    ::java::util::List* toSubscribe = new ::java::util::ArrayList();
    ::java::util::List* alreadySubscribed = new ::java::util::ArrayList();
    {
        synchronized synchronized_2(topicManagers);
        {
            for (auto _i = npc(theTopics)->iterator(); _i->hasNext(); ) {
                Topic* topic = java_cast< Topic* >(_i->next());
                {
                    auto manager = java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic)));
                    if(manager == nullptr) {
                        manager = new ScribeImpl_TopicManager(this, topic);
                        npc(topicManagers)->put(static_cast< ::java::lang::Object* >(topic), static_cast< ::java::lang::Object* >(manager));
                        npc(toSubscribe)->add(static_cast< ::java::lang::Object* >(topic));
                    } else {
                        if((npc(manager)->getParent() == nullptr) && (!isRoot(topic))) {
                            npc(toSubscribe)->add(static_cast< ::java::lang::Object* >(topic));
                        } else {
                            npc(alreadySubscribed)->add(static_cast< ::java::lang::Object* >(topic));
                        }
                    }
                    npc(manager)->addClient(client);
                }
            }
        }
    }
    if(client != nullptr) {
        if(!npc(alreadySubscribed)->isEmpty())
            npc(client)->subscribeSuccess(alreadySubscribed);

    }
    if(npc(toSubscribe)->isEmpty())
        return;

    sendSubscribe(toSubscribe, client, content, hint);
}

void rice::p2p::scribe::ScribeImpl::unsubscribe(Topic* topic, ScribeClient* client)
{
    unsubscribe(static_cast< ::java::util::Collection* >(::java::util::Collections::singletonList(topic)), getMultiClient(client));
}

void rice::p2p::scribe::ScribeImpl::unsubscribe(Topic* topic, ScribeMultiClient* client)
{
    unsubscribe(static_cast< ::java::util::Collection* >(::java::util::Collections::singletonList(topic)), client);
}

void rice::p2p::scribe::ScribeImpl::unsubscribe(::java::util::Collection* topicsToUnsubscribe, ScribeMultiClient* client)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Unsubscribing client "_j)->append(static_cast< ::java::lang::Object* >(client))
            ->append(u" from topic "_j)
            ->append(static_cast< ::java::lang::Object* >(topicManagers))->toString());

    auto needToUnsubscribe = new ::java::util::HashMap();
    {
        synchronized synchronized_3(topicManagers);
        {
            for (auto _i = npc(topicsToUnsubscribe)->iterator(); _i->hasNext(); ) {
                Topic* topic = java_cast< Topic* >(_i->next());
                {
                    auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
                    if(manager != nullptr) {
                        auto parent = npc(manager)->getParent();
                        if(npc(manager)->removeClient(getMultiClient(client))) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Removing TopicManager for topic: "_j)->append(static_cast< ::java::lang::Object* >(topic))->toString());

                            npc(topicManagers)->remove(static_cast< ::java::lang::Object* >(topic));
                            removeFromAllParents(topic, parent);
                            if(parent != nullptr) {
                                auto theTopics = java_cast< ::java::util::List* >(npc(needToUnsubscribe)->get(static_cast< ::java::lang::Object* >(parent)));
                                if(theTopics == nullptr) {
                                    theTopics = new ::java::util::ArrayList();
                                    npc(needToUnsubscribe)->put(static_cast< ::java::lang::Object* >(parent), static_cast< ::java::lang::Object* >(theTopics));
                                }
                                npc(theTopics)->add(static_cast< ::java::lang::Object* >(topic));
                            }
                        }
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Attempt to unsubscribe client "_j)->append(static_cast< ::java::lang::Object* >(client))
                                ->append(u" from unknown topic "_j)
                                ->append(static_cast< ::java::lang::Object* >(topic))->toString());

                    }
                }
            }
        }
    }
    for (auto _i = npc(npc(needToUnsubscribe)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::NodeHandle* parent = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
        {
            npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::UnsubscribeMessage(localHandle, java_cast< ::java::util::List* >(npc(needToUnsubscribe)->get(static_cast< ::java::lang::Object* >(parent))))), parent);
        }
    }
}

void rice::p2p::scribe::ScribeImpl::publish(Topic* topic, ScribeContent* content)
{
    publish(topic, dynamic_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) != nullptr ? java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) : static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(content)));
}

void rice::p2p::scribe::ScribeImpl::publish(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Publishing content "_j)->append(static_cast< ::java::lang::Object* >(content))
            ->append(u" to topic "_j)
            ->append(static_cast< ::java::lang::Object* >(topic))->toString());

    npc(endpoint)->route(npc(topic)->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::PublishRequestMessage(localHandle, topic, content)), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

void rice::p2p::scribe::ScribeImpl::anycast(Topic* topic, ScribeContent* content)
{
    anycast(topic, content, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

void rice::p2p::scribe::ScribeImpl::anycast(Topic* topic, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    if(dynamic_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) != nullptr) {
        anycast(topic, java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content), hint);
    } else {
        anycast(topic, static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(content)), hint);
    }
}

void rice::p2p::scribe::ScribeImpl::anycast(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    anycast(topic, content, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
}

void rice::p2p::scribe::ScribeImpl::anycast(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Anycasting content "_j)->append(static_cast< ::java::lang::Object* >(content))
            ->append(u" to topic "_j)
            ->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u" with hint "_j)
            ->append(static_cast< ::java::lang::Object* >(hint))->toString());

    auto aMsg = new ::rice::p2p::scribe::messaging::AnycastMessage(localHandle, topic, content);
    npc(policy)->directAnycast(aMsg, getParent(topic), getChildrenOfTopic(topic));
    if(hint == nullptr || npc(localHandle)->equals(hint)) {
        npc(endpoint)->route(npc(topic)->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aMsg), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
    } else {
        npc(endpoint)->route(npc(topic)->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aMsg), hint);
    }
}

void rice::p2p::scribe::ScribeImpl::addChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    if(addChildHelper(topic, child)) {
        subscribe(static_cast< ::java::util::Collection* >(::java::util::Collections::singletonList(topic)), static_cast< ScribeMultiClient* >(nullptr), npc(maintenancePolicy)->implicitSubscribe(::java::util::Collections::singletonList(topic)), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
    }
    auto manager = getTopicManager(topic);
    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::SubscribeAckMessage(localHandle, ::java::util::Collections::singletonList(topic), ::java::util::Collections::singletonList(npc(manager)->getPathToRoot()), MAINTENANCE_ID)), child);
}

void rice::p2p::scribe::ScribeImpl::setParent(Topic* topic, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::List* pathToRoot)
{
    auto manager = getTopicManager(topic);
    npc(manager)->setParent(parent, pathToRoot);
}

rice::p2p::scribe::ScribeImpl_TopicManager* rice::p2p::scribe::ScribeImpl::getTopicManager(Topic* topic)
{
    {
        synchronized synchronized_4(topicManagers);
        {
            auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
            if(manager == nullptr) {
                manager = new ScribeImpl_TopicManager(this, topic);
                npc(topicManagers)->put(static_cast< ::java::lang::Object* >(topic), static_cast< ::java::lang::Object* >(manager));
            }
            return manager;
        }
    }
}

bool rice::p2p::scribe::ScribeImpl::addChildHelper(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addChild("_j)->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(child))
            ->append(u","_j)
            ->append(id)
            ->append(u")"_j)->toString());

    auto ret = false;
    ScribeImpl_TopicManager* manager;
    ::java::util::List* clientList;
    {
        synchronized synchronized_5(topicManagers);
        {
            manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
            if(manager == nullptr) {
                manager = new ScribeImpl_TopicManager(this, topic);
                npc(topicManagers)->put(static_cast< ::java::lang::Object* >(topic), static_cast< ::java::lang::Object* >(manager));
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Implicitly subscribing to topic "_j)->append(static_cast< ::java::lang::Object* >(topic))->toString());

                ret = true;
            }
            npc(manager)->addChild(child);
            clientList = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(manager)->getClients()));
        }
    }
    npc(policy)->childAdded(topic, child);
    for (auto _i = npc(clientList)->iterator(); _i->hasNext(); ) {
        ScribeMultiClient* client = java_cast< ScribeMultiClient* >(_i->next());
        {
            npc(client)->childAdded(topic, child);
        }
    }
    return ret;
}

void rice::p2p::scribe::ScribeImpl::removeChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    removeChild(topic, child, true);
}

void rice::p2p::scribe::ScribeImpl::removeChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child, bool sendDrop)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Removing child "_j)->append(static_cast< ::java::lang::Object* >(child))
            ->append(u" from topic "_j)
            ->append(static_cast< ::java::lang::Object* >(topic))->toString());

    auto sendUnsubscribe = false;
    ScribeImpl_TopicManager* manager;
    {
        synchronized synchronized_6(topicManagers);
        {
            manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
            if(manager != nullptr) {
                auto parent = npc(manager)->getParent();
                sendUnsubscribe = npc(manager)->removeChild(child);
                if(sendUnsubscribe) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Removing TopicManager for topic: "_j)->append(static_cast< ::java::lang::Object* >(topic))->toString());

                    npc(topicManagers)->remove(static_cast< ::java::lang::Object* >(topic));
                    removeFromAllParents(topic, parent);
                }
            }
        }
    }
    if(manager != nullptr) {
        auto parent = npc(manager)->getParent();
        if(sendUnsubscribe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"We no longer need topic "_j)->append(static_cast< ::java::lang::Object* >(topic))
                    ->append(u" - unsubscribing from parent "_j)
                    ->append(static_cast< ::java::lang::Object* >(parent))->toString());

            if(parent != nullptr) {
                npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::UnsubscribeMessage(localHandle, ::java::util::Collections::singletonList(topic))), parent);
            }
        }
        if((sendDrop) && (npc(child)->isAlive())) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Informing child "_j)->append(static_cast< ::java::lang::Object* >(child))
                    ->append(u" that he has been dropped from topic "_j)
                    ->append(static_cast< ::java::lang::Object* >(topic))->toString());

            npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::DropMessage(localHandle, topic)), child);
        }
        npc(policy)->childRemoved(topic, child);
        ::java::util::List* clientList;
        {
            synchronized synchronized_7(topicManagers);
            {
                clientList = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(manager)->getClients()));
            }
        }
        for (auto _i = npc(clientList)->iterator(); _i->hasNext(); ) {
            ScribeMultiClient* client = java_cast< ScribeMultiClient* >(_i->next());
            {
                npc(client)->childRemoved(topic, child);
            }
        }
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Unexpected attempt to remove child "_j)->append(static_cast< ::java::lang::Object* >(child))
                ->append(u" from unknown topic "_j)
                ->append(static_cast< ::java::lang::Object* >(topic))->toString());

    }
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getTopicsByClient(ScribeClient* client)
{
    auto result = new ::java::util::ArrayList();
    for (auto _i = npc(npc(topicManagers)->values())->iterator(); _i->hasNext(); ) {
        ScribeImpl_TopicManager* topicManager = java_cast< ScribeImpl_TopicManager* >(_i->next());
        {
            if(npc(topicManager)->containsClient(getMultiClient(client)))
                npc(result)->add(static_cast< ::java::lang::Object* >(npc(topicManager)->getTopic()));

        }
    }
    return result;
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getTopicsByClient(ScribeMultiClient* client)
{
    auto result = new ::java::util::ArrayList();
    for (auto _i = npc(npc(topicManagers)->values())->iterator(); _i->hasNext(); ) {
        ScribeImpl_TopicManager* topicManager = java_cast< ScribeImpl_TopicManager* >(_i->next());
        {
            if(npc(topicManager)->containsClient(client))
                npc(result)->add(static_cast< ::java::lang::Object* >(npc(topicManager)->getTopic()));

        }
    }
    return result;
}

rice::p2p::scribe::TopicArray* rice::p2p::scribe::ScribeImpl::getTopics(ScribeClient* client)
{
    return java_cast< TopicArray* >(npc(getTopicsByClient(client))->toArray_());
}

void rice::p2p::scribe::ScribeImpl::recvAnycastFail(Topic* topic, ::rice::p2p::commonapi::NodeHandle* failedAtNode, ScribeContent* content)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"received anycast failure message from "_j)->append(static_cast< ::java::lang::Object* >(failedAtNode))
            ->append(u" for topic "_j)
            ->append(static_cast< ::java::lang::Object* >(topic))->toString());

    npc(policy)->recvAnycastFail(topic, failedAtNode, content);
}

void rice::p2p::scribe::ScribeImpl::addToAllChildren(Topic* t, ::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addToAllChildren("_j)->append(static_cast< ::java::lang::Object* >(t))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(child))
            ->append(u")"_j)->toString());

    auto topics = java_cast< ::java::util::Collection* >(npc(allChildren)->get(static_cast< ::java::lang::Object* >(child)));
    if(topics == nullptr) {
        if(npc(child)->isAlive()) {
            if(!npc(allParents)->containsKey(static_cast< ::java::lang::Object* >(child)))
                npc(child)->addObserver(this);

        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"addToAllChildren("_j)->append(static_cast< ::java::lang::Object* >(t))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(child))
                    ->append(u") child.isAlive() == false"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        }
        topics = new ::java::util::ArrayList();
        npc(allChildren)->put(static_cast< ::java::lang::Object* >(child), static_cast< ::java::lang::Object* >(topics));
    }
    if(!npc(topics)->contains(t)) {
        npc(topics)->add(t);
    }
}

void rice::p2p::scribe::ScribeImpl::removeFromAllChildren(Topic* t, ::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"removeFromAllChildren("_j)->append(static_cast< ::java::lang::Object* >(t))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(child))
            ->append(u")"_j)->toString());

    auto topics = java_cast< ::java::util::Collection* >(npc(allChildren)->get(static_cast< ::java::lang::Object* >(child)));
    if(topics == nullptr) {
        return;
    }
    npc(topics)->remove(t);
    if(npc(topics)->isEmpty()) {
        npc(allChildren)->remove(static_cast< ::java::lang::Object* >(child));
        if(!npc(allParents)->containsKey(static_cast< ::java::lang::Object* >(child)))
            npc(child)->deleteObserver(this);

    }
}

void rice::p2p::scribe::ScribeImpl::addToAllParents(Topic* t, ::rice::p2p::commonapi::NodeHandle* parent)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addToAllParents("_j)->append(static_cast< ::java::lang::Object* >(t))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(parent))
            ->append(u")"_j)->toString());

    if(parent == nullptr || npc(parent)->equals(localHandle)) {
        if(isRoot(t)) {
            npc(roots)->add(static_cast< ::java::lang::Object* >(t));
        }
        return;
    }
    auto topics = java_cast< ::java::util::Collection* >(npc(allParents)->get(static_cast< ::java::lang::Object* >(parent)));
    if(topics == nullptr) {
        if(npc(parent)->isAlive()) {
            if(!npc(allChildren)->containsKey(static_cast< ::java::lang::Object* >(parent)))
                npc(parent)->addObserver(this);

        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"addToAllParents("_j)->append(static_cast< ::java::lang::Object* >(t))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(parent))
                    ->append(u") parent.isAlive() == false"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        }
        topics = new ::java::util::ArrayList();
        npc(allParents)->put(static_cast< ::java::lang::Object* >(parent), static_cast< ::java::lang::Object* >(topics));
    }
    if(!npc(topics)->contains(t)) {
        npc(topics)->add(t);
    }
}

void rice::p2p::scribe::ScribeImpl::removeFromAllParents(Topic* t, ::rice::p2p::commonapi::NodeHandle* parent)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"removeFromAllParents("_j)->append(static_cast< ::java::lang::Object* >(t))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(parent))
            ->append(u")"_j)->toString());

    if(parent == nullptr || npc(parent)->equals(localHandle)) {
        npc(roots)->remove(static_cast< ::java::lang::Object* >(t));
        npc(pending)->remove(static_cast< ::java::lang::Object* >(t));
        return;
    }
    auto topics = java_cast< ::java::util::Collection* >(npc(allParents)->get(static_cast< ::java::lang::Object* >(parent)));
    if(topics == nullptr) {
        return;
    }
    npc(topics)->remove(t);
    if(npc(topics)->isEmpty()) {
        npc(allParents)->remove(static_cast< ::java::lang::Object* >(parent));
        if(!npc(allChildren)->containsKey(static_cast< ::java::lang::Object* >(parent)))
            npc(parent)->deleteObserver(this);

    }
}

bool rice::p2p::scribe::ScribeImpl::allParentsContains(Topic* t, ::rice::p2p::commonapi::NodeHandle* parent)
{
    if(parent == nullptr) {
        return false;
    }
    if(npc(allParents)->containsKey(static_cast< ::java::lang::Object* >(parent))) {
        auto topics = java_cast< ::java::util::Vector* >(java_cast< ::java::util::Collection* >(npc(allParents)->get(static_cast< ::java::lang::Object* >(parent))));
        if(npc(topics)->contains(static_cast< ::java::lang::Object* >(t))) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool rice::p2p::scribe::ScribeImpl::allParentsContainsParent(::rice::p2p::commonapi::NodeHandle* parent)
{
    if(parent == nullptr) {
        return false;
    }
    if(npc(allParents)->containsKey(static_cast< ::java::lang::Object* >(parent))) {
        return true;
    } else {
        return false;
    }
}

void rice::p2p::scribe::ScribeImpl::printAllParentsDataStructure()
{
    auto s = u"printAllParentsDataStructure()"_j;
    for (auto _i = npc(npc(allParents)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::NodeHandle* parent = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
        {
            s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"\n  parent: "_j)->append(static_cast< ::java::lang::Object* >(parent))
                ->append(u" (Topics,TopicExists,ActualParent) are as follows: "_j)->toString())->toString();
            for (auto _i = npc(java_cast< ::java::util::Collection* >(npc(allParents)->get(static_cast< ::java::lang::Object* >(parent))))->iterator(); _i->hasNext(); ) {
                Topic* t = java_cast< Topic* >(_i->next());
                {
                    auto topicExists = containsTopic(t);
                    auto actualParent = getParent(t);
                    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"\n    ("_j)->append(static_cast< ::java::lang::Object* >(t))
                        ->append(u", "_j)
                        ->append(topicExists)
                        ->append(u", "_j)
                        ->append(static_cast< ::java::lang::Object* >(actualParent))
                        ->append(u")"_j)->toString())->toString();
                }
            }
        }
    }
}

void rice::p2p::scribe::ScribeImpl::printAllChildrenDataStructure()
{
    auto s = u"printAllChildrenDataStructure()"_j;
    for (auto _i = npc(npc(allChildren)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::NodeHandle* child = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
        {
            s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"\n  child: "_j)->append(static_cast< ::java::lang::Object* >(child))
                ->append(u" (Topics,TopicExists, containsChild) are as follows: "_j)->toString())->toString();
            for (auto _i = npc(java_cast< ::java::util::Collection* >(npc(allChildren)->get(static_cast< ::java::lang::Object* >(child))))->iterator(); _i->hasNext(); ) {
                Topic* t = java_cast< Topic* >(_i->next());
                {
                    auto topicExists = containsTopic(t);
                    auto containsChild = this->containsChild(t, child);
                    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"\n    ("_j)->append(static_cast< ::java::lang::Object* >(t))
                        ->append(u", "_j)
                        ->append(topicExists)
                        ->append(u", "_j)
                        ->append(containsChild)
                        ->append(u")"_j)->toString())->toString();
                }
            }
        }
    }
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getTopicsByParent(::rice::p2p::commonapi::NodeHandle* parent)
{
    if(parent == nullptr)
        parent = localHandle;

    if(npc(parent)->equals(localHandle))
        return roots;

    auto topic = java_cast< ::java::util::Collection* >(npc(allParents)->get(static_cast< ::java::lang::Object* >(parent)));
    if(topic == nullptr) {
        return ::java::util::Collections::emptyList();
    }
    return topic;
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getTopicsByChild(::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(child)->equals(localHandle)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"ScribeImpl.getTopicsByChild() called with localHandle! Why would you do that?"_j);

    }
    auto topic = java_cast< ::java::util::Collection* >(npc(allChildren)->get(static_cast< ::java::lang::Object* >(child)));
    if(topic == nullptr) {
        return ::java::util::Collections::emptyList();
    }
    return topic;
}

bool rice::p2p::scribe::ScribeImpl::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    ::rice::p2p::commonapi::Message* internalMessage;
    try {
        internalMessage = npc(message)->getMessage(npc(endpoint)->getDeserializer());
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Forward called with "_j)->append(static_cast< ::java::lang::Object* >(internalMessage))
            ->append(u" "_j)
            ->append(npc(npc(internalMessage)->getClass())->getName())->toString());

    if(dynamic_cast< ::rice::p2p::scribe::messaging::ScribeMessage* >(internalMessage) != nullptr) {
        npc(policy)->intermediateNode(java_cast< ::rice::p2p::scribe::messaging::ScribeMessage* >(internalMessage));
    }
    if(dynamic_cast< ::rice::p2p::scribe::messaging::AnycastMessage* >(internalMessage) != nullptr) {
        auto aMessage = java_cast< ::rice::p2p::scribe::messaging::AnycastMessage* >(internalMessage);
        if(npc(aMessage)->getTopic() == nullptr) {
            throw new ::java::lang::RuntimeException(u"topic is null!"_j);
        }
        auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))));
        if(dynamic_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(internalMessage) != nullptr) {
            auto sMessage = java_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(internalMessage);
            return handleForwardSubscribeMessage(sMessage);
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(u"DEBUG: Anycast message.forward(1)"_j);

            if(npc(npc(endpoint)->getLocalNodeHandle())->equals(npc(aMessage)->getLastVisited()) && !npc(npc(endpoint)->getLocalNodeHandle())->equals(npc(aMessage)->getInitialRequestor())) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Bypassing forward logic of anycast message becuase local node is the last visited node "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getLastVisited()))
                        ->append(u" of in the anycast message "_j)->toString());
                    if(isRoot(npc(aMessage)->getTopic())) {
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Local node is the root of anycast group "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))->toString());
                    }
                }
                return true;
            }
            if(manager == nullptr) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(u"Manager of anycast group is null"_j);

                return true;
            }
            auto clients = npc(manager)->getClients();
            for (auto _i = npc(clients)->iterator(); _i->hasNext(); ) {
                ScribeMultiClient* client = java_cast< ScribeMultiClient* >(_i->next());
                {
                    if(npc(client)->anycast(npc(aMessage)->getTopic(), npc(aMessage)->getContent())) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Accepting anycast message from "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getSource()))
                                ->append(u" for topic "_j)
                                ->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))->toString());

                        return false;
                    }
                }
            }
            if(npc(npc(npc(aMessage)->getSource())->getId())->equals(npc(endpoint)->getId()) && (npc(message)->getNextHopHandle() != nullptr) && (!npc(localHandle)->equals(npc(message)->getNextHopHandle()))) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(u"DEBUG: Anycast message.forward(2), before returning true"_j);

                return true;
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Rejecting anycast message from "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getSource()))
                    ->append(u" for topic "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))->toString());

        }
        npc(aMessage)->addVisited(npc(endpoint)->getLocalNodeHandle());
        npc(policy)->directAnycast(aMessage, npc(manager)->getParent(), npc(manager)->getChildren());
        npc(aMessage)->setSource(npc(endpoint)->getLocalNodeHandle());
        auto handle = npc(aMessage)->getNext();
        while ((handle != nullptr) && (!npc(handle)->isAlive())) {
            handle = npc(aMessage)->getNext();
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Forwarding anycast message for topic "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))
                ->append(u"on to "_j)
                ->append(static_cast< ::java::lang::Object* >(handle))->toString());

        if(handle == nullptr) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Anycast "_j)->append(static_cast< ::java::lang::Object* >(aMessage))
                    ->append(u" failed."_j)->toString());

            if(npc(logger)->level <= INFO_2) {
                npc(logger)->log(::java::lang::StringBuilder().append(u"Anycast failed at this intermediate node:"_j)->append(static_cast< ::java::lang::Object* >(aMessage))
                    ->append(u"\nAnycastMessage ANYCASTFAILEDHOPS "_j)
                    ->append(npc(aMessage)->getVisitedSize())
                    ->append(u" "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getContent()))->toString());
            }
            auto aFailMsg = new ::rice::p2p::scribe::messaging::AnycastFailureMessage(npc(endpoint)->getLocalNodeHandle(), npc(aMessage)->getTopic(), npc(aMessage)->getContent());
            npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aFailMsg), npc(aMessage)->getInitialRequestor());
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"forward() routing "_j)->append(static_cast< ::java::lang::Object* >(aMessage))
                    ->append(u" to "_j)
                    ->append(static_cast< ::java::lang::Object* >(handle))->toString());

            npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aMessage), handle);
        }
        return false;
    }
    return true;
}

bool rice::p2p::scribe::ScribeImpl::handleForwardSubscribeMessage(::rice::p2p::scribe::messaging::SubscribeMessage* sMessage)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardScribeMessage("_j)->append(static_cast< ::java::lang::Object* >(sMessage))
            ->append(u")"_j)->toString());

    if(npc(npc(npc(sMessage)->getSource())->getId())->equals(npc(endpoint)->getId())) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Bypassing forward logic of subscribemessage "_j)->append(static_cast< ::java::lang::Object* >(sMessage))
                ->append(u" becuase local node is the subscriber source."_j)->toString());

        return true;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() here 1 "_j)->append(static_cast< ::java::lang::Object* >(sMessage))->toString());

    auto forward = new ::java::util::ArrayList();
    auto dontForward = new ::java::util::ArrayList();
    auto askPolicy = new ::java::util::ArrayList();
    for (auto _i = npc(npc(sMessage)->getTopics())->iterator(); _i->hasNext(); ) {
        Topic* topic = java_cast< Topic* >(_i->next());
        {
            auto tmanager = java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic)));
            if(tmanager != nullptr) {
                auto path = npc(tmanager)->getPathToRoot();
                if(npc(path)->contains(static_cast< ::java::lang::Object* >(npc(npc(sMessage)->getSubscriber())->getId()))) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO) {
                        auto s = ::java::lang::StringBuilder().append(u"Rejecting subscribe message from "_j)->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getSubscriber()))
                            ->append(u" for topic "_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getTopic()))
                            ->append(u" because we are on the subscriber's path to the root:"_j)->toString();
                        for (auto _i = npc(path)->iterator(); _i->hasNext(); ) {
                            ::rice::p2p::commonapi::Id* id = java_cast< ::rice::p2p::commonapi::Id* >(_i->next());
                            {
                                s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(id))->append(u","_j)->toString())->toString();
                            }
                        }
                        npc(logger)->log(s);
                    }
                    npc(forward)->add(static_cast< ::java::lang::Object* >(topic));
                    continue;
                }
                if(npc(npc(tmanager)->getChildren())->contains(npc(sMessage)->getSubscriber())) {
                    npc(dontForward)->add(static_cast< ::java::lang::Object* >(topic));
                    continue;
                }
            }
            npc(askPolicy)->add(static_cast< ::java::lang::Object* >(topic));
        }
    }
    ::java::util::List* accepted;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() here 2 "_j)->append(static_cast< ::java::lang::Object* >(sMessage))->toString());

    if(!npc(askPolicy)->isEmpty()) {
        accepted = npc(policy)->allowSubscribe(this, npc(sMessage)->getSubscriber(), new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(askPolicy)), npc(sMessage)->getContent());
        npc(askPolicy)->removeAll(static_cast< ::java::util::Collection* >(accepted));
        npc(dontForward)->addAll(static_cast< ::java::util::Collection* >(accepted));
        ::java::util::List* newTopics = new ::java::util::ArrayList();
        if(npc(npc(sMessage)->getSubscriber())->isAlive()) {
            for (auto _i = npc(accepted)->iterator(); _i->hasNext(); ) {
                Topic* topic = java_cast< Topic* >(_i->next());
                {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Hijacking subscribe message from "_j)->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getSubscriber()))
                            ->append(u" for topic "_j)
                            ->append(static_cast< ::java::lang::Object* >(topic))->toString());

                    if(addChildHelper(topic, npc(sMessage)->getSubscriber())) {
                        npc(newTopics)->add(static_cast< ::java::lang::Object* >(topic));
                    }
                }
            }
            subscribe(static_cast< ::java::util::Collection* >(newTopics), static_cast< ScribeMultiClient* >(nullptr), npc(maintenancePolicy)->implicitSubscribe(newTopics), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING) {
                npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping subscribe message for dead "_j)->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getSubscriber()))
                    ->append(u" "_j)
                    ->append(static_cast< ::java::lang::Object* >(accepted))->toString());
            }
            npc(accepted)->clear();
        }
    } else {
        accepted = askPolicy;
    }
    ::java::util::List* rejected = askPolicy;
    npc(forward)->addAll(static_cast< ::java::util::Collection* >(rejected));
    ::java::util::List* toReturn;
    if(npc(sMessage)->getId() == MAINTENANCE_ID) {
        toReturn = accepted;
    } else {
        toReturn = dontForward;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() here 3 "_j)->append(static_cast< ::java::lang::Object* >(sMessage))->toString());

    if(!npc(toReturn)->isEmpty() && npc(npc(sMessage)->getSubscriber())->isAlive()) {
        ::java::util::List* paths = new ::java::util::ArrayList(npc(toReturn)->size());
        for (auto _i = npc(toReturn)->iterator(); _i->hasNext(); ) {
            Topic* topic = java_cast< Topic* >(_i->next());
            {
                auto tmanager = java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic)));
                npc(paths)->add(static_cast< ::java::lang::Object* >(npc(tmanager)->getPathToRoot()));
            }
        }
        npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::SubscribeAckMessage(localHandle, toReturn, paths, npc(sMessage)->getId())), npc(sMessage)->getSubscriber());
    }
    npc(sMessage)->removeTopics(dontForward);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Rejecting subscribe message from "_j)->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getSubscriber()))
            ->append(u" for topic(s) "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getTopics()))->toString());

    if(npc(sMessage)->isEmpty()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(u"handleForwardSubscribeMessage() returning false here 85"_j);

        return false;
    }
    npc(sMessage)->addVisited(npc(endpoint)->getLocalNodeHandle());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() here 4 "_j)->append(static_cast< ::java::lang::Object* >(sMessage))->toString());

    ::java::util::List* noManager = new ::java::util::ArrayList();
    ::java::util::List* failed = new ::java::util::ArrayList();
    auto topicIterator = npc(npc(sMessage)->getTopics())->iterator();
    while (npc(topicIterator)->hasNext()) {
        auto topic = java_cast< Topic* >(npc(topicIterator)->next());
        auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
        if(manager == nullptr) {
            npc(noManager)->add(static_cast< ::java::lang::Object* >(topic));
        } else {
            npc(topicIterator)->remove();
            ::rice::p2p::scribe::messaging::AnycastMessage* aMessage = npc(sMessage)->copy(::java::util::Collections::singletonList(topic), npc(sMessage)->getRawContent());
            npc(policy)->directAnycast(aMessage, npc(manager)->getParent(), npc(manager)->getChildren());
            npc(aMessage)->setSource(npc(endpoint)->getLocalNodeHandle());
            auto handle = npc(aMessage)->getNext();
            while ((handle != nullptr) && (!npc(handle)->isAlive())) {
                handle = npc(aMessage)->getNext();
            }
            if(handle == nullptr || !npc(handle)->isAlive())
                handle = nullptr;

            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Forwarding anycast message for topic "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))
                    ->append(u"on to "_j)
                    ->append(static_cast< ::java::lang::Object* >(handle))->toString());

            if(handle == nullptr) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Anycast "_j)->append(static_cast< ::java::lang::Object* >(aMessage))
                        ->append(u" failed."_j)->toString());

                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Sending SubscribeFailedMessage to "_j)->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getSubscriber()))
                        ->append(u" for topic "_j)
                        ->append(static_cast< ::java::lang::Object* >(topic))->toString());

                npc(failed)->add(static_cast< ::java::lang::Object* >(topic));
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() routing "_j)->append(static_cast< ::java::lang::Object* >(aMessage))
                        ->append(u" to "_j)
                        ->append(static_cast< ::java::lang::Object* >(handle))->toString());

                npc(endpoint)->route(npc(npc(aMessage)->getTopic())->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aMessage), handle);
            }
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() here 5 "_j)->append(static_cast< ::java::lang::Object* >(sMessage))->toString());

    auto manifest = buildManifests(noManager);
    if(npc(manifest)->containsKey(static_cast< ::java::lang::Object* >(localHandle))) {
        auto theTopics = java_cast< ::java::util::List* >(npc(manifest)->remove(static_cast< ::java::lang::Object* >(localHandle)));
        npc(sMessage)->removeTopics(theTopics);
        for (auto _i = npc(theTopics)->iterator(); _i->hasNext(); ) {
            Topic* topic = java_cast< Topic* >(_i->next());
            {
                npc(failed)->add(static_cast< ::java::lang::Object* >(topic));
            }
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() here 6 "_j)->append(static_cast< ::java::lang::Object* >(sMessage))->toString());

    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::SubscribeFailedMessage(localHandle, failed, npc(sMessage)->getId())), npc(sMessage)->getSubscriber());
    if(npc(npc(manifest)->keySet())->size() == 1) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(::java::lang::StringBuilder().append(u"handleForwardSubscribeMessage() returning true at this location!!! "_j)->append(static_cast< ::java::lang::Object* >(sMessage))->toString());

        return true;
    }
    for (auto _i = npc(npc(manifest)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::NodeHandle* nextHop = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
        {
            auto theTopics = java_cast< ::java::util::List* >(npc(manifest)->get(static_cast< ::java::lang::Object* >(nextHop)));
            if(theTopics != nullptr) {
                ::rice::p2p::scribe::messaging::AnycastMessage* aMessage = npc(sMessage)->copy(theTopics, convert(npc(policy)->divideContent(theTopics, npc(sMessage)->getContent())));
                npc(endpoint)->route(npc(npc(aMessage)->getTopic())->getId(), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aMessage), nextHop);
            }
        }
    }
    return false;
}

void rice::p2p::scribe::ScribeImpl::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Deliver called with "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(message))->toString());

    if(dynamic_cast< ::rice::p2p::scribe::messaging::AnycastMessage* >(message) != nullptr) {
        auto aMessage = java_cast< ::rice::p2p::scribe::messaging::AnycastMessage* >(message);
        if(npc(npc(aMessage)->getSource())->equals(localHandle)) {
            if(dynamic_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(aMessage) != nullptr) {
                auto sMessage = java_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(message);
                if(npc(sMessage)->isEmpty())
                    return;

                auto slm = java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(npc(subscribeLostMessages)->get(::java::lang::Integer::valueOf(npc(sMessage)->getId())));
                if(slm != nullptr) {
                    auto multiClient = npc(slm)->getClient();
                    if(multiClient != nullptr)
                        npc(multiClient)->subscribeSuccess(npc(sMessage)->getTopics());

                    if(npc(slm)->topicsAcked(npc(sMessage)->getTopics())) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Removing client "_j)->append(static_cast< ::java::lang::Object* >(npc(slm)->getClient()))
                                ->append(u" from list of outstanding for ack "_j)
                                ->append(npc(sMessage)->getId())->toString());
                        }
                        npc(java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(npc(subscribeLostMessages)->remove(::java::lang::Integer::valueOf(npc(sMessage)->getId()))))->cancel();
                    }
                }
                for (auto _i = npc(npc(sMessage)->getTopics())->iterator(); _i->hasNext(); ) {
                    Topic* topic = java_cast< Topic* >(_i->next());
                    {
                        if(!isRoot(topic)) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Received our own subscribe message "_j)->append(static_cast< ::java::lang::Object* >(aMessage))
                                    ->append(u" for topic "_j)
                                    ->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))
                                    ->append(u" - we are not the root."_j)->toString());

                        }
                    }
                }
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Received our own subscribe message "_j)->append(static_cast< ::java::lang::Object* >(aMessage))
                        ->append(u" for topic "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))
                        ->append(u" - we are the root."_j)->toString());

            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"WARNING : Anycast failed at Root for Topic "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))
                        ->append(u" was generated by us "_j)
                        ->append(u" msg= "_j)
                        ->append(static_cast< ::java::lang::Object* >(aMessage))->toString());

                if(npc(logger)->level <= INFO_2)
                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->append(u": AnycastMessage ANYCASTFAILEDHOPS "_j)
                        ->append(npc(aMessage)->getVisitedSize())
                        ->append(u" "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getContent()))->toString());

                auto aFailMsg = new ::rice::p2p::scribe::messaging::AnycastFailureMessage(npc(endpoint)->getLocalNodeHandle(), npc(aMessage)->getTopic(), npc(aMessage)->getContent());
                npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aFailMsg), npc(aMessage)->getInitialRequestor());
            }
        } else {
            if(dynamic_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(aMessage) != nullptr) {
                auto sMessage = java_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(aMessage);
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Sending SubscribeFailedMessage (at root) to "_j)->append(static_cast< ::java::lang::Object* >(npc(sMessage)->getSubscriber()))->toString());

                npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::SubscribeFailedMessage(localHandle, npc(sMessage)->getTopics(), npc(sMessage)->getId())), npc(sMessage)->getSubscriber());
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"WARNING : Anycast failed at Root for Topic "_j)->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getTopic()))
                        ->append(u" not generated by us "_j)
                        ->append(u" msg= "_j)
                        ->append(static_cast< ::java::lang::Object* >(aMessage))->toString());

                if(npc(logger)->level <= INFO_2)
                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->append(u": AnycastMessage ANYCASTFAILEDHOPS "_j)
                        ->append(npc(aMessage)->getVisitedSize())
                        ->append(u" "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc(aMessage)->getContent()))->toString());

                auto aFailMsg = new ::rice::p2p::scribe::messaging::AnycastFailureMessage(npc(endpoint)->getLocalNodeHandle(), npc(aMessage)->getTopic(), npc(aMessage)->getContent());
                npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(aFailMsg), npc(aMessage)->getInitialRequestor());
            }
        }
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::SubscribeAckMessage* >(message) != nullptr) {
        auto needToUnsubscribe = new ::java::util::HashMap();
        auto saMessage = java_cast< ::rice::p2p::scribe::messaging::SubscribeAckMessage* >(message);
        if(!npc(npc(saMessage)->getSource())->isAlive()) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping subscribe ack message from dead node:"_j)->append(static_cast< ::java::lang::Object* >(npc(saMessage)->getSource()))
                    ->append(u" for topics "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(saMessage)->getTopics()))->toString());

            return;
        }
        auto i = npc(npc(saMessage)->getPathsToRoot())->iterator();
        for (auto _i = npc(npc(saMessage)->getTopics())->iterator(); _i->hasNext(); ) {
            Topic* topic = java_cast< Topic* >(_i->next());
            {
                auto pathToRoot = java_cast< ::java::util::List* >(npc(i)->next());
                auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Received subscribe ack message from "_j)->append(static_cast< ::java::lang::Object* >(npc(saMessage)->getSource()))
                        ->append(u" for topic "_j)
                        ->append(static_cast< ::java::lang::Object* >(topic))->toString());

                ackMessageReceived(saMessage);
                if(isRoot(topic)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Received unexpected subscribe ack message (we are the root) from "_j)->append(static_cast< ::java::lang::Object* >(npc(saMessage)->getSource()))
                            ->append(u" for topic "_j)
                            ->append(static_cast< ::java::lang::Object* >(topic))->toString());

                    auto topics = java_cast< ::java::util::List* >(npc(needToUnsubscribe)->get(static_cast< ::java::lang::Object* >(npc(saMessage)->getSource())));
                    if(topics == nullptr)
                        topics = new ::java::util::ArrayList();

                    npc(topics)->add(static_cast< ::java::lang::Object* >(topic));
                } else {
                    if(manager == nullptr) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Received unexpected subscribe ack message from "_j)->append(static_cast< ::java::lang::Object* >(npc(saMessage)->getSource()))
                                ->append(u" for unknown topic "_j)
                                ->append(static_cast< ::java::lang::Object* >(topic))->toString());

                        auto topics = java_cast< ::java::util::List* >(npc(needToUnsubscribe)->get(static_cast< ::java::lang::Object* >(npc(saMessage)->getSource())));
                        if(topics == nullptr)
                            topics = new ::java::util::ArrayList();

                        npc(topics)->add(static_cast< ::java::lang::Object* >(topic));
                    } else {
                        if(npc(manager)->getParent() == nullptr) {
                            setParent(topic, npc(saMessage)->getSource(), pathToRoot);
                        }
                        if(!npc(npc(manager)->getParent())->equals(npc(saMessage)->getSource())) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Received somewhat unexpected subscribe ack message (already have parent "_j)->append(static_cast< ::java::lang::Object* >(npc(manager)->getParent()))
                                    ->append(u") from "_j)
                                    ->append(static_cast< ::java::lang::Object* >(npc(saMessage)->getSource()))
                                    ->append(u" for topic "_j)
                                    ->append(static_cast< ::java::lang::Object* >(topic))
                                    ->append(u" - the new policy is now to accept the message"_j)->toString());

                            auto parent = npc(manager)->getParent();
                            setParent(topic, npc(saMessage)->getSource(), pathToRoot);
                            auto topics = java_cast< ::java::util::List* >(npc(needToUnsubscribe)->get(static_cast< ::java::lang::Object* >(parent)));
                            if(topics == nullptr) {
                                topics = new ::java::util::ArrayList();
                                npc(needToUnsubscribe)->put(static_cast< ::java::lang::Object* >(parent), static_cast< ::java::lang::Object* >(topics));
                            }
                            npc(topics)->add(static_cast< ::java::lang::Object* >(topic));
                        }
                    }
                }
                for (auto _i = npc(npc(needToUnsubscribe)->keySet())->iterator(); _i->hasNext(); ) {
                    ::rice::p2p::commonapi::NodeHandle* source = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
                    {
                        npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::UnsubscribeMessage(localHandle, java_cast< ::java::util::List* >(npc(needToUnsubscribe)->get(static_cast< ::java::lang::Object* >(source))))), source);
                    }
                }
            }
        }
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(message) != nullptr) {
        auto slMessage = java_cast< ::rice::p2p::scribe::messaging::SubscribeLostMessage* >(message);
        lostMessageReceived(slMessage);
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::SubscribeFailedMessage* >(message) != nullptr) {
        auto sfMessage = java_cast< ::rice::p2p::scribe::messaging::SubscribeFailedMessage* >(message);
        failedMessageReceived(sfMessage);
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::PublishRequestMessage* >(message) != nullptr) {
        auto prMessage = java_cast< ::rice::p2p::scribe::messaging::PublishRequestMessage* >(message);
        auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(npc(prMessage)->getTopic()))));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received publish request message with data "_j)->append(static_cast< ::java::lang::Object* >(npc(prMessage)->getContent()))
                ->append(u" for topic "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(prMessage)->getTopic()))->toString());

        if(manager == nullptr) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received publish request message for non-existent topic "_j)->append(static_cast< ::java::lang::Object* >(npc(prMessage)->getTopic()))
                    ->append(u" - dropping on floor."_j)->toString());

        } else {
            deliver(npc(npc(prMessage)->getTopic())->getId(), static_cast< ::rice::p2p::commonapi::Message* >(new ::rice::p2p::scribe::messaging::PublishMessage(npc(prMessage)->getSource(), npc(prMessage)->getTopic(), npc(prMessage)->getContent())));
        }
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::PublishMessage* >(message) != nullptr) {
        auto pMessage = java_cast< ::rice::p2p::scribe::messaging::PublishMessage* >(message);
        auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(npc(pMessage)->getTopic()))));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received publish message with data "_j)->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getContent()))
                ->append(u" for topic "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getTopic()))->toString());

        if((manager != nullptr) && ((npc(manager)->getParent() == nullptr) || (npc(npc(manager)->getParent())->equals(npc(pMessage)->getSource())))) {
            npc(pMessage)->setSource(localHandle);
            auto clients = npc(manager)->getClients();
            npc(policy)->intermediateNode(pMessage);
            for (auto _i = npc(clients)->iterator(); _i->hasNext(); ) {
                ScribeMultiClient* client = java_cast< ScribeMultiClient* >(_i->next());
                {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Delivering publish message with data "_j)->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getContent()))
                            ->append(u" for topic "_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getTopic()))
                            ->append(u" to client "_j)
                            ->append(static_cast< ::java::lang::Object* >(client))->toString());

                    npc(client)->deliver(npc(pMessage)->getTopic(), npc(pMessage)->getContent());
                }
            }
            ::java::util::Collection* handles = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(manager)->getChildren()));
            for (auto _i = npc(handles)->iterator(); _i->hasNext(); ) {
                ::rice::p2p::commonapi::NodeHandle* handle = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
                {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Forwarding publish message with data "_j)->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getContent()))
                            ->append(u" for topic "_j)
                            ->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getTopic()))
                            ->append(u" to child "_j)
                            ->append(static_cast< ::java::lang::Object* >(handle))->toString());

                    npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::PublishMessage(npc(endpoint)->getLocalNodeHandle(), npc(pMessage)->getTopic(), npc(pMessage)->getContent())), handle);
                }
            }
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received unexpected publish message from "_j)->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getSource()))
                    ->append(u" for unknown topic "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(pMessage)->getTopic()))->toString());

            npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::UnsubscribeMessage(localHandle, ::java::util::Collections::singletonList(npc(pMessage)->getTopic()))), npc(pMessage)->getSource());
        }
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::UnsubscribeMessage* >(message) != nullptr) {
        auto uMessage = java_cast< ::rice::p2p::scribe::messaging::UnsubscribeMessage* >(message);
        auto topics = npc(uMessage)->getTopics();
        auto source = npc(uMessage)->getSource();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
            ::java::lang::String* s;
            if(npc(topics)->size() == 1) {
                s = ::java::lang::StringBuilder().append(u" for topic "_j)->append(npc(java_cast< Topic* >(npc(topics)->get(0)))->toString())->toString();
            } else {
                s = ::java::lang::StringBuilder().append(u" for "_j)->append(npc(topics)->size())
                    ->append(u" topics."_j)->toString();
            }
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received unsubscribe message from "_j)->append(static_cast< ::java::lang::Object* >(source))
                ->append(s)->toString());
        }
        for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
            Topic* topic = java_cast< Topic* >(_i->next());
            {
                removeChild(topic, source, false);
            }
        }
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::DropMessage* >(message) != nullptr) {
        auto dMessage = java_cast< ::rice::p2p::scribe::messaging::DropMessage* >(message);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received drop message from "_j)->append(static_cast< ::java::lang::Object* >(npc(dMessage)->getSource()))
                ->append(u" for topic "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(dMessage)->getTopic()))->toString());

        auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(npc(dMessage)->getTopic()))));
        if(manager != nullptr) {
            if((npc(manager)->getParent() != nullptr) && npc(npc(manager)->getParent())->equals(npc(dMessage)->getSource())) {
                setParent(npc(dMessage)->getTopic(), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr), static_cast< ::java::util::List* >(nullptr));
                auto clients = npc(manager)->getClients();
                sendSubscribe(npc(dMessage)->getTopic(), static_cast< ScribeMultiClient* >(nullptr), npc(maintenancePolicy)->implicitSubscribe(::java::util::Collections::singletonList(npc(dMessage)->getTopic())), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Received unexpected drop message from non-parent "_j)->append(static_cast< ::java::lang::Object* >(npc(dMessage)->getSource()))
                        ->append(u" for topic "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc(dMessage)->getTopic()))
                        ->append(u" - ignoring"_j)->toString());

            }
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received unexpected drop message from "_j)->append(static_cast< ::java::lang::Object* >(npc(dMessage)->getSource()))
                    ->append(u" for unknown topic "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(dMessage)->getTopic()))
                    ->append(u" - ignoring"_j)->toString());

        }
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::MaintenanceMessage* >(message) != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"Received maintenance message"_j);

        npc(maintenancePolicy)->doMaintenance(this);
    } else if(dynamic_cast< ::rice::p2p::scribe::messaging::AnycastFailureMessage* >(message) != nullptr) {
        auto aFailMsg = java_cast< ::rice::p2p::scribe::messaging::AnycastFailureMessage* >(message);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received anycast failure message from "_j)->append(static_cast< ::java::lang::Object* >(npc(aFailMsg)->getSource()))
                ->append(u" for topic "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(aFailMsg)->getTopic()))->toString());

        recvAnycastFail(npc(aFailMsg)->getTopic(), npc(aFailMsg)->getSource(), npc(aFailMsg)->getContent());
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received unknown message "_j)->append(static_cast< ::java::lang::Object* >(message))
                ->append(u" - dropping on floor."_j)->toString());

    }
}

rice::p2p::scribe::rawserialization::RawScribeContent* rice::p2p::scribe::ScribeImpl::convert(ScribeContent* content)
{
    if(content == nullptr)
        return nullptr;

    if(dynamic_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) != nullptr)
        return java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content);

    return new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(content);
}

void rice::p2p::scribe::ScribeImpl::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    if(npc(arg)->equals(::rice::p2p::commonapi::NodeHandle::DECLARED_DEAD())) {
        auto handle = java_cast< ::rice::p2p::commonapi::NodeHandle* >(o);
        auto wasChildOfTopics = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(getTopicsByChild(handle)));
        for (auto _i = npc(wasChildOfTopics)->iterator(); _i->hasNext(); ) {
            Topic* topic = java_cast< Topic* >(_i->next());
            {
                removeChild(topic, handle);
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Child "_j)->append(static_cast< ::java::lang::Object* >(o))
                        ->append(u" for topic "_j)
                        ->append(static_cast< ::java::lang::Object* >(topic))
                        ->append(u" has died - removing."_j)->toString());

            }
        }
        auto wasParentOfTopics = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(getTopicsByParent(handle)));
        for (auto _i = npc(wasParentOfTopics)->iterator(); _i->hasNext(); ) {
            Topic* topic = java_cast< Topic* >(_i->next());
            {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Parent "_j)->append(static_cast< ::java::lang::Object* >(handle))
                        ->append(u" for topic "_j)
                        ->append(static_cast< ::java::lang::Object* >(topic))
                        ->append(u" has died - removing."_j)->toString());

                setParent(topic, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr), static_cast< ::java::util::List* >(nullptr));
            }
        }
        npc(maintenancePolicy)->nodeFaulty(this, handle, wasParentOfTopics, wasChildOfTopics);
    }
}

void rice::p2p::scribe::ScribeImpl::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"update("_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u", "_j)
            ->append(joined)
            ->append(u")"_j)->toString());

    if(joined) {
        ::java::util::List* notRoot = new ::java::util::ArrayList();
        for (auto _i = (new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(topicManagers)->values())))->iterator(); _i->hasNext(); ) {
            ScribeImpl_TopicManager* manager = java_cast< ScribeImpl_TopicManager* >(_i->next());
            {
                auto topic = npc(manager)->topic;
                if(!isRoot(topic) && npc(manager)->getParent() == nullptr) {
                    npc(notRoot)->add(static_cast< ::java::lang::Object* >(topic));
                }
            }
        }
        if(!npc(notRoot)->isEmpty()) {
            npc(maintenancePolicy)->noLongerRoot(this, notRoot);
        }
    }
}

java::lang::String* rice::p2p::scribe::ScribeImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"ScribeImpl["_j)->append(static_cast< ::java::lang::Object* >(localHandle))
        ->append(u"]"_j)->toString();
}

void rice::p2p::scribe::ScribeImpl::destroy()
{
    if(npc(npc(environment)->getSelectorManager())->isSelectorThread()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Destroying "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

        auto managers = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(topicManagers)->values()));
        npc(topicManagers)->clear();
        for (auto _i = npc(npc(allChildren)->keySet())->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::NodeHandle* handle = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
            {
                npc(handle)->deleteObserver(this);
            }
        }
        for (auto _i = npc(npc(allParents)->keySet())->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::NodeHandle* handle = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
            {
                npc(handle)->deleteObserver(this);
            }
        }
    } else {
        npc(npc(environment)->getSelectorManager())->invoke(new ScribeImpl_destroy_2(this));
    }
}

rice::p2p::commonapi::Endpoint* rice::p2p::scribe::ScribeImpl::getEndpoint()
{
    return endpoint;
}

void rice::p2p::scribe::ScribeImpl::setContentDeserializer(::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* deserializer)
{
    contentDeserializer = deserializer;
}

rice::p2p::scribe::rawserialization::ScribeContentDeserializer* rice::p2p::scribe::ScribeImpl::getContentDeserializer()
{
    return contentDeserializer;
}

java::util::Collection* rice::p2p::scribe::ScribeImpl::getTopics()
{
    return npc(topicManagers)->keySet();
}

java::util::List* rice::p2p::scribe::ScribeImpl::getPathToRoot(Topic* topic)
{
    auto manager = java_cast< ScribeImpl_TopicManager* >(java_cast< ScribeImpl_TopicManager* >(npc(topicManagers)->get(static_cast< ::java::lang::Object* >(topic))));
    if(manager == nullptr)
        return nullptr;

    return npc(manager)->getPathToRoot();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribeImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.ScribeImpl", 26);
    return c;
}

java::lang::Class* rice::p2p::scribe::ScribeImpl::getClass0()
{
    return class_();
}

