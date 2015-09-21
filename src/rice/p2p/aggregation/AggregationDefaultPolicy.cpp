// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationDefaultPolicy.java
#include <rice/p2p/aggregation/AggregationDefaultPolicy.hpp>

rice::p2p::aggregation::AggregationDefaultPolicy::AggregationDefaultPolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::AggregationDefaultPolicy::AggregationDefaultPolicy()
    : AggregationDefaultPolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool rice::p2p::aggregation::AggregationDefaultPolicy::shouldBeAggregated(::rice::p2p::past::PastContent* obj, int32_t size)
{
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationDefaultPolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.AggregationDefaultPolicy", 45);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationDefaultPolicy::getClass0()
{
    return class_();
}

