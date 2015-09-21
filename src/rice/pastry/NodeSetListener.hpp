// Generated from /pastry-2.1/src/rice/pastry/NodeSetListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::NodeSetListener
    : public virtual ::java::lang::Object
{
    virtual void nodeSetUpdate(NodeSetEventSource* nodeSetEventSource, NodeHandle* handle, bool added) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
