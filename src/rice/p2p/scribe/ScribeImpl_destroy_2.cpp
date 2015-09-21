// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java
#include <rice/p2p/scribe/ScribeImpl_destroy_2.hpp>

#include <rice/p2p/scribe/ScribeImpl.hpp>

rice::p2p::scribe::ScribeImpl_destroy_2::ScribeImpl_destroy_2(ScribeImpl *ScribeImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , ScribeImpl_this(ScribeImpl_this)
{
    clinit();
    ctor();
}

void rice::p2p::scribe::ScribeImpl_destroy_2::run()
{
    ScribeImpl_this->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribeImpl_destroy_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::scribe::ScribeImpl_destroy_2::getClass0()
{
    return class_();
}

