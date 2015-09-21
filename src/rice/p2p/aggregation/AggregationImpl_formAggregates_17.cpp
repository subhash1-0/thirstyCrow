// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_17.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_formAggregates_17::AggregationImpl_formAggregates_17(AggregationImpl *AggregationImpl_this, ::rice::Continuation* command, ::rice::Continuation* parent)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , command(command)
    , parent(parent)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_17::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Daisy-chain receiveResult(), restarting "_j)->append(static_cast< ::java::lang::Object* >(command))->toString());

    npc(parent)->receiveResult(o);
    AggregationImpl_this->formAggregates(command);
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_17::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Daisy-chain receiveException(), restarting "_j)->append(static_cast< ::java::lang::Object* >(command))->toString());

    npc(parent)->receiveException(e);
    AggregationImpl_this->formAggregates(command);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_17::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_17::getClass0()
{
    return class_();
}

