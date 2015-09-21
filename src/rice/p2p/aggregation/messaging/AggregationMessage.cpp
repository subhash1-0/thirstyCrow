// Generated from /pastry-2.1/src/rice/p2p/aggregation/messaging/AggregationMessage.java
#include <rice/p2p/aggregation/messaging/AggregationMessage.hpp>

#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

rice::p2p::aggregation::messaging::AggregationMessage::AggregationMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::messaging::AggregationMessage::AggregationMessage(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : AggregationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,source,dest);
}

void rice::p2p::aggregation::messaging::AggregationMessage::ctor(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor();
    this->id = id;
    this->source = source;
    this->dest = dest;
}

int32_t rice::p2p::aggregation::messaging::AggregationMessage::getPriority()
{
    return MEDIUM_LOW_PRIORITY;
}

int32_t rice::p2p::aggregation::messaging::AggregationMessage::getUID()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::aggregation::messaging::AggregationMessage::getSource()
{
    return source;
}

rice::p2p::commonapi::Id* rice::p2p::aggregation::messaging::AggregationMessage::getDestination()
{
    return dest;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::messaging::AggregationMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.messaging.AggregationMessage", 49);
    return c;
}

java::lang::Class* rice::p2p::aggregation::messaging::AggregationMessage::getClass0()
{
    return class_();
}

