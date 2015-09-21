// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeApp.java
#include <rice/pastry/socket/nat/probe/ProbeApp_requestProbe_2.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/nat/probe/ProbeApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::probe::ProbeApp_requestProbe_2::ProbeApp_requestProbe_2(ProbeApp *ProbeApp_this, ::rice::Continuation* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProbeApp_this(ProbeApp_this)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::probe::ProbeApp_requestProbe_2::sent(::rice::pastry::transport::PMessageReceipt* msg)
{
    npc(deliverResultToMe)->receiveResult(::java::lang::Boolean::valueOf(true));
}

void rice::pastry::socket::nat::probe::ProbeApp_requestProbe_2::sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason)
{
    npc(deliverResultToMe)->receiveResult(::java::lang::Boolean::valueOf(false));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::probe::ProbeApp_requestProbe_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::probe::ProbeApp_requestProbe_2::getClass0()
{
    return class_();
}

