// Generated from /pastry-2.1/src/rice/environment/logging/CloneableLogManager.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/LogManager.hpp>

struct rice::environment::logging::CloneableLogManager
    : public virtual LogManager
{
    virtual LogManager* clone(::java::lang::String* detail) = 0;
    virtual LogManager* clone(::java::lang::String* detail, ::rice::environment::time::TimeSource* ts) = 0;
    virtual ::java::lang::String* getPrefix() = 0;

    // Generated
    static ::java::lang::Class *class_();

public: /* protected */
    virtual ::java::lang::Object* clone();
};
