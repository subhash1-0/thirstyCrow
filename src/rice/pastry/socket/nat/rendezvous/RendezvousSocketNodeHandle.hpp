// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle
    : public ::rice::pastry::socket::SocketNodeHandle
    , public virtual ::org::mpisws::p2p::transport::rendezvous::RendezvousContact
{

public:
    typedef ::rice::pastry::socket::SocketNodeHandle super;
    static constexpr int8_t CONTACT_DIRECT { int8_t(0) };
    static constexpr int8_t CONTACT_FIREWALLED { int8_t(1) };

private:
    int8_t contactStatus {  };
protected:
    void ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node, int8_t contactStatus);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    bool canContactDirect() override;

public: /* package */
    static ::rice::pastry::socket::SocketNodeHandle* RendezvousSocketNodeHandle_build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::PastryNode* local) /* throws(IOException) */;

public:
    virtual int8_t getContactStatus();
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    RendezvousSocketNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node, int8_t contactStatus);
protected:
    RendezvousSocketNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
