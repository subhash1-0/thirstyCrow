// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/FragmentAndManifest.java
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>

#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>

rice::p2p::glacier::v2::FragmentAndManifest::FragmentAndManifest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::FragmentAndManifest::FragmentAndManifest(::rice::p2p::glacier::Fragment* fragment, Manifest* manifest) 
    : FragmentAndManifest(*static_cast< ::default_init_tag* >(0))
{
    ctor(fragment,manifest);
}

void rice::p2p::glacier::v2::FragmentAndManifest::ctor(::rice::p2p::glacier::Fragment* fragment, Manifest* manifest)
{
    super::ctor();
    this->fragment = fragment;
    this->manifest = manifest;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::FragmentAndManifest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.FragmentAndManifest", 39);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::FragmentAndManifest::getClass0()
{
    return class_();
}

