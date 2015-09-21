// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getLeafSet_2.hpp>

#include <rice/pastry/pns/PNSApplication.hpp>

rice::pastry::pns::PNSApplication_getLeafSet_2::PNSApplication_getLeafSet_2(PNSApplication *PNSApplication_this, ::rice::pastry::NodeHandle* handle, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , handle(handle)
    , c(c)
{
    clinit();
    ctor();
}

bool rice::pastry::pns::PNSApplication_getLeafSet_2::cancel()
{
    PNSApplication_this->removeFromWaitingForLeafSet(handle, c);
    super::cancel();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getLeafSet_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getLeafSet_2::getClass0()
{
    return class_();
}

