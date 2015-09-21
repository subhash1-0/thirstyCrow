// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/gc/GCPastContentHandle.hpp>
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

rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29::AggregationImpl_rebuildRecursive_29(AggregationImpl *AggregationImpl_this, ::rice::p2p::commonapi::Id* fromKey, ::java::util::Vector* keysInProgress, ::java::util::Vector* keysDone, ::java::util::Vector* keysPostponed, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , fromKey(fromKey)
    , keysInProgress(keysInProgress)
    , keysDone(keysDone)
    , keysPostponed(keysPostponed)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got handles for "_j)->append(static_cast< ::java::lang::Object* >(fromKey))->toString());

    if(dynamic_cast< ::rice::p2p::past::PastContentHandleArray* >(o) != nullptr) {
        auto pch = java_cast< ::rice::p2p::past::PastContentHandleArray* >(o);
        ::rice::p2p::past::PastContentHandle* bestHandle = nullptr;
        for (auto i = int32_t(0); i < npc(pch)->length; i++) {
            if(((*pch)[i] == nullptr) || ((dynamic_cast< ::rice::p2p::past::gc::GCPastContentHandle* >((*pch)[i]) != nullptr) && (npc((java_cast< ::rice::p2p::past::gc::GCPastContentHandle* >((*pch)[i])))->getVersion() != 0)))
                continue;

            if(bestHandle == nullptr)
                bestHandle = (*pch)[i];

        }
        if(bestHandle != nullptr) {
            auto const thisHandle = bestHandle;
            ::rice::Continuation* const outerContinuation = this;
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fetching "_j)->append(static_cast< ::java::lang::Object* >(thisHandle))->toString());

            npc(AggregationImpl_this->aggregateStore)->fetch(thisHandle, new AggregationImpl_rebuildRecursive_29_receiveResult_29_1(this, keysInProgress, fromKey, keysDone, thisHandle, keysPostponed, command, outerContinuation));
        } else {
            receiveException(static_cast< ::java::lang::Exception* >(new AggregationException(::java::lang::StringBuilder().append(u"LookupHandles did not return any valid handles for "_j)->append(static_cast< ::java::lang::Object* >(fromKey))->toString())));
        }
    } else {
        receiveException(static_cast< ::java::lang::Exception* >(new AggregationException(::java::lang::StringBuilder().append(u"LookupHandles for "_j)->append(static_cast< ::java::lang::Object* >(fromKey))
            ->append(u" failed, returned o="_j)
            ->append(static_cast< ::java::lang::Object* >(o))->toString())));
    }
}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(u"Rebuild: Exception "_j, e);

    npc(keysInProgress)->remove(static_cast< ::java::lang::Object* >(fromKey));
    npc(keysDone)->add(static_cast< ::java::lang::Object* >(fromKey));
    if(npc(keysInProgress)->isEmpty() && npc(keysPostponed)->isEmpty()) {
        AggregationImpl_this->rebuildInProgress = false;
        if(npc(AggregationImpl_this->aggregateList)->isEmpty()) {
            npc(command)->receiveException(new AggregationException(u"Cannot read root aggregate! -- retry later"_j));
        } else {
            npc(AggregationImpl_this->aggregateList)->writeToDisk();
            npc(command)->receiveResult(new ::java::lang::Boolean(true));
        }
    }
    while ((npc(keysInProgress)->size() < AggregationImpl_this->reconstructionMaxConcurrentLookups) && (npc(keysPostponed)->size() > 0)) {
        auto nextKey = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(keysPostponed)->firstElement()));
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Rebuild: Resuming lookup for postponed key "_j)->append(npc(nextKey)->toStringFull())->toString());

        npc(keysPostponed)->remove(static_cast< ::java::lang::Object* >(nextKey));
        AggregationImpl_this->rebuildRecursive(nextKey, keysInProgress, keysPostponed, keysDone, command);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29::getClass0()
{
    return class_();
}

