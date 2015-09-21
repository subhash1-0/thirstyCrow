// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java
#include <rice/pastry/standard/StandardRouter_StandardRouter_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/standard/StandardRouter.hpp>

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

rice::pastry::standard::StandardRouter_StandardRouter_1::StandardRouter_StandardRouter_1(StandardRouter *StandardRouter_this, ::rice::pastry::PastryNode* thePastryNode)
    : super(*static_cast< ::default_init_tag* >(0))
    , StandardRouter_this(StandardRouter_this)
    , thePastryNode(thePastryNode)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::pastry::standard::StandardRouter_StandardRouter_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    ::rice::pastry::routing::RouteMessage* rm;
    rm = ::rice::pastry::routing::RouteMessage::build(buf, static_cast< int8_t >(priority), thePastryNode, java_cast< ::rice::pastry::NodeHandle* >(sender), static_cast< int8_t >(npc(npc(npc(thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    return rm;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouter_StandardRouter_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardRouter_StandardRouter_1::getClass0()
{
    return class_();
}

