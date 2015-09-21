// Generated from /pastry-2.1/src/rice/p2p/past/PastPolicy.java
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy_fetch_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1.hpp>
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1::PastPolicy_DefaultPastPolicy_fetch_1(PastPolicy_DefaultPastPolicy *PastPolicy_DefaultPastPolicy_this, Past* past, ::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastPolicy_DefaultPastPolicy_this(PastPolicy_DefaultPastPolicy_this)
    , past(past)
    , id(id)
    , hint(hint)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr)
        npc(parent)->receiveResult(o);
    else
        npc(past)->lookupHandle(id, hint, new PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1(this, past, parent));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1::getClass0()
{
    return class_();
}

