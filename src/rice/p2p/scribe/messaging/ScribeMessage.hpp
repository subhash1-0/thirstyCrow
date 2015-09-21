// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/ScribeMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::ScribeMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(4593674882226544604LL) };

public: /* protected */
    ::rice::p2p::commonapi::NodeHandle* source {  };
    ::rice::p2p::scribe::Topic* topic {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic);

public:
    int32_t getPriority() override;
    virtual ::rice::p2p::commonapi::NodeHandle* getSource();
    virtual void setSource(::rice::p2p::commonapi::NodeHandle* source);
    virtual ::rice::p2p::scribe::Topic* getTopic();
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated

public: /* protected */
    ScribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic);
    ScribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    ScribeMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
