// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_AggregationImpl_2.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/messaging/NonAggregate.hpp>
#include <rice/p2p/aggregation/raw/RawAggregate.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_AggregationImpl_2::AggregationImpl_AggregationImpl_2(AggregationImpl *AggregationImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::past::PastContent* rice::p2p::aggregation::AggregationImpl_AggregationImpl_2::deserializePastContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */
{
    {
        int16_t subType;
        switch (contentType) {
        case ::rice::p2p::aggregation::raw::RawAggregate::TYPE:
            return new ::rice::p2p::aggregation::raw::RawAggregate(buf, endpoint, AggregationImpl_this->contentDeserializer);
        case ::rice::p2p::aggregation::messaging::NonAggregate::TYPE:
            subType = npc(buf)->readShort();
            return npc(AggregationImpl_this->contentDeserializer)->deserializePastContent(buf, endpoint, subType);
        }
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown Type:"_j)->append(contentType)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_AggregationImpl_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_AggregationImpl_2::getClass0()
{
    return class_();
}

