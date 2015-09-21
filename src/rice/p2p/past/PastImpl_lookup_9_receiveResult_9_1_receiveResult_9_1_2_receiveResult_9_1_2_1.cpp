// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl_lookup_9.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2.hpp>
#include <rice/p2p/past/PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1_receiveResult_9_1_2_1_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>

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

rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1(PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2 *PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_this, bool cache, ::rice::Continuation* command, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_this(PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_this)
    , cache(cache)
    , command(command)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1::receiveResult(::java::lang::Object* o)
{
    if(cache) {
        PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_this->PastImpl_lookup_9_receiveResult_9_1_this->PastImpl_lookup_9_this->PastImpl_this->cache(java_cast< PastContent* >(o), new PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1_receiveResult_9_1_2_1_1(this, command, o));
    } else {
        npc(command)->receiveResult(o);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_lookup_9_receiveResult_9_1_receiveResult_9_1_2_receiveResult_9_1_2_1::getClass0()
{
    return class_();
}

