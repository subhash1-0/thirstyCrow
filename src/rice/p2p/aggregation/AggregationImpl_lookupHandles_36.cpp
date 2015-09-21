// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_lookupHandles_36.hpp>

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
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_lookupHandles_36_receiveResult_36_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
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

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastContentHandle, ::java::lang::ObjectArray, ::java::io::SerializableArray > PastContentHandleArray;
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

rice::p2p::aggregation::AggregationImpl_lookupHandles_36::AggregationImpl_lookupHandles_36(AggregationImpl *AggregationImpl_this, ::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , id(id)
    , max(max)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_lookupHandles_36::receiveResult(::java::lang::Object* o)
{
    auto result = (dynamic_cast< ::rice::p2p::past::PastContentHandleArray* >(o) != nullptr) ? (java_cast< ::rice::p2p::past::PastContentHandleArray* >(o)) : new ::rice::p2p::past::PastContentHandleArray({});
    auto foundHandle = false;
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                if((*result)[i] != nullptr)
            foundHandle = true;


    if(foundHandle) {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u","_j)
                ->append(max)
                ->append(u") handled by PAST; ret="_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());

        npc(command)->receiveResult(o);
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles("_j)->append(static_cast< ::java::lang::Object* >(id))
                ->append(u","_j)
                ->append(max)
                ->append(u") failed, ret="_j)
                ->append(static_cast< ::java::lang::Object* >(o))->toString());

        auto adc = java_cast< AggregateDescriptor* >(npc(AggregationImpl_this->aggregateList)->getADC(id));
        if(adc != nullptr) {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(u"lookupHandles: Retrieving from aggregate"_j);

            auto objDescIndex = npc(adc)->lookupNewest(id);
            if(objDescIndex < 0) {
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(AggregationImpl_this->logger)->log(u"lookupHandles: Aggregate found, but object not found in aggregate?!? -- aborted"_j);

                npc(command)->receiveException(new AggregationException(u"Inconsistency detected in aggregate list -- try restarting the application"_j));
                return;
            }
            if(npc((*npc(adc)->objects)[objDescIndex])->refreshedLifetime < npc(npc(AggregationImpl_this->environment)->getTimeSource())->currentTimeMillis()) {
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Object "_j)->append(static_cast< ::java::lang::Object* >(id))
                        ->append(u" exists, but has expired -- ignoring"_j)->toString());

                npc(command)->receiveResult(new ::rice::p2p::past::PastContentHandleArray({static_cast< ::rice::p2p::past::PastContentHandle* >(nullptr)}));
                return;
            }
            AggregationImpl_this->retrieveObjectFromAggregate(adc, objDescIndex, new AggregationImpl_lookupHandles_36_receiveResult_36_1(this, id, max, command));
        } else {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"lookupHandles: "_j)->append(static_cast< ::java::lang::Object* >(id))
                    ->append(u" is neither in object store nor in aggregate list"_j)->toString());

            npc(command)->receiveResult(new ::rice::p2p::past::PastContentHandleArray({static_cast< ::rice::p2p::past::PastContentHandle* >(nullptr)}));
        }
    }
}

void rice::p2p::aggregation::AggregationImpl_lookupHandles_36::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Exception in lookupHandles: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());

    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookupHandles_36::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_lookupHandles_36::getClass0()
{
    return class_();
}

