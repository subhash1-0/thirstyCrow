// Generated from /pastry-2.1/src/rice/pastry/standard/PeriodicLeafSetProtocol.java
#include <rice/pastry/standard/PeriodicLeafSetProtocol_PLSPMessageDeserializer.hpp>

#include <rice/p2p/commonapi/Message.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/BroadcastLeafSet.hpp>
#include <rice/pastry/leafset/RequestLeafSet.hpp>

rice::pastry::standard::PeriodicLeafSetProtocol_PLSPMessageDeserializer::PeriodicLeafSetProtocol_PLSPMessageDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::PeriodicLeafSetProtocol_PLSPMessageDeserializer::PeriodicLeafSetProtocol_PLSPMessageDeserializer(::rice::pastry::PastryNode* pn) 
    : PeriodicLeafSetProtocol_PLSPMessageDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::standard::PeriodicLeafSetProtocol_PLSPMessageDeserializer::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

rice::pastry::messaging::Message* rice::pastry::standard::PeriodicLeafSetProtocol_PLSPMessageDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ::rice::pastry::leafset::RequestLeafSet::TYPE:
        return new ::rice::pastry::leafset::RequestLeafSet(sender, buf);
    case ::rice::pastry::leafset::BroadcastLeafSet::TYPE:
        return new ::rice::pastry::leafset::BroadcastLeafSet(buf, pn);
    }

    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::PeriodicLeafSetProtocol_PLSPMessageDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.PeriodicLeafSetProtocol.PLSPMessageDeserializer", 68);
    return c;
}

rice::p2p::commonapi::Message* rice::pastry::standard::PeriodicLeafSetProtocol_PLSPMessageDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender)
{
    return super::deserialize(buf, type, priority, sender);
}

java::lang::Class* rice::pastry::standard::PeriodicLeafSetProtocol_PLSPMessageDeserializer::getClass0()
{
    return class_();
}

