// Generated from /pastry-2.1/src/rice/environment/params/ParameterChangeListener.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::environment::params::ParameterChangeListener
    : public virtual ::java::lang::Object
{
    virtual void parameterChange(::java::lang::String* paramName, ::java::lang::String* newVal) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
