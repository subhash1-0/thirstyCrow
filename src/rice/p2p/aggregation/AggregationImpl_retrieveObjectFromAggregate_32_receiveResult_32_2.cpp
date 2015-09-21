// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2.hpp>

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
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_retrieveObjectFromAggregate_32.hpp>
#include <rice/p2p/aggregation/AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2_receiveResult_32_2_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
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

rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2::AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2(AggregationImpl_retrieveObjectFromAggregate_32 *AggregationImpl_retrieveObjectFromAggregate_32_this, AggregateDescriptor* adc, ::rice::Continuation* command, int32_t objDescIndex, Aggregate* aggr)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_retrieveObjectFromAggregate_32_this(AggregationImpl_retrieveObjectFromAggregate_32_this)
    , adc(adc)
    , command(command)
    , objDescIndex(objDescIndex)
    , aggr(aggr)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::commonapi::Id* >(o) != nullptr) {
        auto aggrNominalKey = java_cast< ::rice::p2p::commonapi::Id* >(o);
        if(!npc(aggrNominalKey)->equals(npc(adc)->key)) {
            if(npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Cannot validate aggregate "_j)->append(static_cast< ::java::lang::Object* >(npc(adc)->key))
                    ->append(u", hash="_j)
                    ->append(static_cast< ::java::lang::Object* >(aggrNominalKey))->toString());

            npc(command)->receiveException(new AggregationException(u"Cannot validate aggregate -- retry?"_j));
            return;
        }
        if(npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Object "_j)->append(static_cast< ::java::lang::Object* >(npc((*npc(adc)->objects)[objDescIndex])->key))
                ->append(u" (#"_j)
                ->append(objDescIndex)
                ->append(u") successfully retrieved from "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(adc)->key))->toString());

        npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->objectStore)->insert(npc(aggr)->getComponent(objDescIndex), new AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2_receiveResult_32_2_1(this));
        npc(command)->receiveResult(npc(aggr)->getComponent(objDescIndex));
    } else {
        if(npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveObjectFromAggregate cannot determine content hash, received "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

        npc(command)->receiveException(new AggregationException(u"retrieveObjectFromAggregate cannot determine content hash"_j));
    }
}

void rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_retrieveObjectFromAggregate_32_this->AggregationImpl_this->logger)->logException(u"retrieveObjectFromAggregate cannot determine content hash, exception "_j, e);

    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_retrieveObjectFromAggregate_32_receiveResult_32_2::getClass0()
{
    return class_();
}

