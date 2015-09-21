// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_19.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Exception.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>

rice::p2p::aggregation::AggregationImpl_formAggregates_19::AggregationImpl_formAggregates_19(AggregationImpl *AggregationImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_19::receiveResult(::java::lang::Object* o)
{
    AggregationImpl_this->flushComplete(new ::java::lang::Boolean(true));
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_19::receiveException(::java::lang::Exception* e)
{
    AggregationImpl_this->flushComplete(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_19::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_19::getClass0()
{
    return class_();
}

