// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getLeafSet_4.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_getLeafSet_4::PNSApplication_getLeafSet_4(PNSApplication *PNSApplication_this, ::rice::p2p::util::AttachableCancellable* cancellable, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , cancellable(cancellable)
    , c(c)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getLeafSet_4::sent(::rice::pastry::transport::PMessageReceipt* msg)
{
}

void rice::pastry::pns::PNSApplication_getLeafSet_4::sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason)
{
    npc(cancellable)->cancel();
    npc(c)->receiveException(reason);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getLeafSet_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getLeafSet_4::getClass0()
{
    return class_();
}

