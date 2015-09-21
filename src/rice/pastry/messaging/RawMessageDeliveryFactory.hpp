// Generated from /pastry-2.1/src/rice/pastry/messaging/RawMessageDeliveryFactory.java

#pragma once

#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::messaging::RawMessageDeliveryFactory
    : public virtual ::java::lang::Object
{
    virtual RawMessageDelivery* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
