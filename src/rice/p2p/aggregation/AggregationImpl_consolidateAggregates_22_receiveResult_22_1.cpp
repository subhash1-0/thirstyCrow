// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_consolidateAggregates_22_receiveResult_22_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationImpl_consolidateAggregates_22.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io
} // java

namespace rice
{
    namespace p2p
    {
        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContent, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentArray;

            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > GCPastContentArray;
            } // gc
        } // past

        namespace aggregation
        {
typedef ::SubArray< ::rice::p2p::aggregation::Aggregate, ::java::lang::ObjectArray, ::rice::p2p::past::gc::GCPastContentArray > AggregateArray;
typedef ::SubArray< ::rice::p2p::aggregation::AggregateDescriptor, ::java::lang::ObjectArray > AggregateDescriptorArray;
        } // aggregation
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22_receiveResult_22_1::AggregationImpl_consolidateAggregates_22_receiveResult_22_1(AggregationImpl_consolidateAggregates_22 *AggregationImpl_consolidateAggregates_22_this, AggregateDescriptorArray* adc, int32_t objectsTotal, AggregateArray* aggr)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_consolidateAggregates_22_this(AggregationImpl_consolidateAggregates_22_this)
    , adc(adc)
    , objectsTotal(objectsTotal)
    , aggr(aggr)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22_receiveResult_22_1::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->log(u"Consolidated Aggregate stored OK, removing old descriptors..."_j);

    for (auto i = int32_t(0); i < npc(adc)->length; i++) {
        if(npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Removing "_j)->append(npc(npc((*adc)[i])->key)->toStringFull())
                ->append(u" ..."_j)->toString());

        npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->aggregateList)->removeAggregateDescriptor((*adc)[i]);
    }
    npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->aggregateList)->writeToDisk();
    if(npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Consolidation completed, "_j)->append(objectsTotal)
            ->append(u" objects from "_j)
            ->append(npc(aggr)->length)
            ->append(u" aggregates consolidated"_j)->toString());

}

void rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22_receiveResult_22_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_consolidateAggregates_22_this->AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception during consolidation store: e="_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u" -- aborting"_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22_receiveResult_22_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22_receiveResult_22_1::getClass0()
{
    return class_();
}

