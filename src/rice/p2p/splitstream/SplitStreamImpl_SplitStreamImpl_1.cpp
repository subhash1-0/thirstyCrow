// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamImpl.java
#include <rice/p2p/splitstream/SplitStreamImpl_SplitStreamImpl_1.hpp>

#include <rice/p2p/splitstream/SplitStreamImpl.hpp>
#include <rice/p2p/splitstream/SplitStreamScribePolicy.hpp>

rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_1::SplitStreamImpl_SplitStreamImpl_1(SplitStreamImpl *SplitStreamImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SplitStreamImpl_this(SplitStreamImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::scribe::ScribePolicy* rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_1::getSplitStreamScribePolicy(::rice::p2p::scribe::Scribe* scribe, SplitStream* splitstream)
{
    return new SplitStreamScribePolicy(scribe, splitstream);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_1::getClass0()
{
    return class_();
}

