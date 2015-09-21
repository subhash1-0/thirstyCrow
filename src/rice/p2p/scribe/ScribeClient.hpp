// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::scribe::ScribeClient
    : public virtual ::java::lang::Object
{
    virtual bool anycast(Topic* topic, ScribeContent* content) = 0;
    virtual void deliver(Topic* topic, ScribeContent* content) = 0;
    virtual void childAdded(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual void childRemoved(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual void subscribeFailed(Topic* topic) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
