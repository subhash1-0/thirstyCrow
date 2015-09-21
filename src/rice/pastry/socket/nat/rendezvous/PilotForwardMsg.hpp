// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/PilotForwardMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::PilotForwardMsg
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(2) };

public: /* protected */
    ByteBufferMsg* msg {  };
    RendezvousSocketNodeHandle* target {  };
protected:
    void ctor(int32_t address, ByteBufferMsg* msg, RendezvousSocketNodeHandle* target);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ByteBufferMsg* getBBMsg();
    virtual RendezvousSocketNodeHandle* getTarget();
    ::java::lang::String* toString() override;

    // Generated
    PilotForwardMsg(int32_t address, ByteBufferMsg* msg, RendezvousSocketNodeHandle* target);
protected:
    PilotForwardMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
