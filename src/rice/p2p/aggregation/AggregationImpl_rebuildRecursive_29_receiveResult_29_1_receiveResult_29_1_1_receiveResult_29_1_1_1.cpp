// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1 *AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_this, ::rice::p2p::past::gc::GCPastContent* objData)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_this(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_this)
    , objData(objData)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_this->AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_this->AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Reinsert "_j)->append(static_cast< ::java::lang::Object* >(npc(objData)->getId()))
            ->append(u"v"_j)
            ->append(npc(objData)->getVersion())
            ->append(u" ok, result="_j)
            ->append(static_cast< ::java::lang::Object* >(o))->toString());

}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_this->AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_this->AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Reinsert "_j)->append(static_cast< ::java::lang::Object* >(npc(objData)->getId()))
            ->append(u"v"_j)
            ->append(npc(objData)->getVersion())
            ->append(u" failed, exception="_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1::getClass0()
{
    return class_();
}

