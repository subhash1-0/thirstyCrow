// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamScribePolicyFactory.java

#pragma once

#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::splitstream::SplitStreamScribePolicyFactory
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::scribe::ScribePolicy* getSplitStreamScribePolicy(::rice::p2p::scribe::Scribe* scribe, SplitStream* splitstream) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
