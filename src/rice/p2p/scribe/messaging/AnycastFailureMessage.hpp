// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/AnycastFailureMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/ScribeMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::AnycastFailureMessage
    : public ScribeMessage
{

public:
    typedef ScribeMessage super;
    static constexpr int16_t TYPE { int16_t(11) };
    ::rice::p2p::scribe::rawserialization::RawScribeContent* content {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content);
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);

public:
    virtual ::rice::p2p::scribe::ScribeContent* getContent();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static AnycastFailureMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* scd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd) /* throws(IOException) */;

    // Generated

public:
    AnycastFailureMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content);
    AnycastFailureMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);

private:
    AnycastFailureMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd);
protected:
    AnycastFailureMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
