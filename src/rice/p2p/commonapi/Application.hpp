// Generated from /pastry-2.1/src/rice/p2p/commonapi/Application.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::Application
    : public virtual ::java::lang::Object
{
    virtual bool forward(RouteMessage* message) = 0;
    virtual void deliver(Id* id, Message* message) = 0;
    virtual void update(NodeHandle* handle, bool joined) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
