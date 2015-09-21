// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_refresh_3_receiveResult_3_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdSet.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3.hpp>
#include <rice/p2p/past/gc/GCPastImpl_ReplicaMap.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
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

rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_1::GCPastImpl_refresh_3_receiveResult_3_1(GCPastImpl_refresh_3 *GCPastImpl_refresh_3_this, ::rice::environment::logging::Logger* logger, ::rice::p2p::commonapi::IdArray* array, ::rice::p2p::commonapi::NodeHandleSet* set, GCPastImpl_ReplicaMap* map, GCIdSet* ids)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_refresh_3_this(GCPastImpl_refresh_3_this)
    , logger(logger)
    , array(array)
    , set(set)
    , map(map)
    , ids(ids)
{
    clinit();
    ctor();
}

java::lang::Object* rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_1::execute()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"REFRESH: ON PROCESSING THREAD!"_j);

    for (auto i = int32_t(0); i < npc(array)->length; i++) {
        auto id = java_cast< GCId* >((*array)[i]);
        auto replicas = npc(GCPastImpl_refresh_3_this->GCPastImpl_this->endpoint)->replicaSet(npc(id)->getId(), GCPastImpl_refresh_3_this->GCPastImpl_this->replicationFactor + int32_t(1), npc(set)->getHandle(npc(set)->size() - int32_t(1)), set);
        if((replicas != nullptr) && ((npc(replicas)->size() == npc(set)->size()) || (npc(replicas)->size() == GCPastImpl_refresh_3_this->GCPastImpl_this->replicationFactor + int32_t(1)))) {
            for (auto j = int32_t(0); j < npc(replicas)->size(); j++) 
                                npc(map)->addReplica(npc(replicas)->getHandle(j), id);

            GCPastImpl_refresh_3_this->GCPastImpl_this->refreshed++;
            npc(ids)->removeId(static_cast< ::rice::p2p::commonapi::Id* >(id));
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"REFRESH: DONE WITH PROCESSING THREAD - MOVING TO NORMAL THREAD!"_j);

    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_1::getClass0()
{
    return class_();
}

