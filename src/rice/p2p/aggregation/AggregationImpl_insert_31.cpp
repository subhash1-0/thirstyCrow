// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_insert_31.hpp>

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
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>
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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_insert_31::AggregationImpl_insert_31(AggregationImpl *AggregationImpl_this, ::rice::p2p::past::PastContent* obj, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , obj(obj)
    , command(command)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_insert_31::init()
{
    otherSucceeded = false;
    otherFailed = false;
}

void rice::p2p::aggregation::AggregationImpl_insert_31::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"INSERT "_j)->append(static_cast< ::java::lang::Object* >(npc(obj)->getId()))
            ->append(u" receiveResult("_j)
            ->append(static_cast< ::java::lang::Object* >(o))
            ->append(u"), otherSucc="_j)
            ->append(otherSucceeded)
            ->append(u" otherFail="_j)
            ->append(otherFailed)->toString());

    if(otherSucceeded) {
        if(!otherFailed) {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(u"--reporting Success"_j);

            npc(command)->receiveResult(new ::java::lang::BooleanArray({new ::java::lang::Boolean(true)}));
        }
    } else {
        otherSucceeded = true;
    }
}

void rice::p2p::aggregation::AggregationImpl_insert_31::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"INSERT "_j)->append(static_cast< ::java::lang::Object* >(npc(obj)->getId()))
            ->append(u" receiveException("_j)
            ->append(static_cast< ::java::lang::Object* >(e))
            ->append(u"), otherSucc="_j)
            ->append(otherSucceeded)
            ->append(u" otherFail="_j)
            ->append(otherFailed)->toString());

    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(u"--reporting Failure"_j);

    npc(command)->receiveException(e);
    otherFailed = true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_insert_31::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_insert_31::getClass0()
{
    return class_();
}

