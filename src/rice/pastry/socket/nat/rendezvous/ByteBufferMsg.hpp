// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/ByteBufferMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::ByteBufferMsg
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* package */
    ::rice::p2p::commonapi::NodeHandle* originalSender {  };
    ::java::nio::ByteBuffer* buffer {  };
protected:
    void ctor(::java::nio::ByteBuffer* buf, ::rice::p2p::commonapi::NodeHandle* sender, int32_t priority, int32_t dest);

public:
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ::rice::p2p::commonapi::NodeHandle* getOriginalSender();

    // Generated
    ByteBufferMsg(::java::nio::ByteBuffer* buf, ::rice::p2p::commonapi::NodeHandle* sender, int32_t priority, int32_t dest);
protected:
    ByteBufferMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
