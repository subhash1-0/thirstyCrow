// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/SubscribeAckMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/AbstractSubscribeMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::SubscribeAckMessage
    : public AbstractSubscribeMessage
{

public:
    typedef AbstractSubscribeMessage super;
    static constexpr int16_t TYPE { int16_t(3) };

public: /* protected */
    ::java::util::List* pathsToRoot {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::java::util::List* pathsToRoot, int32_t id);

public:
    virtual ::java::util::List* getPathsToRoot();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static SubscribeAckMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    SubscribeAckMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::java::util::List* pathsToRoot, int32_t id);

private:
    SubscribeAckMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    SubscribeAckMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
