// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringEndpoint.java
#include <rice/p2p/multiring/MultiringEndpoint.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/multiring/MultiringIdRange.hpp>
#include <rice/p2p/multiring/MultiringNode.hpp>
#include <rice/p2p/multiring/MultiringNodeCollection.hpp>
#include <rice/p2p/multiring/MultiringNodeHandle.hpp>
#include <rice/p2p/multiring/MultiringNodeHandleSet.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <rice/p2p/util/MRHAdapter.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializedMessage.hpp>

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

rice::p2p::multiring::MultiringEndpoint::MultiringEndpoint(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringEndpoint::MultiringEndpoint(MultiringNode* node, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::commonapi::Application* application) 
    : MultiringEndpoint(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,endpoint,application);
}

void rice::p2p::multiring::MultiringEndpoint::ctor(MultiringNode* node, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::commonapi::Application* application)
{
    super::ctor();
    this->node = node;
    this->endpoint = endpoint;
    this->application = application;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringEndpoint::getId()
{
    return RingId::build(npc(node)->getRingId(), npc(endpoint)->getId());
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint)
{
    return route(id, message, hint, static_cast< ::rice::p2p::commonapi::DeliveryNotification* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe)
{
    return route(id, message, hint, deliverAckToMe, static_cast< ::java::util::Map* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    if(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message) != nullptr) {
        return route(id, java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message), hint, deliverAckToMe, options);
    } else {
        auto const ret = new ::rice::p2p::util::MRHAdapter();
        return route(id, java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::util::rawserialization::JavaSerializedMessage(message)), hint, deliverAckToMe, options);
    }
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint)
{
    return route(id, message, hint, static_cast< ::rice::p2p::commonapi::DeliveryNotification* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe)
{
    return route(id, message, hint, deliverAckToMe, static_cast< ::java::util::Map* >(nullptr));
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringEndpoint::route(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    auto mId = java_cast< RingId* >(id);
    auto mHint = java_cast< MultiringNodeHandle* >(hint);
    if(mId == nullptr) {
        if(npc(npc(mHint)->getRingId())->equals(npc(node)->getRingId())) {
            return npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), message, npc(mHint)->getHandle(), deliverAckToMe, options);
        } else {
            return route(npc(mHint)->getId(), message, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr), deliverAckToMe, options);
        }
    } else {
        if(npc(npc(mId)->getRingId())->equals(npc(node)->getRingId())) {
            if((mHint != nullptr) && (npc(npc(mHint)->getRingId())->equals(npc(node)->getRingId()))) {
                return npc(endpoint)->route(npc(mId)->getId(), message, npc(mHint)->getHandle(), deliverAckToMe, options);
            } else {
                return npc(endpoint)->route(npc(mId)->getId(), message, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr), deliverAckToMe, options);
            }
        } else {
            return npc(npc(node)->getCollection())->route(mId, message, getInstance(), deliverAckToMe, options);
        }
    }
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::multiring::MultiringEndpoint::localLookup(::rice::p2p::commonapi::Id* id, int32_t num, bool safe)
{
    return new MultiringNodeHandleSet(npc(node)->getRingId(), npc(endpoint)->localLookup(npc((java_cast< RingId* >(id)))->getId(), num, safe));
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::multiring::MultiringEndpoint::neighborSet(int32_t num)
{
    return new MultiringNodeHandleSet(npc(node)->getRingId(), npc(endpoint)->neighborSet(num));
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::multiring::MultiringEndpoint::replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank)
{
    if(npc(npc((java_cast< RingId* >(id)))->getRingId())->equals(npc(node)->getRingId()))
        return new MultiringNodeHandleSet(npc(node)->getRingId(), npc(endpoint)->replicaSet(npc((java_cast< RingId* >(id)))->getId(), maxRank));
    else
        return new MultiringNodeHandleSet(npc((java_cast< RingId* >(id)))->getRingId(), npc(npc(npc(node)->getNode())->getIdFactory())->buildNodeHandleSet());
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::multiring::MultiringEndpoint::replicaSet(::rice::p2p::commonapi::Id* id, int32_t maxRank, ::rice::p2p::commonapi::NodeHandle* root, ::rice::p2p::commonapi::NodeHandleSet* set)
{
    if(npc(npc((java_cast< RingId* >(id)))->getRingId())->equals(npc(node)->getRingId()))
        return new MultiringNodeHandleSet(npc(node)->getRingId(), npc(endpoint)->replicaSet(npc((java_cast< RingId* >(id)))->getId(), maxRank, npc((java_cast< MultiringNodeHandle* >(root)))->getHandle(), npc((java_cast< MultiringNodeHandleSet* >(set)))->getSet()));
    else
        return new MultiringNodeHandleSet(npc((java_cast< RingId* >(id)))->getRingId(), npc(npc(npc(node)->getNode())->getIdFactory())->buildNodeHandleSet());
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringEndpoint::range(::rice::p2p::commonapi::NodeHandle* handle, int32_t rank, ::rice::p2p::commonapi::Id* lkey)
{
    if(lkey != nullptr)
        lkey = npc((java_cast< RingId* >(lkey)))->getId();

    auto result = npc(endpoint)->range(npc((java_cast< MultiringNodeHandle* >(handle)))->getHandle(), rank, lkey);
    if(result != nullptr)
        return new MultiringIdRange(npc(node)->getRingId(), result);
    else
        return nullptr;
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringEndpoint::range(::rice::p2p::commonapi::NodeHandle* handle, int32_t rank, ::rice::p2p::commonapi::Id* lkey, bool cumulative)
{
    if(lkey != nullptr)
        lkey = npc((java_cast< RingId* >(lkey)))->getId();

    auto result = npc(endpoint)->range(npc((java_cast< MultiringNodeHandle* >(handle)))->getHandle(), rank, lkey, cumulative);
    if(result != nullptr)
        return new MultiringIdRange(npc(node)->getRingId(), result);
    else
        return nullptr;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringEndpoint::getLocalNodeHandle()
{
    return new MultiringNodeHandle(npc(node)->getRingId(), npc(endpoint)->getLocalNodeHandle());
}

rice::p2p::commonapi::CancellableTask* rice::p2p::multiring::MultiringEndpoint::scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay)
{
    return npc(endpoint)->scheduleMessage(message, delay);
}

rice::p2p::commonapi::CancellableTask* rice::p2p::multiring::MultiringEndpoint::scheduleMessage(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period)
{
    return npc(endpoint)->scheduleMessage(message, delay, period);
}

rice::p2p::commonapi::CancellableTask* rice::p2p::multiring::MultiringEndpoint::scheduleMessageAtFixedRate(::rice::p2p::commonapi::Message* message, int64_t delay, int64_t period)
{
    return npc(endpoint)->scheduleMessageAtFixedRate(message, delay, period);
}

java::util::List* rice::p2p::multiring::MultiringEndpoint::networkNeighbors(int32_t num)
{
    return npc(endpoint)->networkNeighbors(num);
}

void rice::p2p::multiring::MultiringEndpoint::process(::rice::Executable* task, ::rice::Continuation* command)
{
    npc(endpoint)->process(task, command);
}

void rice::p2p::multiring::MultiringEndpoint::deliver(RingId* id, ::rice::p2p::commonapi::Message* target)
{
    npc(application)->deliver(id, target);
}

java::lang::String* rice::p2p::multiring::MultiringEndpoint::getInstance()
{
    return ::java::lang::StringBuilder().append(u"multiring"_j)->append(npc(endpoint)->getInstance())->toString();
}

rice::environment::Environment* rice::p2p::multiring::MultiringEndpoint::getEnvironment()
{
    return npc(node)->getEnvironment();
}

void rice::p2p::multiring::MultiringEndpoint::connect(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver, int32_t timeout)
{
    auto mHandle = java_cast< MultiringNodeHandle* >(handle);
    npc(endpoint)->connect(npc(mHandle)->getHandle(), receiver, timeout);
}

void rice::p2p::multiring::MultiringEndpoint::accept(::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver)
{
    npc(endpoint)->accept(receiver);
}

void rice::p2p::multiring::MultiringEndpoint::setDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    npc(endpoint)->setDeserializer(md);
}

rice::p2p::commonapi::rawserialization::MessageDeserializer* rice::p2p::multiring::MultiringEndpoint::getDeserializer()
{
    return npc(endpoint)->getDeserializer();
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringEndpoint::readId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */
{
    if(type == RingId::TYPE())
        return new RingId(buf, endpoint);

    return npc(endpoint)->readId(buf, type);
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringEndpoint::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return new MultiringNodeHandle(buf, endpoint);
}

rice::p2p::commonapi::IdRange* rice::p2p::multiring::MultiringEndpoint::readIdRange(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return new MultiringIdRange(buf, endpoint);
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringEndpoint::coalesce(::rice::p2p::commonapi::NodeHandle* handle)
{
    if(dynamic_cast< MultiringNodeHandle* >(handle) != nullptr) {
        auto mnh = java_cast< MultiringNodeHandle* >(handle);
        npc(mnh)->handle = npc(endpoint)->coalesce(npc(mnh)->handle);
        return mnh;
    }
    return npc(endpoint)->coalesce(handle);
}

rice::p2p::commonapi::NodeHandleSet* rice::p2p::multiring::MultiringEndpoint::readNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type) /* throws(IOException) */
{
    switch (type) {
    case MultiringNodeHandleSet::TYPE:
        return new MultiringNodeHandleSet(buf, endpoint);
    }

    return npc(endpoint)->readNodeHandleSet(buf, type);
}

java::lang::String* rice::p2p::multiring::MultiringEndpoint::toString()
{
    return ::java::lang::StringBuilder().append(u"MRE["_j)->append(static_cast< ::java::lang::Object* >(endpoint))
        ->append(u"]"_j)->toString();
}

void rice::p2p::multiring::MultiringEndpoint::register_()
{
    npc(endpoint)->register_();
}

int32_t rice::p2p::multiring::MultiringEndpoint::proximity(::rice::p2p::commonapi::NodeHandle* nh)
{
    return npc(endpoint)->proximity(nh);
}

bool rice::p2p::multiring::MultiringEndpoint::isAlive(::rice::p2p::commonapi::NodeHandle* nh)
{
    return npc(endpoint)->isAlive(nh);
}

void rice::p2p::multiring::MultiringEndpoint::setConsistentRouting(bool val)
{
    npc(endpoint)->setConsistentRouting(val);
}

bool rice::p2p::multiring::MultiringEndpoint::routingConsistentFor(::rice::p2p::commonapi::Id* id)
{
    return npc(endpoint)->routingConsistentFor(id);
}

void rice::p2p::multiring::MultiringEndpoint::setSendOptions(::java::util::Map* options)
{
    npc(endpoint)->setSendOptions(options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringEndpoint::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringEndpoint", 36);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringEndpoint::getClass0()
{
    return class_();
}

