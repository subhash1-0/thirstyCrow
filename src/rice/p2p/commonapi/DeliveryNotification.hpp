// Generated from /pastry-2.1/src/rice/p2p/commonapi/DeliveryNotification.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::DeliveryNotification
    : public virtual ::java::lang::Object
{
    virtual void sent(MessageReceipt* msg) = 0;
    virtual void sendFailed(MessageReceipt* msg, ::java::lang::Exception* reason) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
