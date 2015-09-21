// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::splitstream::SplitStreamClient
    : public virtual ::java::lang::Object
{
    virtual void joinFailed(Stripe* s) = 0;
    virtual void deliver(Stripe* s, ::int8_tArray* data) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
