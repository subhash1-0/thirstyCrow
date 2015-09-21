// Generated from /pastry-2.1/src/rice/pastry/ReadyStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::ReadyStrategy
    : public virtual ::java::lang::Object
{
    virtual void setReady(bool r) = 0;
    virtual bool isReady() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
