// Generated from /pastry-2.1/src/rice/p2p/commonapi/MessageReceipt.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct rice::p2p::commonapi::MessageReceipt
    : public virtual Cancellable
{
    virtual Message* getMessage() = 0;
    virtual Id* getId() = 0;
    virtual NodeHandle* getHint() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
