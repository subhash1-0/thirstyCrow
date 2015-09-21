// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_timerExpired_24.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_timerExpired_24::AggregationImpl_timerExpired_24(AggregationImpl *AggregationImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_timerExpired_24::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Scheduled flush: Success (o="_j)->append(static_cast< ::java::lang::Object* >(o))
            ->append(u")"_j)->toString());

}

void rice::p2p::aggregation::AggregationImpl_timerExpired_24::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Scheduled flush: Failure (e="_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_timerExpired_24::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_timerExpired_24::getClass0()
{
    return class_();
}

