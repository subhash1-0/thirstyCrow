// Generated from /pastry-2.1/src/rice/pastry/join/JoinProtocol.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::join::JoinProtocol
    : public virtual ::java::lang::Object
{
    virtual void initiateJoin(::java::util::Collection* bootstrap) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
