// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getNearest_11.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_getNearest_11::PNSApplication_getNearest_11(PNSApplication *PNSApplication_this, ::rice::Continuation* retToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , retToMe(retToMe)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getNearest_11::run()
{
    npc(retToMe)->receiveResult(nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_11::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_11::getClass0()
{
    return class_();
}

