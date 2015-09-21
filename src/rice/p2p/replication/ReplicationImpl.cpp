// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java
#include <rice/p2p/replication/ReplicationImpl.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/Continuation_MultiContinuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/RangeCannotBeDeterminedException.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>
#include <rice/p2p/replication/ReplicationImpl_deliver_3.hpp>
#include <rice/p2p/replication/ReplicationImpl_deliver_4.hpp>
#include <rice/p2p/replication/ReplicationImpl_ReplicationImpl_1.hpp>
#include <rice/p2p/replication/ReplicationImpl_replicate_2.hpp>
#include <rice/p2p/replication/ReplicationImpl_BloomFilterExecutable.hpp>
#include <rice/p2p/replication/ReplicationPolicy_DefaultReplicationPolicy.hpp>
#include <rice/p2p/replication/ReplicationPolicy.hpp>
#include <rice/p2p/replication/messaging/ReminderMessage.hpp>
#include <rice/p2p/replication/messaging/RequestMessage.hpp>
#include <rice/p2p/replication/messaging/ResponseMessage.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
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
typedef ::SubArray< ::rice::p2p::commonapi::IdRange, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdRangeArray;
typedef ::SubArray< ::rice::p2p::commonapi::IdArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > IdArrayArray;
        } // commonapi
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

rice::p2p::replication::ReplicationImpl::ReplicationImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::ReplicationImpl::ReplicationImpl(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance) 
    : ReplicationImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,client,replicationFactor,instance);
}

rice::p2p::replication::ReplicationImpl::ReplicationImpl(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance, ReplicationPolicy* policy) 
    : ReplicationImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,client,replicationFactor,instance,policy);
}

void rice::p2p::replication::ReplicationImpl::init()
{
    destroyed = false;
}

void rice::p2p::replication::ReplicationImpl::ctor(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance)
{
    ctor(node, client, replicationFactor, instance, new ReplicationPolicy_DefaultReplicationPolicy());
}

void rice::p2p::replication::ReplicationImpl::ctor(::rice::p2p::commonapi::Node* node, ReplicationClient* client, int32_t replicationFactor, ::java::lang::String* instance, ReplicationPolicy* policy)
{
    super::ctor();
    init();
    this->environment = npc(node)->getEnvironment();
    npc(environment)->addDestructable(this);
    logger = npc(npc(environment)->getLogManager())->getLogger(ReplicationImpl::class_(), instance);
    auto p = npc(environment)->getParameters();
    MAINTENANCE_INTERVAL = npc(p)->getInt(u"p2p_replication_maintenance_interval"_j);
    MAX_KEYS_IN_MESSAGE = npc(p)->getInt(u"p2p_replication_max_keys_in_message"_j);
    this->client = client;
    this->replicationFactor = replicationFactor;
    this->factory = npc(node)->getIdFactory();
    this->policy = policy;
    this->instance = instance;
    this->endpoint = npc(node)->buildEndpoint(this, instance);
    npc(endpoint)->setDeserializer(new ReplicationImpl_ReplicationImpl_1(this));
    if(this->policy == nullptr)
        this->policy = new ReplicationPolicy_DefaultReplicationPolicy();

    this->handle = npc(endpoint)->getLocalNodeHandle();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Starting up ReplicationImpl with client "_j)->append(static_cast< ::java::lang::Object* >(client))
            ->append(u" and factor "_j)
            ->append(replicationFactor)->toString());

    npc(endpoint)->register_();
    npc(endpoint)->scheduleMessage(new ::rice::p2p::replication::messaging::ReminderMessage(handle), npc(npc(environment)->getRandomSource())->nextInt(MAINTENANCE_INTERVAL), MAINTENANCE_INTERVAL);
}

rice::p2p::commonapi::IdSet* rice::p2p::replication::ReplicationImpl::merge(::rice::p2p::commonapi::IdFactory* factory, ::rice::p2p::commonapi::IdSet* a, ::rice::p2p::commonapi::IdSet* b)
{
    clinit();
    auto result = npc(factory)->buildIdSet();
    auto i = npc(a)->getIterator();
    while (npc(i)->hasNext()) {
        npc(result)->addId(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next())));
    }
    i = npc(b)->getIterator();
    while (npc(i)->hasNext()) {
        npc(result)->addId(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next())));
    }
    return result;
}

rice::p2p::commonapi::IdRange* rice::p2p::replication::ReplicationImpl::getTotalRange()
{
    try {
        return npc(endpoint)->range(handle, replicationFactor, npc(handle)->getId(), true);
    } catch (::rice::p2p::commonapi::RangeCannotBeDeterminedException* rcbde) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"ReplicationImpl.getTotalRange():"_j)->append(static_cast< ::java::lang::Object* >(rcbde))
                ->append(u" returning null."_j)->toString());

        return nullptr;
    }
}

void rice::p2p::replication::ReplicationImpl::updateClient()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Updating client with range "_j)->append(static_cast< ::java::lang::Object* >(getTotalRange()))->toString());

    if(getTotalRange() != nullptr)
        npc(client)->setRange(getTotalRange());

}

void rice::p2p::replication::ReplicationImpl::replicate()
{
    auto const handles = npc(endpoint)->neighborSet(::java::lang::Integer::MAX_VALUE);
    auto const ourRange = npc(endpoint)->range(handle, 0, npc(handle)->getId());
    npc(endpoint)->process(new ReplicationImpl_BloomFilterExecutable(this, ourRange), new ReplicationImpl_replicate_2(this, handles, ourRange, u"Creation of our bloom filter"_j, environment));
}

bool rice::p2p::replication::ReplicationImpl::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void rice::p2p::replication::ReplicationImpl::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"COUNT: Replication "_j)->append(instance)
            ->append(u" received message "_j)
            ->append(static_cast< ::java::lang::Object* >(message))->toString());

    if(dynamic_cast< ::rice::p2p::replication::messaging::RequestMessage* >(message) != nullptr) {
        auto const rm = java_cast< ::rice::p2p::replication::messaging::RequestMessage* >(message);
        auto continuation = new ::rice::Continuation_MultiContinuation(new ReplicationImpl_deliver_3(this, rm, u"Processing of RequestMessage"_j, environment), npc(npc(rm)->getRanges())->length);
        for (auto i = int32_t(0); i < npc(npc(rm)->getRanges())->length; i++) {
            auto const j = i;
            npc(endpoint)->process(new ReplicationImpl_deliver_4(this, j, rm), npc(continuation)->getSubContinuation(i));
        }
    } else if(dynamic_cast< ::rice::p2p::replication::messaging::ResponseMessage* >(message) != nullptr) {
        auto rm = java_cast< ::rice::p2p::replication::messaging::ResponseMessage* >(message);
        for (auto i = int32_t(0); i < npc(npc(rm)->getIdSets())->length; i++) {
            auto temp = npc(factory)->buildIdSet();
            auto tempA = (*npc(rm)->getIdSets())[i];
            for (auto j = int32_t(0); j < npc(tempA)->length; j++) {
                npc(temp)->addId((*tempA)[j]);
            }
            auto fetch = npc(policy)->difference(npc(client)->scan((*npc(rm)->getRanges())[i]), temp, factory);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"COUNT: Was told to fetch "_j)->append(npc(fetch)->numElements())
                    ->append(u" in instance "_j)
                    ->append(instance)->toString());

            if(npc(fetch)->numElements() > 0)
                npc(client)->fetch(fetch, npc(rm)->getSource());

        }
    } else if(dynamic_cast< ::rice::p2p::replication::messaging::ReminderMessage* >(message) != nullptr) {
        replicate();
        updateClient();
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received unknown message "_j)->append(static_cast< ::java::lang::Object* >(message))
                ->append(u" - dropping on floor."_j)->toString());

    }
}

void rice::p2p::replication::ReplicationImpl::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
    updateClient();
}

void rice::p2p::replication::ReplicationImpl::destroy()
{
    destroyed = true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.ReplicationImpl", 36);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationImpl::getClass0()
{
    return class_();
}

