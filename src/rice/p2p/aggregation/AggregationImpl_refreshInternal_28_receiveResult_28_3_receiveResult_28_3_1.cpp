// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastImpl.hpp>

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

rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1(AggregationImpl_refreshInternal_28_receiveResult_28_3 *AggregationImpl_refreshInternal_28_receiveResult_28_3_this, ::rice::p2p::past::PastContent* obj, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* myParent)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_refreshInternal_28_receiveResult_28_3_this(AggregationImpl_refreshInternal_28_receiveResult_28_3_this)
    , obj(obj)
    , id(id)
    , myParent(myParent)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1::receiveResult(::java::lang::Object* o)
{
    npc((java_cast< ::rice::p2p::past::PastImpl* >(AggregationImpl_refreshInternal_28_receiveResult_28_3_this->AggregationImpl_refreshInternal_28_this->AggregationImpl_this->objectStore)))->cache(obj, new AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1_receiveResult_28_3_1_1(this, id, myParent));
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_refreshInternal_28_receiveResult_28_3_this->AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_refreshInternal_28_receiveResult_28_3_this->AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Refresh: Exception while refreshing aggregate: "_j)->append(npc(id)->toStringFull())
            ->append(u" (e="_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString(), e);

    npc(myParent)->receiveResult(new AggregationException(::java::lang::StringBuilder().append(u"Cannot store reaggregated object in waiting list: "_j)->append(npc(id)->toStringFull())->toString()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_3_receiveResult_28_3_1::getClass0()
{
    return class_();
}

