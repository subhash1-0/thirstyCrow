// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getRouteRow_5.hpp>

#include <rice/pastry/pns/PNSApplication.hpp>

rice::pastry::pns::PNSApplication_getRouteRow_5::PNSApplication_getRouteRow_5(PNSApplication *PNSApplication_this, ::rice::pastry::NodeHandle* handle, int16_t row, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , handle(handle)
    , row(row)
    , c(c)
{
    clinit();
    ctor();
}

bool rice::pastry::pns::PNSApplication_getRouteRow_5::cancel()
{
    PNSApplication_this->removeFromWaitingForRouteRow(handle, row, c);
    super::cancel();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getRouteRow_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getRouteRow_5::getClass0()
{
    return class_();
}

