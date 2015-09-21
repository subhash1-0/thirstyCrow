// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNode.java
#include <rice/p2p/multiring/MultiringNode.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Hashtable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/DeliveryNotification.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/multiring/MultiringApplication.hpp>
#include <rice/p2p/multiring/MultiringEndpoint.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>
#include <rice/p2p/multiring/MultiringNode_route_2.hpp>
#include <rice/p2p/multiring/MultiringNode_MultiringNode_1.hpp>
#include <rice/p2p/multiring/MultiringNodeCollection.hpp>
#include <rice/p2p/multiring/MultiringNodeHandle.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <rice/p2p/multiring/messaging/RingMessage.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <Array.hpp>

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

rice::p2p::multiring::MultiringNode::MultiringNode(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringNode::MultiringNode(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node) 
    : MultiringNode(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,node);
}

rice::p2p::multiring::MultiringNode::MultiringNode(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node, MultiringNode* existing) 
    : MultiringNode(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,node,existing);
}

void rice::p2p::multiring::MultiringNode::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->node = node;
    this->environment = npc(node)->getEnvironment();
    this->logger = npc(npc(environment)->getLogManager())->getLogger(MultiringNode::class_(), nullptr);
    this->ringId = ringId;
    this->endpoints = new ::java::util::Hashtable();
    this->scribe = new ::rice::p2p::scribe::ScribeImpl(this, u"Multiring"_j);
    npc(scribe)->setContentDeserializer(new MultiringNode_MultiringNode_1(this));
    this->collection = new MultiringNodeCollection(this, npc(npc(environment)->getParameters())->getInt(u"p2p_multiring_base"_j));
    this->factory = java_cast< MultiringIdFactory* >(getIdFactory());
}

void rice::p2p::multiring::MultiringNode::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Node* node, MultiringNode* existing)
{
    ctor(ringId, node);
    this->collection = npc(existing)->getCollection();
    npc(this->collection)->addNode(this);
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringNode::getLocalNodeHandle()
{
    return new MultiringNodeHandle(getRingId(), npc(node)->getLocalNodeHandle());
}

rice::p2p::commonapi::Endpoint* rice::p2p::multiring::MultiringNode::registerApplication(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance)
{
    ::rice::p2p::commonapi::Endpoint* endpoint = new MultiringEndpoint(this, npc(node)->buildEndpoint(new MultiringApplication(getRingId(), application), ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(npc(application)->getClass()))->append(u"-"_j)
        ->append(instance)->toString()), application);
    npc(endpoints)->put(static_cast< ::java::lang::Object* >(npc(endpoint)->getInstance()), static_cast< ::java::lang::Object* >(endpoint));
    npc(endpoint)->register_();
    return endpoint;
}

rice::p2p::commonapi::Endpoint* rice::p2p::multiring::MultiringNode::buildEndpoint(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance)
{
    ::rice::p2p::commonapi::Endpoint* endpoint = new MultiringEndpoint(this, npc(node)->buildEndpoint(new MultiringApplication(getRingId(), application), ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(npc(application)->getClass()))->append(u"-"_j)
        ->append(instance)->toString()), application);
    npc(endpoints)->put(static_cast< ::java::lang::Object* >(npc(endpoint)->getInstance()), static_cast< ::java::lang::Object* >(endpoint));
    return endpoint;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNode::getId()
{
    return RingId::build(ringId, npc(node)->getId());
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNode::getRingId()
{
    return ringId;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNode::getNodeId()
{
    return npc(node)->getId();
}

rice::p2p::commonapi::Node* rice::p2p::multiring::MultiringNode::getNode()
{
    return node;
}

rice::p2p::multiring::MultiringNodeCollection* rice::p2p::multiring::MultiringNode::getCollection()
{
    return collection;
}

rice::p2p::commonapi::IdFactory* rice::p2p::multiring::MultiringNode::getIdFactory()
{
    return new MultiringIdFactory(ringId, npc(node)->getIdFactory());
}

void rice::p2p::multiring::MultiringNode::nodeAdded(::rice::p2p::commonapi::Id* otherRingId)
{
    npc(scribe)->subscribe(new ::rice::p2p::scribe::Topic(RingId::build(ringId, otherRingId)), this);
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringNode::route(RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(npc(id)->getRingId())->equals(ringId)) {
        auto endpoint = java_cast< MultiringEndpoint* >(java_cast< ::rice::p2p::commonapi::Endpoint* >(npc(endpoints)->get(static_cast< ::java::lang::Object* >(application))));
        return npc(endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(id), message, static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr), deliverAckToMe, options);
    } else {
        npc(scribe)->anycast(new ::rice::p2p::scribe::Topic(RingId::build(ringId, getTarget(id))), new ::rice::p2p::multiring::messaging::RingMessage(id, message, application));
        ::rice::p2p::commonapi::MessageReceipt* ret = new MultiringNode_route_2(this, message, id);
        if(deliverAckToMe != nullptr) {
            npc(deliverAckToMe)->sent(ret);
        }
        return ret;
    }
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNode::getTarget(RingId* id)
{
    auto shared = npc(collection)->getLengthOfSharedPrefix(java_cast< RingId* >(getId()), id);
    auto thisLength = npc(collection)->getLength(java_cast< RingId* >(getId()));
    auto targetLength = npc(collection)->getLength(id);
    if(shared == thisLength)
        return makeTarget(id, thisLength + int32_t(1));
    else
        return makeTarget(java_cast< RingId* >(getId()), thisLength - int32_t(1));
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringNode::makeTarget(RingId* id, int32_t length)
{
    auto current = npc(npc(id)->getRingId())->toByteArray_();
    auto bytes = new ::int8_tArray(npc(current)->length);
    for (auto j = int32_t(0); j < npc(collection)->BASE * length; j++) 
                (*bytes)[npc(bytes)->length - int32_t(1) - j] = (*current)[npc(bytes)->length - int32_t(1) - j];

    return npc(factory)->buildNormalId(bytes);
}

bool rice::p2p::multiring::MultiringNode::anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    if(dynamic_cast< ::rice::p2p::multiring::messaging::RingMessage* >(content) != nullptr) {
        auto rm = java_cast< ::rice::p2p::multiring::messaging::RingMessage* >(content);
        npc(collection)->route(npc(rm)->getId(), npc(rm)->getRawMessage(), npc(rm)->getApplication(), nullptr, nullptr);
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received unrecognized message "_j)->append(static_cast< ::java::lang::Object* >(content))->toString());

    }
    return true;
}

void rice::p2p::multiring::MultiringNode::deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Received unexpected delivery on topic "_j)->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u" of "_j)
            ->append(static_cast< ::java::lang::Object* >(content))->toString());

}

void rice::p2p::multiring::MultiringNode::childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::multiring::MultiringNode::childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::multiring::MultiringNode::subscribeFailed(::rice::p2p::scribe::Topic* topic)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(getId()))->append(u": Received error joining ringId topic "_j)
            ->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u" - trying again."_j)->toString());

    nodeAdded(npc((java_cast< RingId* >(npc(topic)->getId())))->getId());
}

java::lang::String* rice::p2p::multiring::MultiringNode::toString()
{
    return ::java::lang::StringBuilder().append(u"{MultiringNode "_j)->append(static_cast< ::java::lang::Object* >(getId()))
        ->append(u"}"_j)->toString();
}

rice::environment::Environment* rice::p2p::multiring::MultiringNode::getEnvironment()
{
    return environment;
}

java::lang::String* rice::p2p::multiring::MultiringNode::printRouteState()
{
    return npc(node)->printRouteState();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringNode::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringNode", 32);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringNode::getClass0()
{
    return class_();
}

