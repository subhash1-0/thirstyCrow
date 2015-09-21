// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouteSetProtocol.java
#include <rice/pastry/standard/StandardRouteSetProtocol_SRSPDeserializer.hpp>

#include <rice/p2p/commonapi/Message.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/routing/BroadcastRouteRow.hpp>
#include <rice/pastry/routing/RequestRouteRow.hpp>

rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer::StandardRouteSetProtocol_SRSPDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer::StandardRouteSetProtocol_SRSPDeserializer(::rice::pastry::PastryNode* pn) 
    : StandardRouteSetProtocol_SRSPDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

rice::pastry::messaging::Message* rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ::rice::pastry::routing::RequestRouteRow::TYPE:
        return new ::rice::pastry::routing::RequestRouteRow(sender, buf);
    case ::rice::pastry::routing::BroadcastRouteRow::TYPE:
        return new ::rice::pastry::routing::BroadcastRouteRow(buf, static_cast< ::rice::pastry::NodeHandleFactory* >(pn), pn);
    }

    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardRouteSetProtocol.SRSPDeserializer", 62);
    return c;
}

rice::p2p::commonapi::Message* rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender)
{
    return super::deserialize(buf, type, priority, sender);
}

java::lang::Class* rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer::getClass0()
{
    return class_();
}

