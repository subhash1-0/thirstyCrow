// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/SubscribeFailedMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/AbstractSubscribeMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::SubscribeFailedMessage
    : public AbstractSubscribeMessage
{

public:
    typedef AbstractSubscribeMessage super;
    static constexpr int16_t TYPE { int16_t(4) };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static SubscribeFailedMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    SubscribeFailedMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id);

private:
    SubscribeFailedMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    SubscribeFailedMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
