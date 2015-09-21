// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/Aggregate.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
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

rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1::AggregationImpl_rebuildRecursive_29_receiveResult_29_1(AggregationImpl_rebuildRecursive_29 *AggregationImpl_rebuildRecursive_29_this, ::java::util::Vector* keysInProgress, ::rice::p2p::commonapi::Id* fromKey, ::java::util::Vector* keysDone, ::rice::p2p::past::PastContentHandle* thisHandle, ::java::util::Vector* keysPostponed, ::rice::Continuation* command, ::rice::Continuation* outerContinuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_rebuildRecursive_29_this(AggregationImpl_rebuildRecursive_29_this)
    , keysInProgress(keysInProgress)
    , fromKey(fromKey)
    , keysDone(keysDone)
    , thisHandle(thisHandle)
    , keysPostponed(keysPostponed)
    , command(command)
    , outerContinuation(outerContinuation)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< Aggregate* >(o) != nullptr) {
        npc(keysInProgress)->remove(static_cast< ::java::lang::Object* >(fromKey));
        npc(keysDone)->add(static_cast< ::java::lang::Object* >(fromKey));
        if(npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Rebuild: Got aggregate "_j)->append(npc(fromKey)->toStringFull())->toString());

        auto aggr = java_cast< Aggregate* >(o);
        auto objects = new ObjectDescriptorArray(npc(aggr)->numComponents());
        auto aggregateExpiration = (dynamic_cast< ::rice::p2p::past::gc::GCPastContentHandle* >(thisHandle) != nullptr) ? npc((java_cast< ::rice::p2p::past::gc::GCPastContentHandle* >(thisHandle)))->getExpiration() : ::rice::p2p::past::gc::GCPast::INFINITY_EXPIRATION;
        for (auto i = int32_t(0); i < npc(aggr)->numComponents(); i++) {
            objects->set(i, new ObjectDescriptor(npc(npc(aggr)->getComponent(i))->getId(), npc(npc(aggr)->getComponent(i))->getVersion(), aggregateExpiration, aggregateExpiration, AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->getSize(npc(aggr)->getComponent(i))));
            auto const objData = npc(aggr)->getComponent(i);
            if(npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Checking whether "_j)->append(static_cast< ::java::lang::Object* >(npc(objData)->getId()))
                    ->append(u"v"_j)
                    ->append(npc(objData)->getVersion())
                    ->append(u" is in object store..."_j)->toString());

            npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->objectStore)->lookupHandles(npc(objData)->getId(), 1, new AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1(this, objData));
        }
        npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->aggregateList)->addAggregateDescriptor(new AggregateDescriptor(fromKey, aggregateExpiration, objects, npc(aggr)->getPointers()));
        auto pointers = npc(aggr)->getPointers();
        auto numAdded = int32_t(0);
        if(pointers != nullptr) {
            for (auto i = int32_t(0); i < npc(pointers)->length; i++) {
                if(dynamic_cast< ::rice::p2p::commonapi::Id* >((*pointers)[i]) != nullptr) {
                    auto thisPointer = (*pointers)[i];
                    if(!npc(keysDone)->contains(static_cast< ::java::lang::Object* >(thisPointer)) && !npc(keysPostponed)->contains(static_cast< ::java::lang::Object* >(thisPointer)) && !npc(keysInProgress)->contains(static_cast< ::java::lang::Object* >(thisPointer))) {
                        if(npc(keysInProgress)->size() >= AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->reconstructionMaxConcurrentLookups)
                            npc(keysPostponed)->add(static_cast< ::java::lang::Object* >(thisPointer));
                        else
                            AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->rebuildRecursive(thisPointer, keysInProgress, keysPostponed, keysDone, command);
                        numAdded++;
                    }
                }
            }
        }
        if(npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Rebuild: Added "_j)->append(numAdded)
                ->append(u" keys, now "_j)
                ->append(npc(keysInProgress)->size())
                ->append(u" in progress, "_j)
                ->append(npc(keysPostponed)->size())
                ->append(u" postponed and "_j)
                ->append(npc(keysDone)->size())
                ->append(u" done"_j)->toString());

        if(!npc(keysInProgress)->isEmpty() || !npc(keysPostponed)->isEmpty()) {
            if(npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Rebuild: "_j)->append(npc(keysInProgress)->size())
                    ->append(u" keys in progress, "_j)
                    ->append(npc(keysPostponed)->size())
                    ->append(u" postponed, "_j)
                    ->append(npc(keysDone)->size())
                    ->append(u" done"_j)->toString());

            while ((npc(keysInProgress)->size() < AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->reconstructionMaxConcurrentLookups) && (npc(keysPostponed)->size() > 0)) {
                auto nextKey = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(keysPostponed)->firstElement()));
                if(npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Rebuild: Resuming lookup for postponed key "_j)->append(npc(nextKey)->toStringFull())->toString());

                npc(keysPostponed)->remove(static_cast< ::java::lang::Object* >(nextKey));
                AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->rebuildRecursive(nextKey, keysInProgress, keysPostponed, keysDone, command);
            }
        } else {
            npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->aggregateList)->writeToDisk();
            AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->rebuildInProgress = false;
            if(npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Rebuild: Completed; "_j)->append(npc(keysDone)->size())
                    ->append(u" aggregates checked"_j)->toString());

            npc(command)->receiveResult(new ::java::lang::Boolean(true));
        }
    } else {
        receiveException(static_cast< ::java::lang::Exception* >(new AggregationException(::java::lang::StringBuilder().append(u"Fetch failed: "_j)->append(static_cast< ::java::lang::Object* >(fromKey))
            ->append(u", returned "_j)
            ->append(static_cast< ::java::lang::Object* >(o))->toString())));
    }
}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1::receiveException(::java::lang::Exception* e)
{
    npc(outerContinuation)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1::getClass0()
{
    return class_();
}

