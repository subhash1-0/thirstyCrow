// Generated from /pastry-2.1/src/rice/selector/LoopObserver.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::selector::LoopObserver
    : public virtual ::java::lang::Object
{
    virtual int32_t delayInterest() = 0;
    virtual void loopTime(int32_t loopTime) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
