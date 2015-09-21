// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeMultiClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>

struct rice::p2p::scribe::ScribeMultiClient
    : public virtual ScribeClient
{
    /*bool anycast(Topic* topic, ScribeContent* content); (already declared) */
    /*void deliver(Topic* topic, ScribeContent* content); (already declared) */
    /*void childAdded(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child); (already declared) */
    /*void childRemoved(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child); (already declared) */
    /*void subscribeFailed(Topic* topic); (already declared) */
    virtual void subscribeFailed(::java::util::Collection* topics) = 0;
    virtual void subscribeSuccess(::java::util::Collection* topics) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual void subscribeFailed(Topic* topic) = 0;
};
