// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/PastContentDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::past::rawserialization::PastContentDeserializer
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::past::PastContent* deserializePastContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
