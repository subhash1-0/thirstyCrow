// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringRouteMessage.java
#include <rice/p2p/multiring/MultiringRouteMessage.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/RouteMessage.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/multiring/MultiringNodeHandle.hpp>
#include <rice/p2p/multiring/RingId.hpp>

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

rice::p2p::multiring::MultiringRouteMessage::MultiringRouteMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringRouteMessage::MultiringRouteMessage(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::RouteMessage* message) 
    : MultiringRouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,message);
}

void rice::p2p::multiring::MultiringRouteMessage::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::RouteMessage* message)
{
    super::ctor();
    this->ringId = ringId;
    this->message = message;
    if((dynamic_cast< RingId* >(ringId) != nullptr) || (dynamic_cast< MultiringRouteMessage* >(message) != nullptr))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Illegal creation of MRRouteMessage: "_j)->append(static_cast< ::java::lang::Object* >(npc(ringId)->getClass()))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(message)->getClass()))->toString());

}

rice::p2p::commonapi::RouteMessage* rice::p2p::multiring::MultiringRouteMessage::getRouteMessage()
{
    return message;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::MultiringRouteMessage::getDestinationId()
{
    return RingId::build(ringId, npc(message)->getDestinationId());
}

rice::p2p::commonapi::NodeHandle* rice::p2p::multiring::MultiringRouteMessage::getNextHopHandle()
{
    return new MultiringNodeHandle(ringId, npc(message)->getNextHopHandle());
}

rice::p2p::commonapi::Message* rice::p2p::multiring::MultiringRouteMessage::getMessage()
{
    return npc(message)->getMessage();
}

rice::p2p::commonapi::Message* rice::p2p::multiring::MultiringRouteMessage::getMessage(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */
{
    return npc(message)->getMessage(md);
}

void rice::p2p::multiring::MultiringRouteMessage::setDestinationId(::rice::p2p::commonapi::Id* id)
{
    npc(message)->setDestinationId(npc((java_cast< RingId* >(id)))->getId());
}

void rice::p2p::multiring::MultiringRouteMessage::setNextHopHandle(::rice::p2p::commonapi::NodeHandle* nextHop)
{
    npc(message)->setNextHopHandle(npc((java_cast< MultiringNodeHandle* >(nextHop)))->getHandle());
}

void rice::p2p::multiring::MultiringRouteMessage::setMessage(::rice::p2p::commonapi::Message* message)
{
    if(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message) != nullptr) {
        setMessage(java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(message));
    } else {
        npc(this->message)->setMessage(message);
    }
}

void rice::p2p::multiring::MultiringRouteMessage::setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message)
{
    npc(this->message)->setMessage(message);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringRouteMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringRouteMessage", 40);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringRouteMessage::getClass0()
{
    return class_();
}

