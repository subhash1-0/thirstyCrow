// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refresh_26.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refresh_26_refreshInAggregates_26_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
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
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
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

rice::p2p::aggregation::AggregationImpl_refresh_26::AggregationImpl_refresh_26(AggregationImpl *AggregationImpl_this, ::rice::p2p::commonapi::IdArray* ids, ::rice::Continuation* command, ::int64_tArray* expirations)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , ids(ids)
    , command(command)
    , expirations(expirations)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refresh_26::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::java::lang::ObjectArray* >(o) != nullptr) {
        result = java_cast< ::java::lang::ObjectArray* >(o);
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"refresh: ObjectStore result is of incorrect type; expected Object[], got "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

        result = new ::java::lang::ObjectArray(npc(ids)->length);
        for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                        result->set(i, o);

    }
    refreshInAggregates();
}

void rice::p2p::aggregation::AggregationImpl_refresh_26::receiveException(::java::lang::Exception* e)
{
    result = new ::java::lang::ObjectArray(npc(ids)->length);
    for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                result->set(i, e);

    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(u""_j, e);

    refreshInAggregates();
}

void rice::p2p::aggregation::AggregationImpl_refresh_26::refreshInAggregates()
{
    ::rice::Continuation* c = new AggregationImpl_refresh_26_refreshInAggregates_26_1(this, command);
    AggregationImpl_this->refreshInternal(ids, expirations, result, c);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refresh_26::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refresh_26::getClass0()
{
    return class_();
}

