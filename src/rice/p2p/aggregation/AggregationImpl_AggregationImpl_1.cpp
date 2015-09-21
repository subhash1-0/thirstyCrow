// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_AggregationImpl_1.hpp>

#include <rice/p2p/aggregation/AggregationImpl.hpp>

rice::p2p::aggregation::AggregationImpl_AggregationImpl_1::AggregationImpl_AggregationImpl_1(AggregationImpl *AggregationImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::p2p::aggregation::AggregationImpl_AggregationImpl_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    }

    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_AggregationImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_AggregationImpl_1::getClass0()
{
    return class_();
}

