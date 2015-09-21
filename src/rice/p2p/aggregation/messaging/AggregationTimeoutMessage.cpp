// Generated from /pastry-2.1/src/rice/p2p/aggregation/messaging/AggregationTimeoutMessage.java
#include <rice/p2p/aggregation/messaging/AggregationTimeoutMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::messaging::AggregationTimeoutMessage::AggregationTimeoutMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::messaging::AggregationTimeoutMessage::AggregationTimeoutMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local) 
    : AggregationTimeoutMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,local);
}

constexpr int16_t rice::p2p::aggregation::messaging::AggregationTimeoutMessage::TYPE;

void rice::p2p::aggregation::messaging::AggregationTimeoutMessage::ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local)
{
    super::ctor(uid, local, npc(local)->getId());
}

java::lang::String* rice::p2p::aggregation::messaging::AggregationTimeoutMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[AggregationTimeoutMessage "_j)->append(getUID())
        ->append(u"]"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::messaging::AggregationTimeoutMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.messaging.AggregationTimeoutMessage", 56);
    return c;
}

java::lang::Class* rice::p2p::aggregation::messaging::AggregationTimeoutMessage::getClass0()
{
    return class_();
}

