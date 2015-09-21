// Generated from /pastry-2.1/src/rice/p2p/commonapi/rawserialization/RawSerializable.java

#pragma once

#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::rawserialization::RawSerializable
    : public virtual ::java::lang::Object
{
    virtual void serialize(OutputBuffer* buf) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
