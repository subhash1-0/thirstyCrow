// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1(AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1 *AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* myParent)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_this(AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_this)
    , id(id)
    , myParent(myParent)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_this->AggregationImpl_refreshInternal_28_receiveResult_28_3_this->AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_this->AggregationImpl_refreshInternal_28_receiveResult_28_3_this->AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Missing object "_j)->append(npc(id)->toStringFull())
            ->append(u" added ok"_j)->toString());

    npc(myParent)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_this->AggregationImpl_refreshInternal_28_receiveResult_28_3_this->AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_this->AggregationImpl_refreshInternal_28_receiveResult_28_3_this->AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Refresh: Exception while precaching object: "_j)->append(npc(id)->toStringFull())
            ->append(u" (e="_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString(), e);

    npc(myParent)->receiveResult(new ::java::lang::Boolean(true));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1::getClass0()
{
    return class_();
}

