// Generated from /pastry-2.1/src/rice/p2p/past/PastPolicy.java
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/PastPolicy_DefaultPastPolicy_fetch_1.hpp>

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

rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1::PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1(PastPolicy_DefaultPastPolicy_fetch_1 *PastPolicy_DefaultPastPolicy_fetch_1_this, Past* past, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastPolicy_DefaultPastPolicy_fetch_1_this(PastPolicy_DefaultPastPolicy_fetch_1_this)
    , past(past)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr)
        npc(past)->fetch(java_cast< PastContentHandle* >(o), parent);
    else
        npc(parent)->receiveResult(nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1::getClass0()
{
    return class_();
}

