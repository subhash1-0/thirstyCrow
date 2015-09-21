// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java
#include <rice/pastry/standard/StandardJoinProtocol_handleInitiateJoin_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/join/JoinRequest.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/standard/StandardJoinProtocol.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::StandardJoinProtocol_handleInitiateJoin_1::StandardJoinProtocol_handleInitiateJoin_1(StandardJoinProtocol *StandardJoinProtocol_this, ::rice::pastry::NodeHandle* nh)
    : super(*static_cast< ::default_init_tag* >(0))
    , StandardJoinProtocol_this(StandardJoinProtocol_this)
    , nh(nh)
{
    clinit();
    ctor();
}

void rice::pastry::standard::StandardJoinProtocol_handleInitiateJoin_1::receiveResult(::rice::pastry::join::JoinRequest* jr)
{
    auto rm = new ::rice::pastry::routing::RouteMessage(npc(StandardJoinProtocol_this->localHandle)->getNodeId(), static_cast< ::rice::pastry::messaging::PRawMessage* >(jr), static_cast< ::rice::pastry::NodeHandle* >(nullptr), static_cast< ::rice::pastry::routing::SendOptions* >(nullptr), static_cast< int8_t >(npc(npc(npc(StandardJoinProtocol_this->thePastryNode)->getEnvironment())->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    npc(npc(rm)->getOptions())->setRerouteIfSuspected(false);
    npc(rm)->setPrevNode(StandardJoinProtocol_this->localHandle);
    npc(StandardJoinProtocol_this->thePastryNode)->send(nh, rm, nullptr, StandardJoinProtocol_this->getOptions(jr, StandardJoinProtocol_this->options));
}

void rice::pastry::standard::StandardJoinProtocol_handleInitiateJoin_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::join::JoinRequest* >(result));
}

void rice::pastry::standard::StandardJoinProtocol_handleInitiateJoin_1::receiveException(::java::lang::Exception* exception)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_handleInitiateJoin_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_handleInitiateJoin_1::getClass0()
{
    return class_();
}

