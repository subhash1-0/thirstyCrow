// Generated from /pastry-2.1/src/rice/pastry/transport/PMessageNotification.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::transport::PMessageNotification
    : public virtual ::java::lang::Object
{
    virtual void sendFailed(PMessageReceipt* msg, ::java::lang::Exception* reason) = 0;
    virtual void sent(PMessageReceipt* msg) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
