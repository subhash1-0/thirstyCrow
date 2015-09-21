// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_storeAggregate_15.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_storeAggregate_15::AggregationImpl_storeAggregate_15(AggregationImpl *AggregationImpl_this, Aggregate* aggr)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , aggr(aggr)
{
    clinit();
    ctor();
}

java::lang::Object* rice::p2p::aggregation::AggregationImpl_storeAggregate_15::execute()
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(u"storeAggregate() starts working on content hash..."_j);

    return npc(AggregationImpl_this->factory)->buildId(npc(aggr)->getContentHash());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_storeAggregate_15::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_storeAggregate_15::getClass0()
{
    return class_();
}

