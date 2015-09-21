// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java

#pragma once

#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::past::PastImpl_MessageBuilder
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::past::messaging::PastMessage* buildMessage() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
