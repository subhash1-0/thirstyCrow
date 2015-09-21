// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastImpl_deliver_11.hpp>
#include <rice/p2p/past/PastImpl_deliver_11_receiveResult_11_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/persistence/LockManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1::PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1(PastImpl_deliver_11_receiveResult_11_1 *PastImpl_deliver_11_receiveResult_11_1_this, ::rice::p2p::past::messaging::PastMessage* msg, ::rice::p2p::commonapi::Id* msgid, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_deliver_11_receiveResult_11_1_this(PastImpl_deliver_11_receiveResult_11_1_this)
    , msg(msg)
    , msgid(msgid)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1::receiveResult(::java::lang::Object* result)
{
    npc(PastImpl_deliver_11_receiveResult_11_1_this->PastImpl_deliver_11_this->PastImpl_this->getResponseContinuation(msg))->receiveResult(result);
    npc(PastImpl_deliver_11_receiveResult_11_1_this->PastImpl_deliver_11_this->PastImpl_this->lockManager)->unlock(msgid);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1::getClass0()
{
    return class_();
}

