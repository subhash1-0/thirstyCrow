// Generated from /pastry-2.1/src/rice/p2p/scribe/javaserialized/JavaScribeContentDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/javaserialized/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/rawserialization/ScribeContentDeserializer.hpp>

struct default_init_tag;

class rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer
{

public:
    typedef ::java::lang::Object super;
protected:
    void ctor();

public:
    ::rice::p2p::scribe::ScribeContent* deserializeScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */ override;

    // Generated
    JavaScribeContentDeserializer();
protected:
    JavaScribeContentDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
