// Generated from /pastry-2.1/src/rice/p2p/multiring/messaging/RingMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>

struct default_init_tag;

class rice::p2p::multiring::messaging::RingMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::rawserialization::RawScribeContent
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-7097995807488121199LL) };

public:
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::rice::p2p::multiring::RingId* id {  };
    ::rice::p2p::commonapi::rawserialization::RawMessage* message {  };
    ::java::lang::String* application {  };
protected:
    void ctor(::rice::p2p::multiring::RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application);

public:
    virtual int32_t getPriority();
    virtual ::rice::p2p::multiring::RingId* getId();
    virtual ::rice::p2p::commonapi::rawserialization::RawMessage* getRawMessage();
    virtual ::rice::p2p::commonapi::Message* getMessage();
    virtual ::java::lang::String* getApplication();
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* ringEndpoint, ::java::util::Hashtable* endpoints) /* throws(IOException) */;

    // Generated

public:
    RingMessage(::rice::p2p::multiring::RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application);
    RingMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* ringEndpoint, ::java::util::Hashtable* endpoints);
protected:
    RingMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
