// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamImpl.java

#pragma once

#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/splitstream/SplitStreamScribePolicyFactory.hpp>

struct default_init_tag;

class rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_1
    : public virtual ::java::lang::Object
    , public virtual SplitStreamScribePolicyFactory
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::scribe::ScribePolicy* getSplitStreamScribePolicy(::rice::p2p::scribe::Scribe* scribe, SplitStream* splitstream) override;

    // Generated
    SplitStreamImpl_SplitStreamImpl_1(SplitStreamImpl *SplitStreamImpl_this);
    static ::java::lang::Class *class_();
    SplitStreamImpl *SplitStreamImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamImpl;
    friend class SplitStreamImpl_SplitStreamImpl_2;
};
