// Generated from /pastry-2.1/src/rice/p2p/aggregation/Moraine.java
#include <rice/p2p/aggregation/Moraine_refresh_4.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/Moraine.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::Moraine_refresh_4::Moraine_refresh_4(Moraine *Moraine_this, ::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , Moraine_this(Moraine_this)
    , ids(ids)
    , expirations(expirations)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::Moraine_refresh_4::receiveResult(::java::lang::Object* result)
{
    npc(Moraine_this->newPast)->refresh(ids, expirations, command);
}

void rice::p2p::aggregation::Moraine_refresh_4::receiveException(::java::lang::Exception* result)
{
    if(npc(Moraine_this->logger)->level <= ::rice::environment::logging::Logger::WARNING) {
        npc(Moraine_this->logger)->logException(u"in Moraine.refresh, oldPast threw up: "_j, result);
    }
    receiveResult(static_cast< ::java::lang::Object* >(nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::Moraine_refresh_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::Moraine_refresh_4::getClass0()
{
    return class_();
}

