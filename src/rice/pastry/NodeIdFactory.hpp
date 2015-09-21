// Generated from /pastry-2.1/src/rice/pastry/NodeIdFactory.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::NodeIdFactory
    : public virtual ::java::lang::Object
{
    virtual Id* generateNodeId() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
