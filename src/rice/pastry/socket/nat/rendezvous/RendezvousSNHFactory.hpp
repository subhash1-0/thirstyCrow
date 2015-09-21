// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSNHFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSNHFactory
    : public ::rice::pastry::socket::SocketNodeHandleFactory
{

public:
    typedef ::rice::pastry::socket::SocketNodeHandleFactory super;
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    ::rice::pastry::socket::SocketNodeHandle* getNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* id) override;
    virtual ::rice::pastry::socket::SocketNodeHandle* getNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* id, int8_t contactState);
    ::rice::pastry::socket::SocketNodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    RendezvousSNHFactory(::rice::pastry::PastryNode* pn);
protected:
    RendezvousSNHFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
