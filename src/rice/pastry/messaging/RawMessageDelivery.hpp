// Generated from /pastry-2.1/src/rice/pastry/messaging/RawMessageDelivery.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::messaging::RawMessageDelivery
    : public virtual ::java::lang::Object
{
    virtual int32_t getAddress() = 0;
    virtual Message* deserialize(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
