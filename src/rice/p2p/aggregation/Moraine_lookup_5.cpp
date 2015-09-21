// Generated from /pastry-2.1/src/rice/p2p/aggregation/Moraine.java
#include <rice/p2p/aggregation/Moraine_lookup_5.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/aggregation/Moraine_lookup_5_receiveResult_5_1.hpp>
#include <rice/p2p/aggregation/Moraine.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::Moraine_lookup_5::Moraine_lookup_5(Moraine *Moraine_this, ::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , Moraine_this(Moraine_this)
    , id(id)
    , version(version)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::Moraine_lookup_5::receiveResult(::java::lang::Object* result)
{
    if(result == nullptr) {
        npc(Moraine_this->vOldPast)->lookup(id, version, new Moraine_lookup_5_receiveResult_5_1(this, command));
    } else {
        npc(command)->receiveResult(result);
    }
}

void rice::p2p::aggregation::Moraine_lookup_5::receiveException(::java::lang::Exception* result)
{
    npc(command)->receiveException(result);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::Moraine_lookup_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::Moraine_lookup_5::getClass0()
{
    return class_();
}

