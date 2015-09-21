// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribePolicy.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::scribe::ScribePolicy
    : public virtual ::java::lang::Object
{
    virtual ::java::util::List* allowSubscribe(Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ScribeContent* content) = 0;
    virtual void directAnycast(::rice::p2p::scribe::messaging::AnycastMessage* message, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::Collection* children) = 0;
    virtual void childAdded(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual void childRemoved(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual void recvAnycastFail(Topic* topic, ::rice::p2p::commonapi::NodeHandle* failedAtNode, ScribeContent* content) = 0;
    virtual void intermediateNode(::rice::p2p::scribe::messaging::ScribeMessage* message) = 0;
    virtual ScribeContent* divideContent(::java::util::List* theTopics, ScribeContent* content) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
