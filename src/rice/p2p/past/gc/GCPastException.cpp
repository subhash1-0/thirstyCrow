// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastException.java
#include <rice/p2p/past/gc/GCPastException.hpp>

rice::p2p::past::gc::GCPastException::GCPastException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCPastException::GCPastException(::java::lang::String* msg) 
    : GCPastException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::p2p::past::gc::GCPastException::ctor(::java::lang::String* msg)
{
    super::ctor(msg);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCPastException", 32);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastException::getClass0()
{
    return class_();
}

