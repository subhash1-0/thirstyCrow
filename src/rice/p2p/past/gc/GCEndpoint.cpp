// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCEndpoint.java
#include <rice/p2p/past/gc/GCEndpoint.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/List.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdRange.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCEndpoint::GCEndpoint(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCEndpoint::GCEndpoint(::rice::p2p::commonapi::Endpoint* endpoint) 
    : GCEndpoint(*static_cast< ::default_init_tag* >(0))
{
    ctor(endpoint);
}

void rice::p2p::past::gc::GCEndpoint::ctor(::rice::p2p::commonapi::Endpoint* endpoint)
{
    super::ctor();
    this->endpoint = endpoint;
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCEndpoint::getId()
{
    return npc(endpoint)->getId();
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::past::gc::GCEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint)
{
    return npc(endpoint)->route(id, message, hint);
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::past::gc::GCEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint)
{
    return npc(endpoint)->route(id, message, hint);
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::past::gc::GCEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe)
{
    return npc(endpoint)->route(id, message, hint, deliverAckToMe);
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::past::gc::GCEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe)
{
    return npc(endpoint)->route(id, message, hint, deliverAckToMe);
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::past::gc::GCEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    return npc(endpoint)->route(id, message, hint, deliverAckToMe, options);
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::past::gc::GCEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    return npc(endpoint)->route(id, message, hint, deliverAckToMe, options);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::past::gc::GCEndpoint::localLookup(::rice::p2p::commonapi::Id* id, int32_t num, bool safe)
{
    return npc(endpoint)->localLookup(id, num, safe);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::past::gc::GCEndpoint::neighborSet(int32_t num)
{
    return npc(endpoint)->neighborSet(num);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::past::gc::GCEndpoint::replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank)
{
    return npc(endpoint)->replicaSet(id, maxRank);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::past::gc::GCEndpoint::replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank, ::rice::p2p::commonapi::NodeHandle* root, ::rice::p2p::commonapi::NodeHandleSet* set)
{
    return npc(endpoint)->replicaSet(id, maxRank, root, set);
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCEndpoint::range(::rice::p2p::commonapi::NodeHandle* handle, int32_t rank, ::rice::p2p::commonapi::Id* lkey)
{
    auto range = npc(endpoint)->range(handle, rank, lkey);
    return (range == nullptr ? static_cast< ::rice::p2p::commonapi::IdRange* >(nullptr) : static_cast< ::rice::p2p::commonapi::IdRange* >(new GCIdRange(range)));
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCEndpoint::range(::rice::p2p::commonapi::NodeHandle* handle, int32_t rank, ::rice::p2p::commonapi::Id* lkey, bool cumulative)
{
    auto range = npc(endpoint)->range(handle, rank, lkey, cumulative);
    return (range == nullptr ? static_cast< ::rice::p2p::commonapi::IdRange* >(nullptr) : static_cast< ::rice::p2p::commonapi::IdRange* >(new GCIdRange(range)));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::gc::GCEndpoint::getLocalNodeHandle()
{
    return npc(endpoint)->getLocalNodeHandle();
}

java::util::List* rice::p2p::past::gc::GCEndpoint::networkNeighbors(int32_t num)
{
    return npc(endpoint)->networkNeighbors(num);
}

rice::p2p::commonapi::CancellableTask* rice::p2p::past::gc::GCEndpoint::scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay)
{
    return npc(endpoint)->scheduleMessage(message, delay);
}

rice::p2p::commonapi::CancellableTask* rice::p2p::past::gc::GCEndpoint::scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period)
{
    return npc(endpoint)->scheduleMessage(message, delay, period);
}

rice::p2p::commonapi::CancellableTask* rice::p2p::past::gc::GCEndpoint::scheduleMessageAtFixedRate(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period)
{
    return npc(endpoint)->scheduleMessageAtFixedRate(message, delay, period);
}

void rice::p2p::past::gc::GCEndpoint::process(::rice::Executable* task, ::rice::Continuation* command)
{
    npc(endpoint)->process(task, command);
}

java::lang::String* rice::p2p::past::gc::GCEndpoint::getInstance()
{
    return ::java::lang::StringBuilder().append(u"GC"_j)->append(npc(endpoint)->getInstance())->toString();
}

rice::environment::Environment* rice::p2p::past::gc::GCEndpoint::getEnvironment()
{
    return npc(endpoint)->getEnvironment();
}

void rice::p2p::past::gc::GCEndpoint::connect(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout)
{
    npc(endpoint)->connect(handle, receiver, timeout);
}

void rice::p2p::past::gc::GCEndpoint::accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver)
{
    npc(endpoint)->accept(receiver);
}

void rice::p2p::past::gc::GCEndpoint::setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    npc(endpoint)->setDeserializer(md);
}

rice::p2p::commonapi::rawserialization::MessageDeserializer* rice::p2p::past::gc::GCEndpoint::getDeserializer()
{
    return npc(endpoint)->getDeserializer();
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCEndpoint::readId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */
{
    if(type == GCId::TYPE)
        return new GCId(buf, endpoint);

    return npc(endpoint)->readId(buf, type);
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::gc::GCEndpoint::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return npc(endpoint)->readNodeHandle(buf);
}

rice::p2p::commonapi::IdRange* rice::p2p::past::gc::GCEndpoint::readIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return new GCIdRange(buf, endpoint);
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::gc::GCEndpoint::coalesce(::rice::p2p::commonapi::NodeHandle* handle)
{
    return npc(endpoint)->coalesce(handle);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::past::gc::GCEndpoint::readNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */
{
    return npc(endpoint)->readNodeHandleSet(buf, type);
}

java::lang::String* rice::p2p::past::gc::GCEndpoint::toString()
{
    return ::java::lang::StringBuilder().append(u"GCE["_j)->append(static_cast< ::java::lang::Object* >(endpoint))
        ->append(u"]"_j)->toString();
}

void rice::p2p::past::gc::GCEndpoint::register_()
{
    npc(endpoint)->register_();
}

int32_t rice::p2p::past::gc::GCEndpoint::proximity(::rice::p2p::commonapi::NodeHandle* nh)
{
    return npc(endpoint)->proximity(nh);
}

bool rice::p2p::past::gc::GCEndpoint::isAlive(::rice::p2p::commonapi::NodeHandle* nh)
{
    return npc(endpoint)->isAlive(nh);
}

void rice::p2p::past::gc::GCEndpoint::setConsistentRouting(bool val)
{
    npc(endpoint)->setConsistentRouting(val);
}

bool rice::p2p::past::gc::GCEndpoint::routingConsistentFor(::rice::p2p::commonapi::Id* id)
{
    return npc(endpoint)->routingConsistentFor(id);
}

void rice::p2p::past::gc::GCEndpoint::setSendOptions(::java::util::Map* options)
{
    npc(endpoint)->setSendOptions(options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCEndpoint::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCEndpoint", 27);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCEndpoint::getClass0()
{
    return class_();
}

