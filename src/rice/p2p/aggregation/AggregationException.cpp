// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationException.java
#include <rice/p2p/aggregation/AggregationException.hpp>

rice::p2p::aggregation::AggregationException::AggregationException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::AggregationException::AggregationException(::java::lang::String* msg) 
    : AggregationException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::p2p::aggregation::AggregationException::ctor(::java::lang::String* msg)
{
    super::ctor(msg);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.AggregationException", 41);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationException::getClass0()
{
    return class_();
}

