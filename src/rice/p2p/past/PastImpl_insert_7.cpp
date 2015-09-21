// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_insert_7.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/InsertMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_insert_7::PastImpl_insert_7(PastImpl *PastImpl_this, PastContent* obj)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , obj(obj)
{
    clinit();
    ctor();
}

rice::p2p::past::messaging::PastMessage* rice::p2p::past::PastImpl_insert_7::buildMessage()
{
    return new ::rice::p2p::past::messaging::InsertMessage(PastImpl_this->getUID(), obj, PastImpl_this->getLocalNodeHandle(), npc(obj)->getId());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_insert_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_insert_7::getClass0()
{
    return class_();
}

