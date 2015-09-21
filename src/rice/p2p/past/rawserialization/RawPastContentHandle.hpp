// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/RawPastContentHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>

struct rice::p2p::past::rawserialization::RawPastContentHandle
    : public virtual ::rice::p2p::past::PastContentHandle
{
    virtual int16_t getType() = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
