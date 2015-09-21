// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_deliver_11_receiveResult_11_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastException.hpp>
#include <rice/p2p/past/PastImpl_deliver_11.hpp>
#include <rice/p2p/past/PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/InsertMessage.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1::PastImpl_deliver_11_receiveResult_11_1(PastImpl_deliver_11 *PastImpl_deliver_11_this, ::rice::p2p::past::messaging::InsertMessage* imsg, ::rice::p2p::commonapi::Id* msgid, ::rice::p2p::past::messaging::PastMessage* msg, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_deliver_11_this(PastImpl_deliver_11_this)
    , imsg(imsg)
    , msgid(msgid)
    , msg(msg)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1::receiveResult(::java::lang::Object* o)
{
    try {
        auto content = npc(npc(imsg)->getContent())->checkInsert(msgid, java_cast< PastContent* >(o));
        npc(PastImpl_deliver_11_this->PastImpl_this->storage)->store(msgid, nullptr, content, new PastImpl_deliver_11_receiveResult_11_1_receiveResult_11_1_1(this, msg, msgid, parent));
    } catch (PastException* e) {
        npc(parent)->receiveException(e);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_deliver_11_receiveResult_11_1::getClass0()
{
    return class_();
}

