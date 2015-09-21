// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_deliver_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastException.hpp>
#include <rice/p2p/past/gc/GCPastContent.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
#include <rice/p2p/past/gc/messaging/GCInsertMessage.hpp>
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

rice::p2p::past::gc::GCPastImpl_deliver_4::GCPastImpl_deliver_4(GCPastImpl *GCPastImpl_this, ::rice::p2p::past::gc::messaging::GCInsertMessage* imsg, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , imsg(imsg)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_deliver_4::receiveResult(::java::lang::Object* o)
{
    try {
        auto content = java_cast< GCPastContent* >(npc(npc(imsg)->getContent())->checkInsert(npc(npc(imsg)->getContent())->getId(), java_cast< ::rice::p2p::past::PastContent* >(o)));
        npc(GCPastImpl_this->storage)->store(npc(content)->getId(), npc(content)->getMetadata(npc(imsg)->getExpiration()), content, parent);
    } catch (::rice::p2p::past::PastException* e) {
        npc(parent)->receiveException(e);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_deliver_4::getClass0()
{
    return class_();
}

