// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/RawMessageDeserializer.java

#pragma once

#include <org/mpisws/p2p/transport/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::commonapi::RawMessageDeserializer
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::rawserialization::RawMessage* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::RawMessage* m, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
