// Generated from /pastry-2.1/src/rice/selector/Timer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::selector::Timer
    : public virtual ::java::lang::Object
{
    virtual TimerTask* scheduleAtFixedRate(TimerTask* task, int64_t delay, int64_t period) = 0;
    virtual TimerTask* schedule(TimerTask* task, int64_t delay) = 0;
    virtual TimerTask* schedule(TimerTask* task, int64_t delay, int64_t period) = 0;
    virtual TimerTask* schedule(TimerTask* dtt) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
