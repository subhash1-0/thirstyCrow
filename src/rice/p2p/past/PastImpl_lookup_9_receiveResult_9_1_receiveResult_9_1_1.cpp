// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1(PastImpl_lookup_9_receiveResult_9_1 *PastImpl_lookup_9_receiveResult_9_1_this, ::rice::Continuation* command, ::java::lang::Object* o)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_lookup_9_receiveResult_9_1_this(PastImpl_lookup_9_receiveResult_9_1_this)
    , command(command)
    , o(o)
{
    clinit();
    ctor();
}

void rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1::receiveResult(::java::lang::Object* object)
{
    npc(command)->receiveResult(o);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_1::getClass0()
{
    return class_();
}

