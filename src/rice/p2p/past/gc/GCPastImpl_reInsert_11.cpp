// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_reInsert_11.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCPastImpl_reInsert_11_receiveResult_11_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>

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

rice::p2p::past::gc::GCPastImpl_reInsert_11::GCPastImpl_reInsert_11(GCPastImpl *GCPastImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , id(id)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_reInsert_11::receiveResult(::java::lang::Object* o)
{
    GCPastImpl_this->insert(java_cast< ::rice::p2p::past::PastContent* >(o), npc((java_cast< GCId* >(id)))->getExpiration(), static_cast< ::rice::Continuation* >(new GCPastImpl_reInsert_11_receiveResult_11_1(this, parent)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_reInsert_11::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_reInsert_11::getClass0()
{
    return class_();
}

