// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_rateLimitedRetrieveFragment_31.hpp>

#include <rice/p2p/glacier/v2/GlacierImpl.hpp>

rice::p2p::glacier::v2::GlacierImpl_rateLimitedRetrieveFragment_31::GlacierImpl_rateLimitedRetrieveFragment_31(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::FragmentKey* key, Manifest* manifest, char16_t tag, GlacierContinuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , key(key)
    , manifest(manifest)
    , tag(tag)
    , c(c)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_rateLimitedRetrieveFragment_31::receiveResult(::java::lang::Object* o)
{
    GlacierImpl_this->retrieveFragment(key, manifest, tag, c);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_rateLimitedRetrieveFragment_31::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_rateLimitedRetrieveFragment_31::getClass0()
{
    return class_();
}

