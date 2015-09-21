// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/gc/GCPastImpl_collect_8.hpp>
#include <rice/p2p/past/gc/GCPastImpl_collect_8_receiveResult_8_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1::GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1(GCPastImpl_collect_8_receiveResult_8_1 *GCPastImpl_collect_8_receiveResult_8_1_this, ::rice::p2p::commonapi::Id* gid, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_collect_8_receiveResult_8_1_this(GCPastImpl_collect_8_receiveResult_8_1_this)
    , gid(gid)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1::receiveResult(::java::lang::Object* o)
{
    npc(GCPastImpl_collect_8_receiveResult_8_1_this->GCPastImpl_collect_8_this->GCPastImpl_this->storage)->unstore(gid, parent);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1::getClass0()
{
    return class_();
}

