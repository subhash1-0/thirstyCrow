// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_storeAggregate_16_receiveResult_16_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
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
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_storeAggregate_16.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
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
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
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
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_storeAggregate_16_receiveResult_16_1::AggregationImpl_storeAggregate_16_receiveResult_16_1(AggregationImpl_storeAggregate_16 *AggregationImpl_storeAggregate_16_this, Aggregate* aggr, int64_t expiration, ObjectDescriptorArray* desc, ::rice::p2p::commonapi::IdArray* pointers, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_storeAggregate_16_this(AggregationImpl_storeAggregate_16_this)
    , aggr(aggr)
    , expiration(expiration)
    , desc(desc)
    , pointers(pointers)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_storeAggregate_16_receiveResult_16_1::receiveResult(::java::lang::Object* o)
{
    auto adc = new AggregateDescriptor(npc(aggr)->getId(), expiration, desc, pointers);
    if(dynamic_cast< ::java::lang::BooleanArray* >(o) != nullptr) {
        npc(AggregationImpl_storeAggregate_16_this->AggregationImpl_this->aggregateList)->addAggregateDescriptor(adc);
        npc(AggregationImpl_storeAggregate_16_this->AggregationImpl_this->aggregateList)->setRoot(npc(aggr)->getId());
        npc(AggregationImpl_storeAggregate_16_this->AggregationImpl_this->aggregateList)->writeToDisk();
        if(npc(AggregationImpl_storeAggregate_16_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_storeAggregate_16_this->AggregationImpl_this->logger)->log(u"Aggregate inserted successfully"_j);

        npc(command)->receiveResult(new ::java::lang::Boolean(true));
    } else {
        if(npc(AggregationImpl_storeAggregate_16_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_storeAggregate_16_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Unexpected result in aggregate insert (commit): "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

        npc(command)->receiveException(new AggregationException(::java::lang::StringBuilder().append(u"Unexpected result (commit): "_j)->append(static_cast< ::java::lang::Object* >(o))->toString()));
    }
}

void rice::p2p::aggregation::AggregationImpl_storeAggregate_16_receiveResult_16_1::receiveException(::java::lang::Exception* e)
{
    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_storeAggregate_16_receiveResult_16_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_storeAggregate_16_receiveResult_16_1::getClass0()
{
    return class_();
}

