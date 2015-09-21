// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/SubscribeMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/AnycastMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::SubscribeMessage
    : public AnycastMessage
{

public:
    typedef AnycastMessage super;
    static constexpr int16_t TYPE { int16_t(2) };

public: /* protected */
    ::rice::p2p::commonapi::NodeHandle* subscriber {  };
    int32_t id {  };

public: /* package */
    ::java::util::List* topics {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);

public:
    virtual ::rice::p2p::commonapi::NodeHandle* getSubscriber();
    virtual int32_t getId();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static SubscribeMessage* buildSM(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* scd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* contentDeserializer) /* throws(IOException) */;

public:
    virtual void removeTopics(::java::util::Collection* accepted);
    virtual ::java::util::List* getTopics();
    virtual bool isEmpty();
    virtual SubscribeMessage* copy(::java::util::List* newTopics, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);

    // Generated
    SubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);
    SubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, int32_t id, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);

private:
    SubscribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* contentDeserializer);
protected:
    SubscribeMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
