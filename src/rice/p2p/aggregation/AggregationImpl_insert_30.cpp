// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_insert_30.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_insert_30::AggregationImpl_insert_30(AggregationImpl *AggregationImpl_this, ::rice::p2p::past::PastContent* obj)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , obj(obj)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_insert_30::receiveResult(::java::lang::Object* o)
{
}

void rice::p2p::aggregation::AggregationImpl_insert_30::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception while storing aggregate: "_j)->append(static_cast< ::java::lang::Object* >(npc(obj)->getId()))
            ->append(u" (e="_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u")"_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_insert_30::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_insert_30::getClass0()
{
    return class_();
}

