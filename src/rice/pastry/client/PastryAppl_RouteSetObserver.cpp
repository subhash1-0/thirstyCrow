// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java
#include <rice/pastry/client/PastryAppl_RouteSetObserver.hpp>

#include <rice/pastry/client/PastryAppl.hpp>

rice::pastry::client::PastryAppl_RouteSetObserver::PastryAppl_RouteSetObserver(PastryAppl *PastryAppl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryAppl_this(PastryAppl_this)
{
    clinit();
}

rice::pastry::client::PastryAppl_RouteSetObserver::PastryAppl_RouteSetObserver(PastryAppl *PastryAppl_this)
    : PastryAppl_RouteSetObserver(PastryAppl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::client::PastryAppl_RouteSetObserver::nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added)
{
    PastryAppl_this->routeSetChange(handle, added);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::client::PastryAppl_RouteSetObserver::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.client.PastryAppl.RouteSetObserver", 46);
    return c;
}

java::lang::Class* rice::pastry::client::PastryAppl_RouteSetObserver::getClass0()
{
    return class_();
}

