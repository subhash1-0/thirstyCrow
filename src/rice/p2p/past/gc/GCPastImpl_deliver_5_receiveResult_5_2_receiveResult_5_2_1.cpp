// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_5.hpp>
#include <rice/p2p/past/gc/GCPastImpl_deliver_5_receiveResult_5_2.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1::GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1(GCPastImpl_deliver_5_receiveResult_5_2 *GCPastImpl_deliver_5_receiveResult_5_2_this, GCId* id, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_deliver_5_receiveResult_5_2_this(GCPastImpl_deliver_5_receiveResult_5_2_this)
    , id(id)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1::receiveResult(::java::lang::Object* o)
{
    npc(GCPastImpl_deliver_5_receiveResult_5_2_this->GCPastImpl_deliver_5_this->GCPastImpl_this->trash)->unstore(npc(id)->getId(), parent);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1::getClass0()
{
    return class_();
}

