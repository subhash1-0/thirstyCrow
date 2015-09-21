// Generated from /pastry-2.1/src/rice/p2p/commonapi/Cancellable.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::Cancellable
    : public virtual ::java::lang::Object
{
    virtual bool cancel() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
