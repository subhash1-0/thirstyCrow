// Generated from /pastry-2.1/src/rice/p2p/scribe/javaserialized/JavaScribe.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/javaserialized/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/BaseScribe.hpp>

struct rice::p2p::scribe::javaserialized::JavaScribe
    : public virtual ::rice::p2p::scribe::BaseScribe
{
    virtual void subscribe(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeClient* client, ::rice::p2p::scribe::ScribeContent* content) = 0;
    virtual void subscribe(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeClient* client, ::rice::p2p::scribe::ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeMultiClient* client, ::rice::p2p::scribe::ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(::java::util::Collection* topics, ::rice::p2p::scribe::ScribeClient* client, ::rice::p2p::scribe::ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(::java::util::Collection* topics, ::rice::p2p::scribe::ScribeMultiClient* client, ::rice::p2p::scribe::ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void publish(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) = 0;
    virtual void anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) = 0;
    virtual void anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual void subscribe(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeClient* client) = 0;
};
