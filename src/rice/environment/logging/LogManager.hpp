// Generated from /pastry-2.1/src/rice/environment/logging/LogManager.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::environment::logging::LogManager
    : public virtual ::java::lang::Object
{
    virtual Logger* getLogger(::java::lang::Class* clazz, ::java::lang::String* instance) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
