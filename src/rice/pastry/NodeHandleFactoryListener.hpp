// Generated from /pastry-2.1/src/rice/pastry/NodeHandleFactoryListener.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::NodeHandleFactoryListener
    : public virtual ::java::lang::Object
{
    virtual void nodeHandleFound(NodeHandle* nodeHandle) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
