// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregateFactory.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_formAggregates_20_receiveResult_20_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/persistence/StorageManager.hpp>
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
        namespace aggregation
        {
typedef ::SubArray< ::rice::p2p::aggregation::ObjectDescriptor, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > ObjectDescriptorArray;
        } // aggregation

        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContent, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentArray;

            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCPastContent, ::java::lang::ObjectArray, ::rice::p2p::past::PastContentArray > GCPastContentArray;
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

rice::p2p::aggregation::AggregationImpl_formAggregates_20::AggregationImpl_formAggregates_20(AggregationImpl *AggregationImpl_this, ::rice::p2p::past::gc::GCPastContentArray* obj, ObjectDescriptorArray* desc, int32_t iF, int64_t aggrExpirationF, ::rice::Continuation* thisContinuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , obj(obj)
    , desc(desc)
    , iF(iF)
    , aggrExpirationF(aggrExpirationF)
    , thisContinuation(thisContinuation)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_20::init()
{
    currentQuery = int32_t(0);
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_20::receiveResult(::java::lang::Object* o)
{
    if((o != nullptr) && (dynamic_cast< ::rice::p2p::past::gc::GCPastContent* >(o) != nullptr)) {
        obj->set(currentQuery++, java_cast< ::rice::p2p::past::gc::GCPastContent* >(o));
        if(currentQuery < npc(desc)->length) {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Retrieving #"_j)->append(iF)
                    ->append(u"."_j)
                    ->append(currentQuery)
                    ->append(u": "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc((*desc)[currentQuery])->key))->toString());

            npc(AggregationImpl_this->waitingList)->getObject(new ::rice::p2p::glacier::VersionKey(npc((*desc)[currentQuery])->key, npc((*desc)[currentQuery])->version), this);
        } else {
            auto pointers = npc(AggregationImpl_this->aggregateList)->getSomePointers(AggregationImpl_this->nominalReferenceCount, AggregationImpl_this->maxPointersPerAggregate, nullptr);
            AggregationImpl_this->storeAggregate(npc(AggregationImpl_this->aggregateFactory)->buildAggregate(obj, pointers), aggrExpirationF, desc, pointers, new AggregationImpl_formAggregates_20_receiveResult_20_1(this, thisContinuation, desc));
        }
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Aggregation cannot retrieve "_j)->append(static_cast< ::java::lang::Object* >(npc((*desc)[currentQuery])->key))
                ->append(u" (found o="_j)
                ->append(static_cast< ::java::lang::Object* >(o))
                ->append(u")"_j)->toString());

        npc(thisContinuation)->receiveException(new AggregationException(::java::lang::StringBuilder().append(u"Cannot retrieve object from waiting list: "_j)->append(static_cast< ::java::lang::Object* >(npc((*desc)[currentQuery])->key))->toString()));
    }
}

void rice::p2p::aggregation::AggregationImpl_formAggregates_20::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Exception while building aggregate: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());

    npc(thisContinuation)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_20::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_formAggregates_20::getClass0()
{
    return class_();
}

