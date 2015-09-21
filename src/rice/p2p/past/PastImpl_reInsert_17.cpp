// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_reInsert_17.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl_reInsert_17_receiveResult_17_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::p2p::past::PastImpl_reInsert_17::PastImpl_reInsert_17(PastImpl *PastImpl_this, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_reInsert_17::receiveResult(::java::lang::Object* o)
{
    PastImpl_this->insert(java_cast< PastContent* >(o), static_cast< ::rice::Continuation* >(new PastImpl_reInsert_17_receiveResult_17_1(this, parent)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_reInsert_17::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_reInsert_17::getClass0()
{
    return class_();
}

