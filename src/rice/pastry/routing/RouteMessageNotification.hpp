// Generated from /pastry-2.1/src/rice/pastry/routing/RouteMessageNotification.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::routing::RouteMessageNotification
    : public virtual ::java::lang::Object
{
    virtual void sendFailed(RouteMessage* message, ::java::lang::Exception* e) = 0;
    virtual void sendSuccess(RouteMessage* message, ::rice::pastry::NodeHandle* nextHop) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
