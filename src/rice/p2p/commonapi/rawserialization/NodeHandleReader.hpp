// Generated from /pastry-2.1/src/rice/p2p/commonapi/rawserialization/NodeHandleReader.java

#pragma once

#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::rawserialization::NodeHandleReader
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::NodeHandle* readNodeHandle(InputBuffer* buf) /* throws(IOException) */ = 0;
    virtual ::rice::p2p::commonapi::NodeHandle* coalesce(::rice::p2p::commonapi::NodeHandle* handle) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
