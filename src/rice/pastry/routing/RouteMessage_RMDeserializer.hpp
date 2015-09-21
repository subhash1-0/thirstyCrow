// Generated from /pastry-2.1/src/rice/pastry/routing/RouteMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PJavaSerializedDeserializer.hpp>

struct default_init_tag;

class rice::pastry::routing::RouteMessage_RMDeserializer
    : public ::rice::pastry::messaging::PJavaSerializedDeserializer
{

public:
    typedef ::rice::pastry::messaging::PJavaSerializedDeserializer super;

public: /* package */
    ::rice::p2p::commonapi::rawserialization::MessageDeserializer* sub {  };
protected:
    void ctor();

public:
    virtual void setSubDeserializer(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);
    ::rice::pastry::messaging::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    RouteMessage_RMDeserializer(RouteMessage *RouteMessage_this);
protected:
    RouteMessage_RMDeserializer(RouteMessage *RouteMessage_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender);
    RouteMessage *RouteMessage_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RouteMessage;
};
