// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_retrieveObjectFromAggregate_32.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32::AggregationImpl_retrieveObjectFromAggregate_32(AggregationImpl *AggregationImpl_this, AggregateDescriptor* adc, ::rice::Continuation* command, int32_t objDescIndex)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , adc(adc)
    , command(command)
    , objDescIndex(objDescIndex)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< Aggregate* >(o) != nullptr) {
        auto const aggr = java_cast< Aggregate* >(o);
        npc(AggregationImpl_this->endpoint)->process(new AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_1(this, aggr), new AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2(this, adc, command, objDescIndex, aggr));
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObjectFromAggregate failed; receiveResult("_j)->append(static_cast< ::java::lang::Object* >(o))
                ->append(u")"_j)->toString());

        npc(command)->receiveResult(nullptr);
    }
}

void rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"retrieveObjectFromAggregate failed; receiveException("_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString(), e);

    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32::getClass0()
{
    return class_();
}

