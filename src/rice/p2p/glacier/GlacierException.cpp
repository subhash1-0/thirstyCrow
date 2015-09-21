// Generated from /pastry-2.1/src/rice/p2p/glacier/GlacierException.java
#include <rice/p2p/glacier/GlacierException.hpp>

rice::p2p::glacier::GlacierException::GlacierException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::GlacierException::GlacierException(::java::lang::String* msg) 
    : GlacierException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::p2p::glacier::GlacierException::ctor(::java::lang::String* msg)
{
    super::ctor(msg);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::GlacierException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.GlacierException", 33);
    return c;
}

java::lang::Class* rice::p2p::glacier::GlacierException::getClass0()
{
    return class_();
}

