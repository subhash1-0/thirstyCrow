// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation_StandardContinuation.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastPolicy.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdRange.hpp>
#include <rice/p2p/past/gc/GCIdSet.hpp>
#include <rice/p2p/past/gc/GCNode.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_2.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_4.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_5.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_6.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_7.hpp>
#include <rice/p2p/past/gc/GCPastImpl_collect_8.hpp>
#include <rice/p2p/past/gc/GCPastImpl_fetch_9.hpp>
#include <rice/p2p/past/gc/GCPastImpl_fetch_10.hpp>
#include <rice/p2p/past/gc/GCPastImpl_reInsert_11.hpp>
#include <rice/p2p/past/gc/GCPastImpl_insert_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl_GCPastDeserializer.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
#include <rice/p2p/past/gc/messaging/GCCollectMessage.hpp>
#include <rice/p2p/past/gc/messaging/GCInsertMessage.hpp>
#include <rice/p2p/past/gc/messaging/GCLookupHandlesMessage.hpp>
#include <rice/p2p/past/gc/messaging/GCRefreshMessage.hpp>
#include <rice/p2p/past/messaging/FetchHandleMessage.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>
#include <rice/p2p/past/rawserialization/SocketStrategy.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <Array.hpp>
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
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi

        namespace past
        {
            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCId, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > GCIdArray;
            } // gc
        } // past
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

rice::p2p::past::gc::GCPastImpl::GCPastImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCPastImpl::GCPastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval) 
    : GCPastImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,manager,replicas,instance,policy,collectionInterval);
}

rice::p2p::past::gc::GCPastImpl::GCPastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval, ::rice::persistence::StorageManager* trash) 
    : GCPastImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,manager,backup,replicas,instance,policy,collectionInterval,trash);
}

void rice::p2p::past::gc::GCPastImpl::init()
{
    collected = int32_t(0);
    refreshed = int32_t(0);
}

constexpr int64_t rice::p2p::past::gc::GCPastImpl::DEFAULT_EXPIRATION;

java::lang::String* rice::p2p::past::gc::GCPastImpl::toString()
{
    if(endpoint == nullptr)
        return super::toString();

    return ::java::lang::StringBuilder().append(u"GCPastImpl["_j)->append(npc(endpoint)->getInstance())
        ->append(u"]"_j)->toString();
}

void rice::p2p::past::gc::GCPastImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval)
{
    ctor(node, manager, nullptr, replicas, instance, policy, collectionInterval, nullptr);
}

void rice::p2p::past::gc::GCPastImpl::ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval, ::rice::persistence::StorageManager* trash)
{
    super::ctor(new GCNode(node), manager, backup, replicas, instance, policy, trash);
    init();
    this->realFactory = npc(node)->getIdFactory();
    npc(endpoint)->scheduleMessage(new ::rice::p2p::past::gc::messaging::GCCollectMessage(int32_t(0), getLocalNodeHandle(), npc(node)->getId()), collectionInterval, collectionInterval);
    npc(endpoint)->setDeserializer(new GCPastImpl_GCPastDeserializer(this));
}

void rice::p2p::past::gc::GCPastImpl::insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command)
{
    insert(obj, INFINITY_EXPIRATION, command);
}

void rice::p2p::past::gc::GCPastImpl::insert(::rice::p2p::past::PastContent* obj, int64_t expiration, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Inserting data of class "_j)->append(npc(npc(obj)->getClass())->getName())
            ->append(u" under "_j)
            ->append(npc(npc(obj)->getId())->toStringFull())->toString());

    doInsert(npc(obj)->getId(), new GCPastImpl_insert_1(this, obj, expiration), command, npc(socketStrategy)->sendAlongSocket(::rice::p2p::past::rawserialization::SocketStrategy::TYPE_INSERT, obj));
}

void rice::p2p::past::gc::GCPastImpl::refresh(::rice::p2p::commonapi::IdArray* array, int64_t expiration, ::rice::Continuation* command)
{
    auto expirations = new ::int64_tArray(npc(array)->length);
    ::java::util::Arrays::fill(expirations, expiration);
    refresh(array, expirations, command);
}

void rice::p2p::past::gc::GCPastImpl::refresh(::rice::p2p::commonapi::IdArray* array, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Refreshing "_j)->append(npc(array)->length)
            ->append(u" data elements"_j)->toString());

    auto set = new GCIdSet(realFactory);
    for (auto i = int32_t(0); i < npc(array)->length; i++) 
                npc(set)->addId(static_cast< ::rice::p2p::commonapi::Id* >(new GCId((*array)[i], (*expirations)[i])));

    refresh(set, new GCPastImpl_refresh_2(this, array, command));
}

void rice::p2p::past::gc::GCPastImpl::refresh(GCIdSet* ids, ::rice::Continuation* command)
{
    auto const logger = npc(npc(environment)->getLogManager())->getLogger(GCPastImpl::class_(), instance);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"REFRESH: CALLED WITH "_j)->append(npc(ids)->numElements())
            ->append(u" ELEMENTS"_j)->toString());

    if(npc(ids)->numElements() == 0) {
        npc(command)->receiveResult(new ::java::lang::ObjectArray(int32_t(0)));
        return;
    }
    auto const array = npc(ids)->asArray_();
    auto start = java_cast< GCId* >((*array)[int32_t(0)]);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"REFRESH: GETTINGS ALL HANDLES OF "_j)->append(static_cast< ::java::lang::Object* >(start))->toString());

    sendRequest(npc(start)->getId(), static_cast< ::rice::p2p::past::messaging::PastMessage* >(new ::rice::p2p::past::gc::messaging::GCLookupHandlesMessage(getUID(), npc(start)->getId(), getLocalNodeHandle(), npc(start)->getId())), static_cast< ::rice::Continuation* >(new GCPastImpl_refresh_3(this, logger, array, ids, ::java::lang::StringBuilder().append(u"GCLookupHandles for "_j)->append(static_cast< ::java::lang::Object* >(npc(start)->getId()))->toString(), command)));
}

bool rice::p2p::past::gc::GCPastImpl::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    try {
        if(dynamic_cast< ::rice::p2p::past::gc::messaging::GCLookupHandlesMessage* >(npc(message)->getMessage(npc(endpoint)->getDeserializer())) != nullptr)
            return true;
        else
            return super::forward(message);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

void rice::p2p::past::gc::GCPastImpl::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    auto const msg = java_cast< ::rice::p2p::past::messaging::PastMessage* >(message);
    if(npc(msg)->isResponse()) {
        super::deliver(id, message);
    } else {
        if(dynamic_cast< ::rice::p2p::past::gc::messaging::GCInsertMessage* >(msg) != nullptr) {
            auto const imsg = java_cast< ::rice::p2p::past::gc::messaging::GCInsertMessage* >(msg);
            inserts++;
            if(npc(policy)->allowInsert(npc(imsg)->getContent())) {
                auto theId = npc(npc(imsg)->getContent())->getId();
                if(theId == nullptr) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Error: null Id from "_j)->append(static_cast< ::java::lang::Object* >(npc(imsg)->getContent()))
                            ->append(u" from "_j)
                            ->append(static_cast< ::java::lang::Object* >(imsg))
                            ->append(u" in "_j)
                            ->append(static_cast< ::java::lang::Object* >(this))->toString());

                }
                npc(storage)->getObject(theId, new GCPastImpl_deliver_4(this, imsg, getResponseContinuation(msg)));
            } else {
                npc(getResponseContinuation(msg))->receiveResult(new ::java::lang::Boolean(false));
            }
        } else if(dynamic_cast< ::rice::p2p::past::gc::messaging::GCRefreshMessage* >(msg) != nullptr) {
            auto const rmsg = java_cast< ::rice::p2p::past::gc::messaging::GCRefreshMessage* >(msg);
            auto const i = npc(::java::util::Arrays::asList(npc(rmsg)->getKeys()))->iterator();
            auto const result = new ::java::util::Vector();
            other += npc(npc(rmsg)->getKeys())->length;
            ::rice::Continuation_StandardContinuation* process = new GCPastImpl_deliver_5(this, result, i, getResponseContinuation(msg));
            npc(process)->receiveResult(nullptr);
        } else if(dynamic_cast< ::rice::p2p::past::gc::messaging::GCLookupHandlesMessage* >(msg) != nullptr) {
            auto lmsg = java_cast< ::rice::p2p::past::gc::messaging::GCLookupHandlesMessage* >(msg);
            auto set = npc(endpoint)->neighborSet(npc(lmsg)->getMax());
            npc(set)->removeHandle(npc(getLocalNodeHandle())->getId());
            npc(set)->putHandle(getLocalNodeHandle());
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Returning neighbor set "_j)->append(static_cast< ::java::lang::Object* >(set))
                    ->append(u" for lookup handles of id "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(lmsg)->getId()))
                    ->append(u" max "_j)
                    ->append(npc(lmsg)->getMax())
                    ->append(u" at "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->toString());

            npc(getResponseContinuation(msg))->receiveResult(set);
        } else if(dynamic_cast< ::rice::p2p::past::gc::messaging::GCCollectMessage* >(msg) != nullptr) {
            collect(npc(storage)->scanMetadataValuesHead(new GCPastMetadata(npc(npc(environment)->getTimeSource())->currentTimeMillis())), new GCPastImpl_deliver_6(this, u"Removal of expired ids"_j, environment));
        } else if(dynamic_cast< ::rice::p2p::past::messaging::FetchHandleMessage* >(msg) != nullptr) {
            auto const fmsg = java_cast< ::rice::p2p::past::messaging::FetchHandleMessage* >(msg);
            fetchHandles++;
            npc(storage)->getObject(npc(fmsg)->getId(), new GCPastImpl_deliver_7(this, fmsg, getResponseContinuation(msg)));
        } else {
            super::deliver(id, message);
        }
    }
}

void rice::p2p::past::gc::GCPastImpl::collect(::java::util::SortedMap* map, ::rice::Continuation* command)
{
    auto const i = npc(npc(map)->keySet())->iterator();
    ::rice::Continuation* remove = new GCPastImpl_collect_8(this, i, command);
    npc(remove)->receiveResult(nullptr);
}

void rice::p2p::past::gc::GCPastImpl::fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Sending out replication fetch request for the id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

    auto const gcid = java_cast< GCId* >(id);
    if(npc(gcid)->getExpiration() < npc(npc(environment)->getTimeSource())->currentTimeMillis()) {
        npc(command)->receiveResult(::java::lang::Boolean::TRUE());
    } else if(npc(storage)->exists(npc(gcid)->getId())) {
        auto metadata = java_cast< GCPastMetadata* >(npc(storage)->getMetadata(npc(gcid)->getId()));
        if(metadata == nullptr) {
            npc(storage)->getObject(npc(gcid)->getId(), new GCPastImpl_fetch_9(this, gcid, command));
        } else if(npc(metadata)->getExpiration() < npc(gcid)->getExpiration()) {
            npc(storage)->setMetadata(npc(gcid)->getId(), npc(metadata)->setExpiration(npc(gcid)->getExpiration()), command);
        } else {
            npc(command)->receiveResult(::java::lang::Boolean::TRUE());
        }
    } else {
        npc(policy)->fetch(npc(gcid)->getId(), hint, backup, this, new GCPastImpl_fetch_10(this, id, gcid, command));
    }
}

void rice::p2p::past::gc::GCPastImpl::remove(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    super::remove(npc((java_cast< GCId* >(id)))->getId(), command);
}

rice::p2p::commonapi::IdSet* rice::p2p::past::gc::GCPastImpl::scan(::rice::p2p::commonapi::IdRange* range)
{
    auto gcRange = java_cast< GCIdRange* >(range);
    return new GCIdSet(npc(npc(storage)->getStorage())->scan(npc(gcRange)->getRange()), npc(npc(storage)->getStorage())->scanMetadata(npc(gcRange)->getRange()));
}

rice::p2p::commonapi::IdSet* rice::p2p::past::gc::GCPastImpl::scan()
{
    return new GCIdSet(npc(npc(storage)->getStorage())->scan(), npc(npc(storage)->getStorage())->scanMetadata());
}

bool rice::p2p::past::gc::GCPastImpl::exists(::rice::p2p::commonapi::Id* id)
{
    if(dynamic_cast< GCId* >(id) != nullptr)
        return npc(npc(storage)->getStorage())->exists(npc((java_cast< GCId* >(id)))->getId());
    else
        return npc(npc(storage)->getStorage())->exists(id);
}

void rice::p2p::past::gc::GCPastImpl::existsInOverlay(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    if(dynamic_cast< GCId* >(id) != nullptr) {
        super::existsInOverlay(npc((java_cast< GCId* >(id)))->getId(), command);
    } else {
        super::existsInOverlay(id, command);
    }
}

void rice::p2p::past::gc::GCPastImpl::reInsert(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    if(dynamic_cast< GCId* >(id) != nullptr) {
        npc(storage)->getObject(npc((java_cast< GCId* >(id)))->getId(), new GCPastImpl_reInsert_11(this, id, command));
    } else {
        auto metadata = java_cast< GCPastMetadata* >(npc(storage)->getMetadata(id));
        if(metadata == nullptr) {
            super::reInsert(id, command);
        } else {
            reInsert(static_cast< ::rice::p2p::commonapi::Id* >(new GCId(id, npc(metadata)->getExpiration())), command);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCPastImpl", 27);
    return c;
}

void rice::p2p::past::gc::GCPastImpl::fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command)
{
    PastImpl::fetch(handle, command);
}

rice::environment::Environment* rice::p2p::past::gc::GCPastImpl::getEnvironment()
{
    return PastImpl::getEnvironment();
}

java::lang::String* rice::p2p::past::gc::GCPastImpl::getInstance()
{
    return PastImpl::getInstance();
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::gc::GCPastImpl::getLocalNodeHandle()
{
    return PastImpl::getLocalNodeHandle();
}

int32_t rice::p2p::past::gc::GCPastImpl::getReplicationFactor()
{
    return PastImpl::getReplicationFactor();
}

void rice::p2p::past::gc::GCPastImpl::lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    PastImpl::lookup(id, command);
}

void rice::p2p::past::gc::GCPastImpl::lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command)
{
    PastImpl::lookup(id, cache, command);
}

void rice::p2p::past::gc::GCPastImpl::lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command)
{
    PastImpl::lookupHandle(id, handle, command);
}

void rice::p2p::past::gc::GCPastImpl::lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command)
{
    PastImpl::lookupHandles(id, max, command);
}

void rice::p2p::past::gc::GCPastImpl::setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer)
{
    PastImpl::setContentDeserializer(deserializer);
}

void rice::p2p::past::gc::GCPastImpl::setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer)
{
    PastImpl::setContentHandleDeserializer(deserializer);
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl::getClass0()
{
    return class_();
}

