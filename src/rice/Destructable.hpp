// Generated from /pastry-2.1/src/rice/Destructable.java

#pragma once

#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::Destructable
    : public virtual ::java::lang::Object
{
    virtual void destroy() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
