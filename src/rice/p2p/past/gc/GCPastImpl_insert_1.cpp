// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_insert_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/messaging/GCInsertMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCPastImpl_insert_1::GCPastImpl_insert_1(GCPastImpl *GCPastImpl_this, ::rice::p2p::past::PastContent* obj, int64_t expiration)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , obj(obj)
    , expiration(expiration)
{
    clinit();
    ctor();
}

rice::p2p::past::messaging::PastMessage* rice::p2p::past::gc::GCPastImpl_insert_1::buildMessage()
{
    return new ::rice::p2p::past::gc::messaging::GCInsertMessage(GCPastImpl_this->getUID(), obj, expiration, GCPastImpl_this->getLocalNodeHandle(), npc(obj)->getId());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_insert_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_insert_1::getClass0()
{
    return class_();
}

