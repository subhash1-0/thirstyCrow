// Generated from /pastry-2.1/src/rice/pastry/boot/Bootstrapper.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::boot::Bootstrapper
    : public virtual ::java::lang::Object
{
    virtual void boot(::java::util::Collection* bootaddresses) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
