// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/UnsubscribeMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::UnsubscribeMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(10) };

public: /* package */
    ::rice::p2p::commonapi::NodeHandle* source {  };
    ::java::util::List* topics {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics);

public:
    int32_t getPriority() override;
    virtual ::rice::p2p::commonapi::NodeHandle* getSource();
    virtual ::java::util::List* getTopics();
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static UnsubscribeMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    UnsubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics);

private:
    UnsubscribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    UnsubscribeMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
