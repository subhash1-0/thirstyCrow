// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20_receiveResult_20_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1::AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1(AggregationImpl_formAggregates_20_receiveResult_20_1 *AggregationImpl_formAggregates_20_receiveResult_20_1_this, ::rice::Continuation* c2s)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_formAggregates_20_receiveResult_20_1_this(AggregationImpl_formAggregates_20_receiveResult_20_1_this)
    , c2s(c2s)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1::receiveResult(::java::lang::Object* o)
{
    npc(c2s)->receiveResult(o);
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_formAggregates_20_receiveResult_20_1_this->AggregationImpl_formAggregates_20_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_formAggregates_20_receiveResult_20_1_this->AggregationImpl_formAggregates_20_this->AggregationImpl_this->logger)->logException(u"Exception while unstoring aggregate component: "_j, e);

    npc(c2s)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_20_receiveResult_20_1_receiveResult_20_1_1::getClass0()
{
    return class_();
}

