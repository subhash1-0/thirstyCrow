// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java
#include <rice/pastry/client/PastryAppl_LeafSetObserver.hpp>

#include <rice/pastry/client/PastryAppl.hpp>

rice::pastry::client::PastryAppl_LeafSetObserver::PastryAppl_LeafSetObserver(PastryAppl *PastryAppl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryAppl_this(PastryAppl_this)
{
    clinit();
}

rice::pastry::client::PastryAppl_LeafSetObserver::PastryAppl_LeafSetObserver(PastryAppl *PastryAppl_this)
    : PastryAppl_LeafSetObserver(PastryAppl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::client::PastryAppl_LeafSetObserver::nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added)
{
    PastryAppl_this->leafSetChange(handle, added);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::client::PastryAppl_LeafSetObserver::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.client.PastryAppl.LeafSetObserver", 45);
    return c;
}

java::lang::Class* rice::pastry::client::PastryAppl_LeafSetObserver::getClass0()
{
    return class_();
}

