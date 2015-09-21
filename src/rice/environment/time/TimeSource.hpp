// Generated from /pastry-2.1/src/rice/environment/time/TimeSource.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>

struct rice::environment::time::TimeSource
    : public virtual ::rice::Destructable
{
    virtual int64_t currentTimeMillis() = 0;
    virtual void sleep(int64_t delay) /* throws(InterruptedException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
