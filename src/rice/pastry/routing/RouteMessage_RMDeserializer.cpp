// Generated from /pastry-2.1/src/rice/pastry/routing/RouteMessage.java
#include <rice/pastry/routing/RouteMessage_RMDeserializer.hpp>

#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>

rice::pastry::routing::RouteMessage_RMDeserializer::RouteMessage_RMDeserializer(RouteMessage *RouteMessage_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RouteMessage_this(RouteMessage_this)
{
    clinit();
}

rice::pastry::routing::RouteMessage_RMDeserializer::RouteMessage_RMDeserializer(RouteMessage *RouteMessage_this) 
    : RouteMessage_RMDeserializer(RouteMessage_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::routing::RouteMessage_RMDeserializer::ctor()
{
    super::ctor(nullptr);
}

void rice::pastry::routing::RouteMessage_RMDeserializer::setSubDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md)
{
    sub = md;
}

rice::pastry::messaging::Message* rice::pastry::routing::RouteMessage_RMDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    pn = RouteMessage_this->pn;
    return new ::rice::pastry::commonapi::PastryEndpointMessage(RouteMessage_this->auxAddress, buf, sub, type, priority, sender);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RouteMessage_RMDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.RouteMessage.RMDeserializer", 47);
    return c;
}

rice::p2p::commonapi::Message* rice::pastry::routing::RouteMessage_RMDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender)
{
    return super::deserialize(buf, type, priority, sender);
}

java::lang::Class* rice::pastry::routing::RouteMessage_RMDeserializer::getClass0()
{
    return class_();
}

