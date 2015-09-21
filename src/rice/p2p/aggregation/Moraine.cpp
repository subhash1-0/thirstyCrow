// Generated from /pastry-2.1/src/rice/p2p/aggregation/Moraine.java
#include <rice/p2p/aggregation/Moraine.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Arrays.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/Moraine_lookup_1.hpp>
#include <rice/p2p/aggregation/Moraine_lookupHandles_2.hpp>
#include <rice/p2p/aggregation/Moraine_fetch_3.hpp>
#include <rice/p2p/aggregation/Moraine_refresh_4.hpp>
#include <rice/p2p/aggregation/Moraine_lookup_5.hpp>
#include <rice/p2p/aggregation/Moraine_lookupHandles_6.hpp>
#include <rice/p2p/aggregation/Moraine_refresh_7.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
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

rice::p2p::aggregation::Moraine::Moraine(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::Moraine::Moraine(::rice::p2p::past::gc::GCPast* newPast, ::rice::p2p::past::gc::GCPast* oldPast) 
    : Moraine(*static_cast< ::default_init_tag* >(0))
{
    ctor(newPast,oldPast);
}

void rice::p2p::aggregation::Moraine::ctor(::rice::p2p::past::gc::GCPast* newPast, ::rice::p2p::past::gc::GCPast* oldPast)
{
    super::ctor();
    this->newPast = newPast;
    this->oldPast = oldPast;
    this->vNewPast = java_cast< ::rice::p2p::glacier::VersioningPast* >(newPast);
    this->vOldPast = java_cast< ::rice::p2p::glacier::VersioningPast* >(oldPast);
    this->logger = npc(npc(npc(newPast)->getEnvironment())->getLogManager())->getLogger(Moraine::class_(), npc(newPast)->getInstance());
}

void rice::p2p::aggregation::Moraine::insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command)
{
    npc(newPast)->insert(obj, command);
}

void rice::p2p::aggregation::Moraine::lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    lookup(id, true, command);
}

void rice::p2p::aggregation::Moraine::lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command)
{
    npc(newPast)->lookup(id, cache, new Moraine_lookup_1(this, id, cache, command));
}

void rice::p2p::aggregation::Moraine::lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command)
{
    npc(newPast)->lookupHandles(id, max, new Moraine_lookupHandles_2(this, id, max, command));
}

void rice::p2p::aggregation::Moraine::lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command)
{
    npc(command)->receiveException(new ::java::lang::UnsupportedOperationException(u"LookupHandle() is not supported on Moraine"_j));
}

void rice::p2p::aggregation::Moraine::fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command)
{
    npc(newPast)->fetch(handle, new Moraine_fetch_3(this, handle, command));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::aggregation::Moraine::getLocalNodeHandle()
{
    return npc(newPast)->getLocalNodeHandle();
}

int32_t rice::p2p::aggregation::Moraine::getReplicationFactor()
{
    return npc(newPast)->getReplicationFactor();
}

rice::environment::Environment* rice::p2p::aggregation::Moraine::getEnvironment()
{
    return npc(newPast)->getEnvironment();
}

java::lang::String* rice::p2p::aggregation::Moraine::getInstance()
{
    return npc(newPast)->getInstance();
}

void rice::p2p::aggregation::Moraine::setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer)
{
    npc(newPast)->setContentDeserializer(deserializer);
    npc(oldPast)->setContentDeserializer(deserializer);
}

void rice::p2p::aggregation::Moraine::setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer)
{
    npc(newPast)->setContentHandleDeserializer(deserializer);
    npc(oldPast)->setContentHandleDeserializer(deserializer);
}

void rice::p2p::aggregation::Moraine::insert(::rice::p2p::past::PastContent* obj, int64_t expiration, ::rice::Continuation* command)
{
    npc(newPast)->insert(obj, expiration, command);
}

void rice::p2p::aggregation::Moraine::refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    npc(oldPast)->refresh(ids, expirations, static_cast< ::rice::Continuation* >(new Moraine_refresh_4(this, ids, expirations, command)));
}

void rice::p2p::aggregation::Moraine::refresh(::rice::p2p::commonapi::IdArray* ids, int64_t expiration, ::rice::Continuation* command)
{
    auto expirations = new ::int64_tArray(npc(ids)->length);
    ::java::util::Arrays::fill(expirations, expiration);
    refresh(ids, expirations, command);
}

void rice::p2p::aggregation::Moraine::lookup(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command)
{
    npc(vNewPast)->lookup(id, version, new Moraine_lookup_5(this, id, version, command));
}

void rice::p2p::aggregation::Moraine::lookupHandles(::rice::p2p::commonapi::Id* id, int64_t version, int32_t num, ::rice::Continuation* command)
{
    npc(vNewPast)->lookupHandles(id, version, num, new Moraine_lookupHandles_6(this, id, version, num, command));
}

void rice::p2p::aggregation::Moraine::refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::int64_tArray* expirations, ::rice::Continuation* command)
{
    npc(vOldPast)->refresh(ids, versions, expirations, new Moraine_refresh_7(this, ids, versions, expirations, command));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::Moraine::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.Moraine", 28);
    return c;
}

java::lang::Class* rice::p2p::aggregation::Moraine::getClass0()
{
    return class_();
}

