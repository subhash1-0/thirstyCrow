// Generated from /pastry-2.1/src/rice/p2p/commonapi/rawserialization/MessageDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::rawserialization::MessageDeserializer
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::Message* deserialize(InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
