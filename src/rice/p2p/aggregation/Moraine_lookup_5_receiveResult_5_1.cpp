// Generated from /pastry-2.1/src/rice/p2p/aggregation/Moraine.java
#include <rice/p2p/aggregation/Moraine_lookup_5_receiveResult_5_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/aggregation/Moraine_lookup_5.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::Moraine_lookup_5_receiveResult_5_1::Moraine_lookup_5_receiveResult_5_1(Moraine_lookup_5 *Moraine_lookup_5_this, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , Moraine_lookup_5_this(Moraine_lookup_5_this)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::aggregation::Moraine_lookup_5_receiveResult_5_1::receiveResult(::java::lang::Object* result)
{
    npc(command)->receiveResult(result);
}

void rice::p2p::aggregation::Moraine_lookup_5_receiveResult_5_1::receiveException(::java::lang::Exception* result)
{
    npc(command)->receiveException(result);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::Moraine_lookup_5_receiveResult_5_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::Moraine_lookup_5_receiveResult_5_1::getClass0()
{
    return class_();
}

