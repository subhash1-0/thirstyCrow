// Generated from /pastry-2.1/src/rice/Executable.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::Executable
    : public virtual ::java::lang::Object
{
    virtual ::java::lang::Object* execute() /* throws(E) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
