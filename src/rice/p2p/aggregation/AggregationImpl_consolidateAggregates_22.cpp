// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_consolidateAggregates_22.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateFactory.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationImpl_consolidateAggregates_22_receiveResult_22_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/rawserialization/RawGCPastContent.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
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
typedef ::SubArray< ::rice::p2p::aggregation::ObjectDescriptor, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > ObjectDescriptorArray;
        } // aggregation

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi

        namespace past
        {
            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::past::rawserialization::RawPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > RawPastContentArray;
            } // rawserialization

            namespace gc
            {
                namespace rawserialization
                {
typedef ::SubArray< ::rice::p2p::past::gc::rawserialization::RawGCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::gc::GCPastContentArray, ::rice::p2p::past::rawserialization::RawPastContentArray > RawGCPastContentArray;
                } // rawserialization
            } // gc
        } // past
    } // p2p
} // rice

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

rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22::AggregationImpl_consolidateAggregates_22(AggregationImpl *AggregationImpl_this, AggregateArray* aggr, ::java::util::Vector* componentList, int32_t objectsTotal, AggregateDescriptorArray* adc, int64_t now)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , aggr(aggr)
    , componentList(componentList)
    , objectsTotal(objectsTotal)
    , adc(adc)
    , now(now)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22::init()
{
    currentLookup = int32_t(0);
}

void rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< Aggregate* >(o) != nullptr) {
        aggr->set(currentLookup, java_cast< Aggregate* >(o));
        currentLookup++;
        if(currentLookup >= npc(componentList)->size()) {
            auto components = new ::rice::p2p::past::gc::rawserialization::RawGCPastContentArray(objectsTotal);
            auto desc = new ObjectDescriptorArray(objectsTotal);
            auto componentIndex = int32_t(0);
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(AggregationImpl_this->logger)->log(u"Consolidation: All aggregates fetched OK, forming new aggregate..."_j);

            for (auto i = int32_t(0); i < npc(adc)->length; i++) {
                for (auto j = int32_t(0); j < npc(npc((*adc)[i])->objects)->length; j++) {
                    if(npc((*npc((*adc)[i])->objects)[j])->isAliveAt(now)) {
                        auto temp = npc((*aggr)[i])->getComponent(j);
                        components->set(componentIndex, java_cast< ::rice::p2p::past::gc::rawserialization::RawGCPastContent* >(temp));
                        desc->set(componentIndex, (*npc((*adc)[i])->objects)[j]);
                        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"  #"_j)->append(componentIndex)
                                ->append(u": "_j)
                                ->append(npc(npc((*npc((*adc)[i])->objects)[j])->key)->toStringFull())->toString());

                        componentIndex++;
                    } else {
                        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Skipped (dead): "_j)->append(npc(npc((*npc((*adc)[i])->objects)[j])->key)->toStringFull())->toString());

                    }
                }
            }
            auto obsoleteAggregates = new ::rice::p2p::commonapi::IdArray(npc(adc)->length);
            for (auto i = int32_t(0); i < npc(adc)->length; i++) 
                                obsoleteAggregates->set(i, npc((*adc)[i])->key);

            auto pointers = npc(AggregationImpl_this->aggregateList)->getSomePointers(AggregationImpl_this->nominalReferenceCount, AggregationImpl_this->maxPointersPerAggregate, obsoleteAggregates);
            auto const aggrExpirationF = AggregationImpl_this->chooseAggregateLifetime(desc, npc(npc(AggregationImpl_this->environment)->getTimeSource())->currentTimeMillis(), 0);
            AggregationImpl_this->storeAggregate(npc(AggregationImpl_this->aggregateFactory)->buildAggregate(components, pointers), aggrExpirationF, desc, pointers, new AggregationImpl_consolidateAggregates_22_receiveResult_22_1(this, adc, objectsTotal, aggr));
        } else {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Consolidation: Fetching aggregate #"_j)->append(currentLookup)
                    ->append(u": "_j)
                    ->append(npc(npc((*adc)[currentLookup])->key)->toStringFull())->toString());

            npc(AggregationImpl_this->aggregateStore)->lookup(npc((*adc)[currentLookup])->key, this);
        }
    }
}

void rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception during consolidation lookup "_j)->append(npc(npc((*adc)[currentLookup])->key)->toStringFull())
            ->append(u": "_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u" -- aborting"_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_consolidateAggregates_22::getClass0()
{
    return class_();
}

