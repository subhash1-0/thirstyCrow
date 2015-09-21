// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/WeakHashMap.hpp>
#include <rice/Continuation_ListenerContinuation.hpp>
#include <rice/Continuation_NamedContinuation.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastImpl_getResponseContinuation_2.hpp>
#include <rice/p2p/past/PastImpl_getFetchResponseContinuation_3.hpp>
#include <rice/p2p/past/PastImpl_sendViaSocket_4.hpp>
#include <rice/p2p/past/PastImpl_getHandles_5.hpp>
#include <rice/p2p/past/PastImpl_doInsert_6.hpp>
#include <rice/p2p/past/PastImpl_insert_7.hpp>
#include <rice/p2p/past/PastImpl_insert_8.hpp>
#include <rice/p2p/past/PastImpl_lookup_9.hpp>
#include <rice/p2p/past/PastImpl_lookupHandles_10.hpp>
#include <rice/p2p/past/PastImpl_deliver_11.hpp>
#include <rice/p2p/past/PastImpl_deliver_12.hpp>
#include <rice/p2p/past/PastImpl_deliver_13.hpp>
#include <rice/p2p/past/PastImpl_fetch_14.hpp>
#include <rice/p2p/past/PastImpl_remove_15.hpp>
#include <rice/p2p/past/PastImpl_existsInOverlay_16.hpp>
#include <rice/p2p/past/PastImpl_reInsert_17.hpp>
#include <rice/p2p/past/PastImpl_PastImpl_1.hpp>
#include <rice/p2p/past/PastImpl_PastDeserializer.hpp>
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy.hpp>
#include <rice/p2p/past/PastPolicy.hpp>
#include <rice/p2p/past/messaging/CacheMessage.hpp>
#include <rice/p2p/past/messaging/ContinuationMessage.hpp>
#include <rice/p2p/past/messaging/FetchHandleMessage.hpp>
#include <rice/p2p/past/messaging/FetchMessage.hpp>
#include <rice/p2p/past/messaging/InsertMessage.hpp>
#include <rice/p2p/past/messaging/LookupHandlesMessage.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>
#include <rice/p2p/past/messaging/MessageLostMessage.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>
#include <rice/p2p/past/rawserialization/DefaultSocketStrategy.hpp>
#include <rice/p2p/past/rawserialization/JavaPastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/JavaPastContentHandleDeserializer.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/PastContentHandleDeserializer.hpp>
#include <rice/p2p/past/rawserialization/SocketStrategy.hpp>
#include <rice/p2p/replication/Replication.hpp>
#include <rice/p2p/replication/manager/ReplicationManager.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/LockManager.hpp>
#include <rice/persistence/LockManagerImpl.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

namespace rice
{
typedef ::SubArray< ::rice::Continuation, ::java::lang::ObjectArray > ContinuationArray;
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

rice::p2p::past::PastImpl::PastImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::PastImpl::PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance) 
    : PastImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,manager,replicas,instance);
}

rice::p2p::past::PastImpl::PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy) 
    : PastImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,manager,replicas,instance,policy);
}

rice::p2p::past::PastImpl::PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash) 
    : PastImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,manager,backup,replicas,instance,policy,trash);
}

rice::p2p::past::PastImpl::PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, bool useOwnSocket) 
    : PastImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,manager,backup,replicas,instance,policy,trash,useOwnSocket);
}

rice::p2p::past::PastImpl::PastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, ::rice::p2p::past::rawserialization::SocketStrategy* strategy) 
    : PastImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,manager,backup,replicas,instance,policy,trash,strategy);
}

void rice::p2p::past::PastImpl::init()
{
    inserts = int32_t(0);
    lookups = int32_t(0);
    fetchHandles = int32_t(0);
    other = int32_t(0);
    pendingSocketTransactions = new ::java::util::WeakHashMap();
}

void rice::p2p::past::PastImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance)
{
    ctor(node, manager, replicas, instance, new PastPolicy_DefaultPastPolicy());
}

void rice::p2p::past::PastImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy)
{
    ctor(node, manager, nullptr, replicas, instance, policy, nullptr);
}

void rice::p2p::past::PastImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash)
{
    ctor(node, manager, backup, replicas, instance, policy, trash, false);
}

void rice::p2p::past::PastImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, bool useOwnSocket)
{
    ctor(node, manager, backup, replicas, instance, policy, trash, static_cast< ::rice::p2p::past::rawserialization::SocketStrategy* >(new ::rice::p2p::past::rawserialization::DefaultSocketStrategy(useOwnSocket)));
}

void rice::p2p::past::PastImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, PastPolicy* policy, ::rice::persistence::StorageManager* trash, ::rice::p2p::past::rawserialization::SocketStrategy* strategy)
{
    super::ctor();
    init();
    this->environment = npc(node)->getEnvironment();
    logger = npc(npc(environment)->getLogManager())->getLogger(getClass(), instance);
    auto p = npc(environment)->getParameters();
    MESSAGE_TIMEOUT = npc(p)->getInt(u"p2p_past_messageTimeout"_j);
    SUCCESSFUL_INSERT_THRESHOLD = npc(p)->getDouble(u"p2p_past_successfulInsertThreshold"_j);
    this->socketStrategy = strategy;
    this->storage = manager;
    this->backup = backup;
    this->contentDeserializer = new ::rice::p2p::past::rawserialization::JavaPastContentDeserializer();
    this->contentHandleDeserializer = new ::rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer();
    this->endpoint = npc(node)->buildEndpoint(this, instance);
    npc(this->endpoint)->setDeserializer(new PastImpl_PastDeserializer(this));
    this->factory = npc(node)->getIdFactory();
    this->policy = policy;
    this->instance = instance;
    this->trash = trash;
    this->id = ::java::lang::Integer::MIN_VALUE;
    this->outstanding = new ::java::util::Hashtable();
    this->timers = new ::java::util::Hashtable();
    this->replicationFactor = replicas;
    this->replicaManager = buildReplicationManager(node, instance);
    this->lockManager = new ::rice::persistence::LockManagerImpl(environment);
    npc(this->endpoint)->accept(new PastImpl_PastImpl_1(this));
    npc(endpoint)->register_();
}

java::lang::String* rice::p2p::past::PastImpl::toString()
{
    if(endpoint == nullptr)
        return super::toString();

    return ::java::lang::StringBuilder().append(u"PastImpl["_j)->append(npc(endpoint)->getInstance())
        ->append(u"]"_j)->toString();
}

rice::environment::Environment* rice::p2p::past::PastImpl::getEnvironment()
{
    return environment;
}

rice::p2p::replication::manager::ReplicationManager* rice::p2p::past::PastImpl::buildReplicationManager(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance)
{
    return new ::rice::p2p::replication::manager::ReplicationManagerImpl(node, this, replicationFactor, instance);
}

rice::ContinuationArray* rice::p2p::past::PastImpl::getOutstandingMessages()
{
    return java_cast< ::rice::ContinuationArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(outstanding)->values())->toArray_(new ::rice::ContinuationArray(int32_t(0)))));
}

rice::p2p::commonapi::Endpoint* rice::p2p::past::PastImpl::getEndpoint()
{
    return endpoint;
}

int32_t rice::p2p::past::PastImpl::getUID()
{
    return id++;
}

rice::Continuation* rice::p2p::past::PastImpl::getResponseContinuation(::rice::p2p::past::messaging::PastMessage* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Getting the Continuation to respond to the message "_j)->append(static_cast< ::java::lang::Object* >(msg))->toString());

    auto const cmsg = java_cast< ::rice::p2p::past::messaging::ContinuationMessage* >(msg);
    return new PastImpl_getResponseContinuation_2(this, cmsg, msg);
}

rice::Continuation* rice::p2p::past::PastImpl::getFetchResponseContinuation(::rice::p2p::past::messaging::PastMessage* msg)
{
    auto const cmsg = java_cast< ::rice::p2p::past::messaging::ContinuationMessage* >(msg);
    return new PastImpl_getFetchResponseContinuation_3(this, cmsg, msg);
}

void rice::p2p::past::PastImpl::sendViaSocket(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::past::messaging::PastMessage* m, ::rice::Continuation* c)
{
    if(c != nullptr) {
        auto timer = npc(endpoint)->scheduleMessage(new ::rice::p2p::past::messaging::MessageLostMessage(npc(m)->getUID(), getLocalNodeHandle(), nullptr, m, handle), MESSAGE_TIMEOUT);
        insertPending(npc(m)->getUID(), timer, c);
    }
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    try {
        npc(sob)->writeInt(int32_t(0));
        npc(sob)->writeShort(npc(m)->getType());
        npc(m)->serialize(static_cast< ::rice::p2p::commonapi::rawserialization::OutputBuffer* >(sob));
    } catch (::java::io::IOException* ioe) {
        if(c != nullptr)
            npc(c)->receiveException(ioe);

    }
    auto size = npc(sob)->getWritten() - int32_t(4);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Sending size of "_j)->append(size)
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u" to send "_j)
            ->append(static_cast< ::java::lang::Object* >(m))->toString());

    auto bytes = npc(sob)->getBytes();
    ::rice::p2p::util::MathUtils::intToByteArray_(size, bytes, 0);
    auto const bb = new ::java::nio::ByteBufferArray(int32_t(1));
    bb->set(int32_t(0), ::java::nio::ByteBuffer::wrap(bytes, 0, npc(sob)->getWritten()));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Opening socket to "_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u" to send "_j)
            ->append(static_cast< ::java::lang::Object* >(m))->toString());

    npc(endpoint)->connect(handle, new PastImpl_sendViaSocket_4(this, handle, m, bb, c), 10000);
}

void rice::p2p::past::PastImpl::sendRequest(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::messaging::PastMessage* message, ::rice::Continuation* command)
{
    sendRequest(id, message, nullptr, command);
}

void rice::p2p::past::PastImpl::sendRequest(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::past::messaging::PastMessage* message, ::rice::Continuation* command)
{
    sendRequest(nullptr, message, handle, command);
}

void rice::p2p::past::PastImpl::sendRequest(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::messaging::PastMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Sending request message "_j)->append(static_cast< ::java::lang::Object* >(message))
            ->append(u" {"_j)
            ->append(npc(message)->getUID())
            ->append(u"} to id "_j)
            ->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" via "_j)
            ->append(static_cast< ::java::lang::Object* >(hint))->toString());

    auto timer = npc(endpoint)->scheduleMessage(new ::rice::p2p::past::messaging::MessageLostMessage(npc(message)->getUID(), getLocalNodeHandle(), id, message, hint), MESSAGE_TIMEOUT);
    insertPending(npc(message)->getUID(), timer, command);
    npc(endpoint)->route(id, static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message), hint);
}

void rice::p2p::past::PastImpl::insertPending(int32_t uid, ::rice::p2p::commonapi::CancellableTask* timer, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Loading continuation "_j)->append(uid)
            ->append(u" into pending table"_j)->toString());

    npc(timers)->put(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(uid)), static_cast< ::java::lang::Object* >(timer));
    npc(outstanding)->put(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(uid)), static_cast< ::java::lang::Object* >(command));
}

rice::Continuation* rice::p2p::past::PastImpl::removePending(int32_t uid)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Removing and returning continuation "_j)->append(uid)
            ->append(u" from pending table"_j)->toString());

    auto timer = java_cast< ::rice::p2p::commonapi::CancellableTask* >(java_cast< ::java::lang::Object* >(npc(timers)->remove(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(uid)))));
    if(timer != nullptr)
        npc(timer)->cancel();

    return java_cast< ::rice::Continuation* >(java_cast< ::java::lang::Object* >(npc(outstanding)->remove(static_cast< ::java::lang::Object* >(new ::java::lang::Integer(uid)))));
}

void rice::p2p::past::PastImpl::handleResponse(::rice::p2p::past::messaging::PastMessage* message)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handling reponse message "_j)->append(static_cast< ::java::lang::Object* >(message))
            ->append(u" from the request"_j)->toString());

    auto command = removePending(npc(message)->getUID());
    if(command != nullptr) {
        npc(message)->returnResponse(command, environment, instance);
    }
}

void rice::p2p::past::PastImpl::getHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command)
{
    auto set = npc(endpoint)->replicaSet(id, max);
    if(npc(set)->size() == max) {
        npc(command)->receiveResult(set);
    } else {
        sendRequest(id, static_cast< ::rice::p2p::past::messaging::PastMessage* >(new ::rice::p2p::past::messaging::LookupHandlesMessage(getUID(), id, max, getLocalNodeHandle(), id)), static_cast< ::rice::Continuation* >(new PastImpl_getHandles_5(this, max, command)));
    }
}

void rice::p2p::past::PastImpl::cache(PastContent* content)
{
    cache(content, new ::rice::Continuation_ListenerContinuation(::java::lang::StringBuilder().append(u"Caching of "_j)->append(static_cast< ::java::lang::Object* >(content))->toString(), environment));
}

void rice::p2p::past::PastImpl::cache(PastContent* content, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Inserting PastContent object "_j)->append(static_cast< ::java::lang::Object* >(content))
            ->append(u" into cache"_j)->toString());

    if((content != nullptr) && (!npc(content)->isMutable()))
        npc(storage)->cache(npc(content)->getId(), nullptr, content, command);
    else
        npc(command)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::p2p::past::PastImpl::doInsert(::rice::p2p::commonapi::Id* id, PastImpl_MessageBuilder* builder, ::rice::Continuation* command, bool useSocket)
{
    getHandles(id, replicationFactor + int32_t(1), new PastImpl_doInsert_6(this, id, builder, useSocket, command));
}

void rice::p2p::past::PastImpl::insert(PastContent* obj, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Inserting the object "_j)->append(static_cast< ::java::lang::Object* >(obj))
            ->append(u" with the id "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(obj)->getId()))->toString());

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u" Inserting data of class "_j)->append(npc(npc(obj)->getClass())->getName())
            ->append(u" under "_j)
            ->append(npc(npc(obj)->getId())->toStringFull())->toString());

    doInsert(npc(obj)->getId(), new PastImpl_insert_7(this, obj), new PastImpl_insert_8(this, obj, command), npc(socketStrategy)->sendAlongSocket(::rice::p2p::past::rawserialization::SocketStrategy::TYPE_INSERT, obj));
}

void rice::p2p::past::PastImpl::lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    lookup(id, true, static_cast< ::rice::Continuation* >(command));
}

void rice::p2p::past::PastImpl::lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u" Performing lookup on "_j)->append(npc(id)->toStringFull())->toString());

    npc(storage)->getObject(id, new PastImpl_lookup_9(this, command, id, cache, command));
}

void rice::p2p::past::PastImpl::lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Retrieving handles of up to "_j)->append(max)
            ->append(u" replicas of the object stored in Past with id "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString());

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Fetching up to "_j)->append(max)
            ->append(u" handles of "_j)
            ->append(npc(id)->toStringFull())->toString());

    getHandles(id, max, new PastImpl_lookupHandles_10(this, id, command));
}

void rice::p2p::past::PastImpl::lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Retrieving handle for id "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" from node "_j)
            ->append(static_cast< ::java::lang::Object* >(handle))->toString());

    sendRequest(handle, static_cast< ::rice::p2p::past::messaging::PastMessage* >(new ::rice::p2p::past::messaging::FetchHandleMessage(getUID(), id, getLocalNodeHandle(), npc(handle)->getId())), static_cast< ::rice::Continuation* >(new ::rice::Continuation_NamedContinuation(::java::lang::StringBuilder().append(u"FetchHandleMessage to "_j)->append(static_cast< ::java::lang::Object* >(handle))
        ->append(u" for "_j)
        ->append(static_cast< ::java::lang::Object* >(id))->toString(), command)));
}

void rice::p2p::past::PastImpl::fetch(PastContentHandle* handle, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Retrieving object associated with content handle "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Fetching object under id "_j)->append(npc(npc(handle)->getId())->toStringFull())
            ->append(u" on "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getNodeHandle()))->toString());

    auto han = npc(handle)->getNodeHandle();
    sendRequest(han, static_cast< ::rice::p2p::past::messaging::PastMessage* >(new ::rice::p2p::past::messaging::FetchMessage(getUID(), handle, getLocalNodeHandle(), npc(han)->getId())), static_cast< ::rice::Continuation* >(new ::rice::Continuation_NamedContinuation(::java::lang::StringBuilder().append(u"FetchMessage to "_j)->append(static_cast< ::java::lang::Object* >(npc(handle)->getNodeHandle()))
        ->append(u" for "_j)
        ->append(static_cast< ::java::lang::Object* >(npc(handle)->getId()))->toString(), command)));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::PastImpl::getLocalNodeHandle()
{
    return npc(endpoint)->getLocalNodeHandle();
}

int32_t rice::p2p::past::PastImpl::getReplicationFactor()
{
    return replicationFactor;
}

bool rice::p2p::past::PastImpl::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    ::rice::p2p::commonapi::Message* internal;
    try {
        internal = npc(message)->getMessage(npc(endpoint)->getDeserializer());
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
    if(dynamic_cast< ::rice::p2p::past::messaging::LookupMessage* >(internal) != nullptr) {
        auto const lmsg = java_cast< ::rice::p2p::past::messaging::LookupMessage* >(internal);
        auto id = npc(lmsg)->getId();
        if(!npc(lmsg)->isResponse()) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Lookup message "_j)->append(static_cast< ::java::lang::Object* >(lmsg))
                    ->append(u" is a request; look in the cache"_j)->toString());

            if(npc(storage)->exists(id)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Request for "_j)->append(static_cast< ::java::lang::Object* >(id))
                        ->append(u" satisfied locally - responding"_j)->toString());

                deliver(npc(endpoint)->getId(), static_cast< ::rice::p2p::commonapi::Message* >(lmsg));
                return false;
            }
        }
    } else if(dynamic_cast< ::rice::p2p::past::messaging::LookupHandlesMessage* >(internal) != nullptr) {
        auto lmsg = java_cast< ::rice::p2p::past::messaging::LookupHandlesMessage* >(internal);
        if(!npc(lmsg)->isResponse()) {
            if(npc(npc(endpoint)->replicaSet(npc(lmsg)->getId(), npc(lmsg)->getMax()))->size() == npc(lmsg)->getMax()) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Hijacking lookup handles request for "_j)->append(static_cast< ::java::lang::Object* >(npc(lmsg)->getId()))->toString());

                deliver(npc(endpoint)->getId(), static_cast< ::rice::p2p::commonapi::Message* >(lmsg));
                return false;
            }
        }
    }
    return true;
}

void rice::p2p::past::PastImpl::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    auto const msg = java_cast< ::rice::p2p::past::messaging::PastMessage* >(message);
    if(npc(msg)->isResponse()) {
        handleResponse(java_cast< ::rice::p2p::past::messaging::PastMessage* >(message));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received message "_j)->append(static_cast< ::java::lang::Object* >(message))
                ->append(u" with destination "_j)
                ->append(static_cast< ::java::lang::Object* >(id))->toString());

        if(dynamic_cast< ::rice::p2p::past::messaging::InsertMessage* >(msg) != nullptr) {
            auto const imsg = java_cast< ::rice::p2p::past::messaging::InsertMessage* >(msg);
            if(npc(policy)->allowInsert(npc(imsg)->getContent())) {
                inserts++;
                auto const msgid = npc(npc(imsg)->getContent())->getId();
                npc(lockManager)->lock(msgid, new PastImpl_deliver_11(this, msgid, imsg, msg, getResponseContinuation(msg)));
            } else {
                npc(getResponseContinuation(msg))->receiveResult(new ::java::lang::Boolean(false));
            }
        } else if(dynamic_cast< ::rice::p2p::past::messaging::LookupMessage* >(msg) != nullptr) {
            auto const lmsg = java_cast< ::rice::p2p::past::messaging::LookupMessage* >(msg);
            lookups++;
            npc(storage)->getObject(npc(lmsg)->getId(), new PastImpl_deliver_12(this, lmsg, getResponseContinuation(lmsg)));
        } else if(dynamic_cast< ::rice::p2p::past::messaging::LookupHandlesMessage* >(msg) != nullptr) {
            auto lmsg = java_cast< ::rice::p2p::past::messaging::LookupHandlesMessage* >(msg);
            auto set = npc(endpoint)->replicaSet(npc(lmsg)->getId(), npc(lmsg)->getMax());
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Returning replica set "_j)->append(static_cast< ::java::lang::Object* >(set))
                    ->append(u" for lookup handles of id "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(lmsg)->getId()))
                    ->append(u" max "_j)
                    ->append(npc(lmsg)->getMax())
                    ->append(u" at "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString());

            npc(getResponseContinuation(msg))->receiveResult(set);
        } else if(dynamic_cast< ::rice::p2p::past::messaging::FetchMessage* >(msg) != nullptr) {
            auto fmsg = java_cast< ::rice::p2p::past::messaging::FetchMessage* >(msg);
            lookups++;
            ::rice::Continuation* c;
            c = getFetchResponseContinuation(msg);
            npc(storage)->getObject(npc(npc(fmsg)->getHandle())->getId(), c);
        } else if(dynamic_cast< ::rice::p2p::past::messaging::FetchHandleMessage* >(msg) != nullptr) {
            auto const fmsg = java_cast< ::rice::p2p::past::messaging::FetchHandleMessage* >(msg);
            fetchHandles++;
            npc(storage)->getObject(npc(fmsg)->getId(), new PastImpl_deliver_13(this, fmsg, getResponseContinuation(msg)));
        } else if(dynamic_cast< ::rice::p2p::past::messaging::CacheMessage* >(msg) != nullptr) {
            cache(npc((java_cast< ::rice::p2p::past::messaging::CacheMessage* >(msg)))->getContent());
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"ERROR - Received message "_j)->append(static_cast< ::java::lang::Object* >(msg))
                    ->append(u"of unknown type."_j)->toString());

        }
    }
}

void rice::p2p::past::PastImpl::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

void rice::p2p::past::PastImpl::fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Sending out replication fetch request for the id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

    npc(policy)->fetch(id, hint, backup, this, new PastImpl_fetch_14(this, id, command));
}

void rice::p2p::past::PastImpl::remove(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    if(backup != nullptr) {
        npc(storage)->getObject(id, new PastImpl_remove_15(this, id, command));
    } else {
        npc(storage)->unstore(id, command);
    }
}

rice::p2p::commonapi::IdSet* rice::p2p::past::PastImpl::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(npc(storage)->getStorage())->scan(range);
}

rice::p2p::commonapi::IdSet* rice::p2p::past::PastImpl::scan()
{
    return npc(npc(storage)->getStorage())->scan();
}

bool rice::p2p::past::PastImpl::exists(::rice::p2p::commonapi::Id* id)
{
    return npc(npc(storage)->getStorage())->exists(id);
}

void rice::p2p::past::PastImpl::existsInOverlay(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    lookupHandles(id, replicationFactor + int32_t(1), static_cast< ::rice::Continuation* >(new PastImpl_existsInOverlay_16(this, command)));
}

void rice::p2p::past::PastImpl::reInsert(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    npc(storage)->getObject(id, new PastImpl_reInsert_17(this, command));
}

rice::p2p::replication::Replication* rice::p2p::past::PastImpl::getReplication()
{
    return npc(replicaManager)->getReplication();
}

rice::persistence::StorageManager* rice::p2p::past::PastImpl::getStorageManager()
{
    return storage;
}

java::lang::String* rice::p2p::past::PastImpl::getInstance()
{
    return instance;
}

void rice::p2p::past::PastImpl::setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer)
{
    contentDeserializer = deserializer;
}

void rice::p2p::past::PastImpl::setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer)
{
    contentHandleDeserializer = deserializer;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.PastImpl", 22);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl::getClass0()
{
    return class_();
}

