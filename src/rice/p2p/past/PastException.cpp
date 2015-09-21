// Generated from /pastry-2.1/src/rice/p2p/past/PastException.java
#include <rice/p2p/past/PastException.hpp>

rice::p2p::past::PastException::PastException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::PastException::PastException(::java::lang::String* msg) 
    : PastException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::p2p::past::PastException::ctor(::java::lang::String* msg)
{
    super::ctor(msg);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.PastException", 27);
    return c;
}

java::lang::Class* rice::p2p::past::PastException::getClass0()
{
    return class_();
}

