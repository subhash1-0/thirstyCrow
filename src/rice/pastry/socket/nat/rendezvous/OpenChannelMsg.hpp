// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/OpenChannelMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::OpenChannelMsg
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(3) };

public: /* package */
    RendezvousSocketNodeHandle* rendezvous {  };
    RendezvousSocketNodeHandle* source {  };
    int32_t uid {  };
protected:
    void ctor(int32_t address, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid);

public:
    virtual RendezvousSocketNodeHandle* getRendezvous();
    virtual RendezvousSocketNodeHandle* getSource();
    virtual int32_t getUid();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    OpenChannelMsg(int32_t address, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid);
protected:
    OpenChannelMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
