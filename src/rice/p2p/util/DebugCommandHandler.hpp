// Generated from /pastry-2.1/src/rice/p2p/util/DebugCommandHandler.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::util::DebugCommandHandler
    : public virtual ::java::lang::Object
{
    virtual ::java::lang::String* handleDebugCommand(::java::lang::String* command) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
