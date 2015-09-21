// Generated from /pastry-2.1/src/rice/Continuation.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::Continuation
    : public virtual ::java::lang::Object
{
    virtual void receiveResult(::java::lang::Object* result) = 0;
    virtual void receiveException(::java::lang::Exception* exception) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
