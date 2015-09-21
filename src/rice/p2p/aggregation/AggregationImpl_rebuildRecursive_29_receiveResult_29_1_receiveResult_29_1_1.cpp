// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
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

rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1(AggregationImpl_rebuildRecursive_29_receiveResult_29_1 *AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this, ::rice::p2p::past::gc::GCPastContent* objData)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this)
    , objData(objData)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1::receiveResult(::java::lang::Object* o)
{
    auto result = (dynamic_cast< ::rice::p2p::past::PastContentHandleArray* >(o) != nullptr) ? (java_cast< ::rice::p2p::past::PastContentHandleArray* >(o)) : new ::rice::p2p::past::PastContentHandleArray({});
    if(npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handles for "_j)->append(static_cast< ::java::lang::Object* >(npc(objData)->getId()))
            ->append(u"v"_j)
            ->append(npc(objData)->getVersion())
            ->append(u": "_j)
            ->append(static_cast< ::java::lang::Object* >(result))
            ->append(u" ("_j)
            ->append(npc(result)->length)
            ->append(u", PCH="_j)
            ->append((dynamic_cast< ::rice::p2p::past::PastContentHandleArray* >(o) != nullptr))
            ->append(u")"_j)->toString());

    auto gotOne = false;
    for (auto i = int32_t(0); i < npc(result)->length; i++) {
        if((*result)[i] != nullptr) {
            if(npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Have v"_j)->append(npc((java_cast< ::rice::p2p::past::gc::GCPastContentHandle* >((*result)[i])))->getVersion())->toString());

            if(npc((java_cast< ::rice::p2p::past::gc::GCPastContentHandle* >((*result)[i])))->getVersion() >= npc(objData)->getVersion())
                gotOne = true;

        }
    }
    if(gotOne) {
        if(npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(u"Got it"_j);

    } else {
        if(npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->log(u"Ain't got it... reinserting"_j);

        npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->objectStore)->insert(objData, new AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1_receiveResult_29_1_1_1(this, objData));
    }
}

void rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(AggregationImpl_rebuildRecursive_29_receiveResult_29_1_this->AggregationImpl_rebuildRecursive_29_this->AggregationImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Cannot retrieve handles for object "_j)->append(static_cast< ::java::lang::Object* >(npc(objData)->getId()))
            ->append(u"v"_j)
            ->append(npc(objData)->getVersion())
            ->append(u" to be restored; e="_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_rebuildRecursive_29_receiveResult_29_1_receiveResult_29_1_1::getClass0()
{
    return class_();
}

