// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28.hpp>

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
#include <java/util/Iterator.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationException.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_2.hpp>
#include <rice/p2p/aggregation/AggregationImpl_refreshInternal_28_receiveResult_28_3.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <Array.hpp>
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

rice::p2p::aggregation::AggregationImpl_refreshInternal_28::AggregationImpl_refreshInternal_28(AggregationImpl *AggregationImpl_this, ::rice::p2p::commonapi::IdArray* ids, ::java::lang::ObjectArray* result, ::rice::Continuation* command, ::int64_tArray* expirations)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , ids(ids)
    , result(result)
    , command(command)
    , expirations(expirations)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28::init()
{
    objectsMissing = int32_t(0);
    objectsFetched = int32_t(0);
    currentIndex = -int32_t(1);
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28::receiveResult(::java::lang::Object* o)
{
    auto lastResult = o;
    while (true) {
        if(currentIndex >= 0) {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"receiveResult("_j)->append(static_cast< ::java::lang::Object* >(lastResult))
                    ->append(u") for index "_j)
                    ->append(currentIndex)
                    ->append(u", length="_j)
                    ->append(npc(ids)->length)->toString());

            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Internal refresh of "_j)->append(npc((*ids)[currentIndex])->toStringFull())
                    ->append(u" returned "_j)
                    ->append(static_cast< ::java::lang::Object* >(lastResult))->toString());

            result->set(currentIndex, lastResult);
        }
        currentIndex++;
        if(currentIndex >= npc(ids)->length) {
            if(objectsMissing > 0)
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"refresh: "_j)->append(objectsMissing)
                        ->append(u"/"_j)
                        ->append(npc(ids)->length)
                        ->append(u" objects not in aggregate list, fetched "_j)
                        ->append(objectsFetched)
                        ->append(u" (max "_j)
                        ->append(AggregationImpl_this->maxReaggregationPerRefresh)
                        ->append(u")"_j)->toString());


            auto nOK = int32_t(0);
            for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                                if(dynamic_cast< ::java::lang::Boolean* >((*result)[i]) != nullptr)
                    nOK++;


            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"refreshInternal: Processed "_j)->append(npc(ids)->length)
                    ->append(u" keys, completed "_j)
                    ->append(nOK)->toString());

            for (auto i = int32_t(0); i < npc(ids)->length; i++) 
                                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u" - "_j)->append(npc((*ids)[i])->toStringFull())
                        ->append(u": "_j)
                        ->append(static_cast< ::java::lang::Object* >((*result)[i]))->toString());


            npc(command)->receiveResult(result);
            return;
        }
        auto const id = (*ids)[currentIndex];
        auto const expiration = (*expirations)[currentIndex];
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh("_j)->append(npc(id)->toStringFull())
                ->append(u", expiration="_j)
                ->append(expiration)
                ->append(u") started"_j)->toString());

        auto adc = java_cast< AggregateDescriptor* >(npc(AggregationImpl_this->aggregateList)->getADC(id));
        if(adc != nullptr) {
            auto objDescIndex = npc(adc)->lookupNewest(id);
            if(objDescIndex < 0) {
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(AggregationImpl_this->logger)->log(u"NL: Aggregate found, but object not found in aggregate?!? -- aborted"_j);

                npc(command)->receiveException(new AggregationException(u"Inconsistency detected in aggregate list -- try restarting the application"_j));
                return;
            }
            if(npc((*npc(adc)->objects)[objDescIndex])->refreshedLifetime < expiration) {
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Changing expiration date from "_j)->append(npc((*npc(adc)->objects)[objDescIndex])->refreshedLifetime)
                        ->append(u" to "_j)
                        ->append(expiration)->toString());

                npc(AggregationImpl_this->aggregateList)->setObjectRefreshedLifetime(adc, objDescIndex, expiration);
            } else {
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Expiration is "_j)->append(npc((*npc(adc)->objects)[objDescIndex])->refreshedLifetime)
                        ->append(u" already, no update needed"_j)->toString());

            }
            lastResult = new ::java::lang::Boolean(true);
            continue;
        } else {
            auto waitingIds = npc(AggregationImpl_this->waitingList)->scan();
            auto iter = npc(waitingIds)->getIterator();
            while (npc(iter)->hasNext()) {
                auto const vkey = java_cast< ::rice::p2p::glacier::VersionKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
                if(npc(npc(vkey)->getId())->equals(id)) {
                    auto thisObject = java_cast< ObjectDescriptor* >(npc(AggregationImpl_this->waitingList)->getMetadata(vkey));
                    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refreshing in waiting list: "_j)->append(npc(vkey)->toStringFull())->toString());

                    if(thisObject == nullptr) {
                        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Broken object in waiting list: "_j)->append(npc(vkey)->toStringFull())
                                ->append(u", removing..."_j)->toString());

                        ::rice::Continuation* const myParent = this;
                        npc(AggregationImpl_this->waitingList)->unstore(vkey, new AggregationImpl_refreshInternal_28_receiveResult_28_1(this, vkey, myParent));
                        return;
                    }
                    if(npc(thisObject)->refreshedLifetime < expiration) {
                        auto newDescriptor = new ObjectDescriptor(npc(thisObject)->key, npc(thisObject)->version, npc(thisObject)->currentLifetime, expiration, npc(thisObject)->size);
                        ::rice::Continuation* const myParent = this;
                        npc(AggregationImpl_this->waitingList)->setMetadata(vkey, newDescriptor, new AggregationImpl_refreshInternal_28_receiveResult_28_2(this, vkey, myParent));
                        return;
                    } else {
                        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Object found in waiting list and no update needed: "_j)->append(npc(vkey)->toStringFull())->toString());

                        receiveResult(static_cast< ::java::lang::Object* >(new ::java::lang::Boolean(true)));
                        return;
                    }
                }
            }
            objectsMissing++;
            if(AggregationImpl_this->addMissingAfterRefresh) {
                if(objectsFetched < AggregationImpl_this->maxReaggregationPerRefresh) {
                    objectsFetched++;
                    ::rice::Continuation* const myParent = this;
                    npc(AggregationImpl_this->objectStore)->lookup(id, false, new AggregationImpl_refreshInternal_28_receiveResult_28_3(this, id, expiration, myParent));
                    return;
                } else {
                    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Limit of "_j)->append(AggregationImpl_this->maxReaggregationPerRefresh)
                            ->append(u" reaggregations exceeded; postponing id="_j)
                            ->append(npc(id)->toStringFull())->toString());

                    lastResult = new ::java::lang::Boolean(true);
                    continue;
                }
            } else {
                if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Refresh: Refreshed object not found in any aggregate: "_j)->append(npc(id)->toStringFull())->toString());

                lastResult = new ::java::lang::Boolean(true);
                continue;
            }
        }
    }
}

void rice::p2p::aggregation::AggregationImpl_refreshInternal_28::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception while refreshing "_j)->append(npc((*ids)[currentIndex])->toStringFull())
            ->append(u", e="_j)->toString(), e);

    receiveResult(static_cast< ::java::lang::Object* >(e));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_refreshInternal_28::getClass0()
{
    return class_();
}

