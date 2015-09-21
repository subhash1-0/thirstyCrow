// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpointMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::commonapi::PastryEndpointMessage
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;

private:
    static constexpr int64_t serialVersionUID { int64_t(4499456388556140871LL) };

public: /* protected */
    ::rice::p2p::commonapi::rawserialization::RawMessage* message {  };
protected:
    void ctor(int32_t address, ::rice::p2p::commonapi::Message* message, ::rice::pastry::NodeHandle* sender);

public:
    static void checkRawType(::rice::p2p::commonapi::rawserialization::RawMessage* message);
protected:
    void ctor(int32_t address, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::pastry::NodeHandle* sender);

public:
    virtual ::rice::p2p::commonapi::Message* getMessage();
    virtual void setMessage(::rice::p2p::commonapi::Message* message);
    virtual void setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message);
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(int32_t address, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */;

    // Generated

public:
    PastryEndpointMessage(int32_t address, ::rice::p2p::commonapi::Message* message, ::rice::pastry::NodeHandle* sender);
    PastryEndpointMessage(int32_t address, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::rice::pastry::NodeHandle* sender);
    PastryEndpointMessage(int32_t address, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender);
protected:
    PastryEndpointMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
