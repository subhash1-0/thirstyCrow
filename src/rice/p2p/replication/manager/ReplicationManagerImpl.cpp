// Generated from /pastry-2.1/src/rice/p2p/replication/manager/ReplicationManagerImpl.java
#include <rice/p2p/replication/manager/ReplicationManagerImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/replication/ReplicationImpl.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl_informClient_1.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerDeleter.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl_ReplicationManagerHelper.hpp>
#include <rice/p2p/replication/manager/messaging/ReminderMessage.hpp>
#include <rice/p2p/replication/manager/messaging/TimeoutMessage.hpp>

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

rice::p2p::replication::manager::ReplicationManagerImpl::ReplicationManagerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::manager::ReplicationManagerImpl::ReplicationManagerImpl(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance) 
    : ReplicationManagerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,client,replicationFactor,instance);
}

rice::p2p::replication::manager::ReplicationManagerImpl::ReplicationManagerImpl(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance, ::rice::p2p::replication::ReplicationPolicy* policy) 
    : ReplicationManagerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,client,replicationFactor,instance,policy);
}

void rice::p2p::replication::manager::ReplicationManagerImpl::ctor(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance)
{
    ctor(node, client, replicationFactor, instance, nullptr);
}

void rice::p2p::replication::manager::ReplicationManagerImpl::ctor(::rice::p2p::commonapi::Node* node, ReplicationManagerClient* client, int32_t replicationFactor, ::java::lang::String* instance, ::rice::p2p::replication::ReplicationPolicy* policy)
{
    super::ctor();
    this->environment = npc(node)->getEnvironment();
    logger = npc(npc(environment)->getLogManager())->getLogger(ReplicationManagerImpl::class_(), instance);
    auto p = npc(environment)->getParameters();
    FETCH_DELAY = npc(p)->getInt(u"p2p_replication_manager_fetch_delay"_j);
    TIMEOUT_DELAY = npc(p)->getInt(u"p2p_replication_manager_timeout_delay"_j);
    NUM_DELETE_AT_ONCE = npc(p)->getInt(u"p2p_replication_manager_num_delete_at_once"_j);
    this->client = client;
    this->factory = npc(node)->getIdFactory();
    this->endpoint = npc(node)->buildEndpoint(this, instance);
    this->helper = new ReplicationManagerImpl_ReplicationManagerHelper(this);
    this->deleter = new ReplicationManagerImpl_ReplicationManagerDeleter(this);
    this->instance = instance;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Starting up ReplicationManagerImpl with client "_j)->append(static_cast< ::java::lang::Object* >(client))->toString());

    this->replication = new ::rice::p2p::replication::ReplicationImpl(node, this, replicationFactor, instance, policy);
    npc(endpoint)->register_();
}

rice::p2p::commonapi::IdSet* rice::p2p::replication::manager::ReplicationManagerImpl::clone(::rice::p2p::commonapi::IdSet* keySet)
{
    auto result = npc(factory)->buildIdSet();
    auto i = npc(keySet)->getIterator();
    while (npc(i)->hasNext()) {
        npc(result)->addId(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next())));
    }
    return result;
}

void rice::p2p::replication::manager::ReplicationManagerImpl::informClient(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Telling client to fetch id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString());

    auto const timer = npc(endpoint)->scheduleMessage(new ::rice::p2p::replication::manager::messaging::TimeoutMessage(id), TIMEOUT_DELAY);
    npc(client)->fetch(id, hint, new ReplicationManagerImpl_informClient_1(this, id, timer));
}

void rice::p2p::replication::manager::ReplicationManagerImpl::scheduleNext()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Scheduling next fetch in "_j)->append(FETCH_DELAY)
            ->append(u" milliseconds"_j)->toString());

    npc(endpoint)->scheduleMessage(new ::rice::p2p::replication::manager::messaging::ReminderMessage(), FETCH_DELAY);
}

void rice::p2p::replication::manager::ReplicationManagerImpl::fetch(::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::NodeHandle* hint)
{
    npc(helper)->fetch(keySet, hint);
}

void rice::p2p::replication::manager::ReplicationManagerImpl::setRange(::rice::p2p::commonapi::IdRange* range)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Removing range "_j)->append(static_cast< ::java::lang::Object* >(range))
            ->append(u" from the list of pending ids"_j)->toString());

    npc(helper)->setRange(range);
    npc(deleter)->setRange(range);
}

rice::p2p::commonapi::IdSet* rice::p2p::replication::manager::ReplicationManagerImpl::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(client)->scan(range);
}

bool rice::p2p::replication::manager::ReplicationManagerImpl::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void rice::p2p::replication::manager::ReplicationManagerImpl::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(dynamic_cast< ::rice::p2p::replication::manager::messaging::ReminderMessage* >(message) != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(u"Received reminder message"_j);

        npc(helper)->wakeup();
    } else if(dynamic_cast< ::rice::p2p::replication::manager::messaging::TimeoutMessage* >(message) != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(u"Received timeout message"_j);

        npc(helper)->message(npc((java_cast< ::rice::p2p::replication::manager::messaging::TimeoutMessage* >(message)))->getId());
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received unknown message "_j)->append(static_cast< ::java::lang::Object* >(message))->toString());

    }
}

void rice::p2p::replication::manager::ReplicationManagerImpl::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

rice::p2p::replication::Replication* rice::p2p::replication::manager::ReplicationManagerImpl::getReplication()
{
    return replication;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.manager.ReplicationManagerImpl", 51);
    return c;
}

java::lang::Object* rice::p2p::replication::manager::ReplicationManagerImpl::clone()
{
    return super::clone();
}

java::lang::Class* rice::p2p::replication::manager::ReplicationManagerImpl::getClass0()
{
    return class_();
}

