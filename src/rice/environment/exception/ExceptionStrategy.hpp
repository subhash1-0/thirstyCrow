// Generated from /pastry-2.1/src/rice/environment/exception/ExceptionStrategy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/exception/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::environment::exception::ExceptionStrategy
    : public virtual ::java::lang::Object
{
    virtual void handleException(::java::lang::Object* source, ::java::lang::Throwable* t) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
