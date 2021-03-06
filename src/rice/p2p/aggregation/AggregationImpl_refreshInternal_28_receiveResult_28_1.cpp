// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_1::AggregationImpl_refreshInternal_28_receiveResult_28_1(AggregationImpl_refreshInternal_28 *AggregationImpl_refreshInternal_28_this, ::rice::p2p::glacier::VersionKey* vkey, ::rice::Continuation* myParent)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_refreshInternal_28_this(AggregationImpl_refreshInternal_28_this)
    , vkey(vkey)
    , myParent(myParent)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_1::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Broken object "_j)->append(npc(vkey)->toStringFull())
            ->append(u" removed successfully"_j)->toString());

    npc(myParent)->receiveResult(new AggregationException(::java::lang::StringBuilder().append(u"Object in waiting list, but broken: "_j)->append(npc(vkey)->toStringFull())->toString()));
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_refreshInternal_28_this->AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Cannot remove broken object "_j)->append(npc(vkey)->toStringFull())
            ->append(u" from waiting list (exception: "_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString(), e);

    npc(myParent)->receiveResult(new AggregationException(::java::lang::StringBuilder().append(u"Object broken, in waiting list, and cannot remove: "_j)->append(npc(vkey)->toStringFull())
        ->append(u" (e="_j)
        ->append(static_cast< ::java::lang::Object* >(e))
        ->append(u")"_j)->toString()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28_receiveResult_28_1::getClass0()
{
    return class_();
}

