// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastException.java
#include <rice/p2p/past/gc/GCPastException_ObjectNotFoundException.hpp>

#include <rice/p2p/past/gc/GCPastException.hpp>

rice::p2p::past::gc::GCPastException_ObjectNotFoundException::GCPastException_ObjectNotFoundException(GCPastException *GCPastException_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastException_this(GCPastException_this)
{
    clinit();
}

rice::p2p::past::gc::GCPastException_ObjectNotFoundException::GCPastException_ObjectNotFoundException(GCPastException *GCPastException_this, ::java::lang::String* msg) 
    : GCPastException_ObjectNotFoundException(GCPastException_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::p2p::past::gc::GCPastException_ObjectNotFoundException::ctor(::java::lang::String* msg)
{
    super::ctor(msg);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastException_ObjectNotFoundException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCPastException.ObjectNotFoundException", 56);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastException_ObjectNotFoundException::getClass0()
{
    return class_();
}

