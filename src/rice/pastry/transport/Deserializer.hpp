// Generated from /pastry-2.1/src/rice/pastry/transport/Deserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::transport::Deserializer
    : public virtual ::java::lang::Object
{
    virtual void setDeserializer(int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) = 0;
    virtual void clearDeserializer(int32_t address) = 0;
    virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer* getDeserializer(int32_t address) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
