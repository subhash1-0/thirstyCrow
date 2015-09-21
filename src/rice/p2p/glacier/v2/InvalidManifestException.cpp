// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/InvalidManifestException.java
#include <rice/p2p/glacier/v2/InvalidManifestException.hpp>

rice::p2p::glacier::v2::InvalidManifestException::InvalidManifestException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::InvalidManifestException::InvalidManifestException(::java::lang::String* msg) 
    : InvalidManifestException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg);
}

void rice::p2p::glacier::v2::InvalidManifestException::ctor(::java::lang::String* msg)
{
    super::ctor(msg);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::InvalidManifestException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.InvalidManifestException", 44);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::InvalidManifestException::getClass0()
{
    return class_();
}

