// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_12.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregateDescriptor.hpp>
#include <rice/p2p/aggregation/AggregateList.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/aggregation/ObjectDescriptor.hpp>
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

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
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

rice::p2p::aggregation::AggregationImpl_handleDebugCommand_12::AggregationImpl_handleDebugCommand_12(AggregationImpl *AggregationImpl_this, ::java::lang::StringBuffer* result, int64_t now, ::java::lang::StringArray* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , result(result)
    , now(now)
    , ret(ret)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_12::init()
{
    currentLookup = int32_t(0);
    lookupInAggrStore = false;
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_12::receiveResult(::java::lang::Object* o)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Monitor: Retr "_j)->append(currentLookup)
            ->append(u" a="_j)
            ->append(lookupInAggrStore)
            ->append(u" got "_j)
            ->append(static_cast< ::java::lang::Object* >(o))->toString());

    auto currentId = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(AggregationImpl_this->monitorIDs)->elementAt(currentLookup)));
    auto handles = java_cast< ::rice::p2p::past::PastContentHandleArray* >(o);
    ::rice::p2p::past::gc::GCPastContentHandle* handle = nullptr;
    auto skipToNext = true;
    for (auto i = int32_t(0); i < npc(handles)->length; i++) 
                if((*handles)[i] != nullptr)
            handle = java_cast< ::rice::p2p::past::gc::GCPastContentHandle* >((*handles)[i]);


    if(!lookupInAggrStore) {
        npc(result)->append(::java::lang::StringBuilder().append(npc(currentId)->toStringFull())->append(u" - OS "_j)->toString());
        npc(result)->append((handle == nullptr) ? u"--"_j : ::java::lang::StringBuilder().append(u""_j)->append((npc(handle)->getExpiration() - now))->toString());
        auto adc = java_cast< AggregateDescriptor* >(npc(AggregationImpl_this->aggregateList)->getADC(currentId));
        if(adc != nullptr) {
            npc(result)->append(::java::lang::StringBuilder().append(u" AD "_j)->append((npc(adc)->currentLifetime - now))->toString());
            auto objDescIndex = npc(adc)->lookupNewest(currentId);
            if(objDescIndex >= 0) {
                auto odc = (*npc(adc)->objects)[objDescIndex];
                npc(result)->append(::java::lang::StringBuilder().append(u" OD "_j)->append((npc(odc)->currentLifetime - now))->toString());
                lookupInAggrStore = true;
                skipToNext = false;
                npc(AggregationImpl_this->aggregateStore)->lookupHandles(npc(adc)->key, 1, this);
            } else {
                npc(result)->append(u" OD ??\n"_j);
            }
        } else {
            npc(result)->append(u" AD ??\n"_j);
        }
    } else {
        npc(result)->append(::java::lang::StringBuilder().append(u" AS "_j)->append(((handle == nullptr) ? u"--\n"_j : ::java::lang::StringBuilder().append(u""_j)->append((npc(handle)->getExpiration() - now))
            ->append(u"\n"_j)->toString()))->toString());
        lookupInAggrStore = false;
    }
    if(skipToNext) {
        currentLookup++;
        if(currentLookup < npc(AggregationImpl_this->monitorIDs)->size()) {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Monitor: Continuing with element "_j)->append(currentLookup)->toString());

            npc(AggregationImpl_this->objectStore)->lookupHandles(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(AggregationImpl_this->monitorIDs)->elementAt(currentLookup))), 1, this);
        } else {
            if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_this->logger)->log(u"Monitor: Done"_j);

            ret->set(int32_t(0), u"done"_j);
        }
    }
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_12::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(u"Montior: Failed, e="_j, e);

    ret->set(int32_t(0), u"done"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_12::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_12::getClass0()
{
    return class_();
}

