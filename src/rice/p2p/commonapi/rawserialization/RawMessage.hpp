// Generated from /pastry-2.1/src/rice/p2p/commonapi/rawserialization/RawMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct rice::p2p::commonapi::rawserialization::RawMessage
    : public virtual ::rice::p2p::commonapi::Message
    , public virtual RawSerializable
{
    virtual int16_t getType() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
