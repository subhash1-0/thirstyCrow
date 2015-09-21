// Generated from /pastry-2.1/src/rice/p2p/aggregation/Moraine.java
#include <rice/p2p/aggregation/Moraine_lookupHandles_6.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/aggregation/Moraine.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>
#include <ObjectArray.hpp>

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

rice::p2p::aggregation::Moraine_lookupHandles_6::Moraine_lookupHandles_6(Moraine *Moraine_this, ::rice::p2p::commonapi::Id* id, int64_t version, int32_t num, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , Moraine_this(Moraine_this)
    , id(id)
    , version(version)
    , num(num)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::Moraine_lookupHandles_6::receiveResult(::java::lang::Object* result)
{
    auto results = java_cast< ::java::lang::ObjectArray* >(result);
    if(npc(results)->length == 1 && (*results)[int32_t(0)] == nullptr) {
        npc(Moraine_this->vOldPast)->lookupHandles(id, version, num, command);
    } else {
        npc(command)->receiveResult(result);
    }
}

void rice::p2p::aggregation::Moraine_lookupHandles_6::receiveException(::java::lang::Exception* result)
{
    if(npc(Moraine_this->logger)->level <= ::rice::environment::logging::Logger::WARNING) {
        npc(Moraine_this->logger)->logException(u"in Moraine.lookupHandles, newPast threw up: "_j, result);
    }
    npc(Moraine_this->vOldPast)->lookupHandles(id, version, num, command);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::Moraine_lookupHandles_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::Moraine_lookupHandles_6::getClass0()
{
    return class_();
}

