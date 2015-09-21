// Generated from /pastry-2.1/src/rice/p2p/commonapi/CancellableTask.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct rice::p2p::commonapi::CancellableTask
    : public virtual Cancellable
{
    virtual void run() = 0;
    virtual int64_t scheduledExecutionTime() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
