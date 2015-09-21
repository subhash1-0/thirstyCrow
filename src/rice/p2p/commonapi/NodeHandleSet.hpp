// Generated from /pastry-2.1/src/rice/p2p/commonapi/NodeHandleSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::commonapi::NodeHandleSet
    : public virtual ::java::io::Serializable
{
    virtual bool putHandle(NodeHandle* handle) = 0;
    virtual NodeHandle* getHandle(Id* id) = 0;
    virtual NodeHandle* getHandle(int32_t i) = 0;
    virtual bool memberHandle(Id* id) = 0;
    virtual NodeHandle* removeHandle(Id* id) = 0;
    virtual int32_t size() = 0;
    virtual int32_t getIndexHandle(Id* id) /* throws(NoSuchElementException) */ = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;
    virtual int16_t getType() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
