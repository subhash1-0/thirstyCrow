// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/AbstractSubscribeMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::AbstractSubscribeMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int32_t id {  };
    ::rice::p2p::commonapi::NodeHandle* source {  };
    ::java::util::List* topics {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id);

public:
    virtual int32_t getId();
    int32_t getPriority() override;
    virtual ::rice::p2p::commonapi::NodeHandle* getSource();
    virtual ::java::util::List* getTopics();
    ::java::lang::String* toString() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    AbstractSubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id);

public: /* protected */
    AbstractSubscribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    AbstractSubscribeMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
