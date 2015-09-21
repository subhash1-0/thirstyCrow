// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_remove_15_receiveResult_15_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/PastImpl_remove_15.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_remove_15_receiveResult_15_1::PastImpl_remove_15_receiveResult_15_1(PastImpl_remove_15 *PastImpl_remove_15_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_remove_15_this(PastImpl_remove_15_this)
    , id(id)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_remove_15_receiveResult_15_1::receiveResult(::java::lang::Object* o)
{
    npc(PastImpl_remove_15_this->PastImpl_this->storage)->unstore(id, parent);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_remove_15_receiveResult_15_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_remove_15_receiveResult_15_1::getClass0()
{
    return class_();
}

