// Generated from /pastry-2.1/src/rice/p2p/scribe/Scribe.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribe.hpp>
#include <rice/p2p/scribe/javaserialized/JavaScribe.hpp>

struct rice::p2p::scribe::Scribe
    : public virtual ::rice::p2p::scribe::rawserialization::RawScribe
    , public virtual ::rice::p2p::scribe::javaserialized::JavaScribe
{

    // Generated
    static ::java::lang::Class *class_();
    virtual void anycast(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) = 0;
    virtual void anycast(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void publish(Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) = 0;
    virtual void subscribe(Topic* topic, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) = 0;
    virtual void subscribe(Topic* topic, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(Topic* topic, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(::java::util::Collection* topics, ScribeClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(::java::util::Collection* topics, ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void anycast(Topic* topic, ScribeContent* content) = 0;
    virtual void anycast(Topic* topic, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void publish(Topic* topic, ScribeContent* content) = 0;
    virtual void subscribe(Topic* topic, ScribeClient* client, ScribeContent* content) = 0;
    virtual void subscribe(Topic* topic, ScribeClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(Topic* topic, ScribeMultiClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(::java::util::Collection* topics, ScribeClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(::java::util::Collection* topics, ScribeMultiClient* client, ScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void subscribe(Topic* topic, ScribeClient* client) = 0;
};
