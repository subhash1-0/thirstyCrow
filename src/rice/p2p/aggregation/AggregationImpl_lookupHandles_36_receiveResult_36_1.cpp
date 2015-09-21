// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_lookupHandles_36_receiveResult_36_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl_lookupHandles_36.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_lookupHandles_36_receiveResult_36_1::AggregationImpl_lookupHandles_36_receiveResult_36_1(AggregationImpl_lookupHandles_36 *AggregationImpl_lookupHandles_36_this, ::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_lookupHandles_36_this(AggregationImpl_lookupHandles_36_this)
    , id(id)
    , max(max)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_lookupHandles_36_receiveResult_36_1::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_lookupHandles_36_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_lookupHandles_36_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles: Retrieved from aggregate: "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u", result="_j)
            ->append(static_cast< ::java::lang::Object* >(o))->toString());

    npc(AggregationImpl_lookupHandles_36_this->AggregationImpl_this->objectStore)->lookupHandles(id, max, command);
}

void rice::p2p::aggregation::AggregationImpl_lookupHandles_36_receiveResult_36_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_lookupHandles_36_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_lookupHandles_36_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles: Cannot retrieve from aggregate, exception "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());

    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookupHandles_36_receiveResult_36_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookupHandles_36_receiveResult_36_1::getClass0()
{
    return class_();
}

