// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_deliver_11.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/PastImpl_deliver_11_receiveResult_11_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_deliver_11::PastImpl_deliver_11(PastImpl *PastImpl_this, ::rice::p2p::commonapi::Id* msgid, ::rice::p2p::past::messaging::InsertMessage* imsg, ::rice::p2p::past::messaging::PastMessage* msg, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , msgid(msgid)
    , imsg(imsg)
    , msg(msg)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_deliver_11::receiveResult(::java::lang::Object* result)
{
    npc(PastImpl_this->storage)->getObject(msgid, new PastImpl_deliver_11_receiveResult_11_1(this, imsg, msgid, msg, parent));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_deliver_11::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_deliver_11::getClass0()
{
    return class_();
}

