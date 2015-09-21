// Generated from /pastry-2.1/src/rice/pastry/NodeHandleFactory.java

#pragma once

#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::NodeHandleFactory
    : public virtual ::java::lang::Object
{
    virtual NodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ = 0;
    virtual NodeHandle* coalesce(NodeHandle* handle) = 0;
    virtual void addNodeHandleFactoryListener(NodeHandleFactoryListener* listener) = 0;
    virtual void removeNodeHandleFactoryListener(NodeHandleFactoryListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
