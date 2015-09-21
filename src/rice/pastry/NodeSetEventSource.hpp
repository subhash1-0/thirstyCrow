// Generated from /pastry-2.1/src/rice/pastry/NodeSetEventSource.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::NodeSetEventSource
    : public virtual ::java::lang::Object
{
    virtual void addNodeSetListener(NodeSetListener* listener) = 0;
    virtual void removeNodeSetListener(NodeSetListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
