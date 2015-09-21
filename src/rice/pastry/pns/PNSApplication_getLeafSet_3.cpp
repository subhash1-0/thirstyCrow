// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getLeafSet_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/exception/TimeoutException.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_getLeafSet_3::PNSApplication_getLeafSet_3(PNSApplication *PNSApplication_this, ::rice::p2p::util::AttachableCancellable* cancellable, ::rice::Continuation* c, ::rice::pastry::NodeHandle* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , cancellable(cancellable)
    , c(c)
    , handle(handle)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getLeafSet_3::run()
{
    npc(cancellable)->cancel();
    npc(c)->receiveException(new ::rice::p2p::commonapi::exception::TimeoutException(::java::lang::StringBuilder().append(u"Ping to "_j)->append(static_cast< ::java::lang::Object* >(handle))
        ->append(u" timed out."_j)->toString()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getLeafSet_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getLeafSet_3::getClass0()
{
    return class_();
}

