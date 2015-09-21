// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_storeAggregate_16.hpp>

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
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_storeAggregate_16_receiveResult_16_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
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

rice::p2p::aggregation::AggregationImpl_storeAggregate_16::AggregationImpl_storeAggregate_16(AggregationImpl *AggregationImpl_this, Aggregate* aggr, int64_t expiration, ObjectDescriptorArray* desc, ::rice::p2p::commonapi::IdArray* pointers, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , aggr(aggr)
    , expiration(expiration)
    , desc(desc)
    , pointers(pointers)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_storeAggregate_16::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::commonapi::Id* >(o) != nullptr) {
        npc(aggr)->setId(java_cast< ::rice::p2p::commonapi::Id* >(o));
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Storing aggregate, CH="_j)->append(static_cast< ::java::lang::Object* >(npc(aggr)->getId()))
                ->append(u", expiration="_j)
                ->append(expiration)
                ->append(u" (rel "_j)
                ->append((expiration - npc(npc(AggregationImpl_this->environment)->getTimeSource())->currentTimeMillis()))
                ->append(u") with "_j)
                ->append(npc(desc)->length)
                ->append(u" objects:"_j)->toString());

        for (auto j = int32_t(0); j < npc(desc)->length; j++) 
                        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"#"_j)->append(j)
                    ->append(u": "_j)
                    ->append(static_cast< ::java::lang::Object* >((*desc)[j]))->toString());


        ::rice::Continuation* c = new AggregationImpl_storeAggregate_16_receiveResult_16_1(this, aggr, expiration, desc, pointers, command);
        if(dynamic_cast< ::rice::p2p::past::gc::GCPast* >(AggregationImpl_this->aggregateStore) != nullptr)
            npc((java_cast< ::rice::p2p::past::gc::GCPast* >(AggregationImpl_this->aggregateStore)))->insert(aggr, expiration, c);
        else
            npc(AggregationImpl_this->aggregateStore)->insert(aggr, c);
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"storeAggregate() cannot determine content hash, received "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

        npc(command)->receiveException(new AggregationException(u"storeAggregate() cannot determine content hash"_j));
    }
}

void rice::p2p::aggregation::AggregationImpl_storeAggregate_16::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(u"storeAggregate() cannot determine content hash, exception "_j, e);

    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_storeAggregate_16::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_storeAggregate_16::getClass0()
{
    return class_();
}

