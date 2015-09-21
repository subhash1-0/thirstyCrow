// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSPNFIdentitySerializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SPNFIdentitySerializer.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSPNFIdentitySerializer
    : public ::rice::pastry::socket::SPNFIdentitySerializer
{

public:
    typedef ::rice::pastry::socket::SPNFIdentitySerializer super;
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketNodeHandleFactory* factory);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, ::rice::pastry::socket::TransportLayerNodeHandle* i) /* throws(IOException) */ override;

public: /* protected */
    ::rice::pastry::socket::SocketNodeHandle* buildSNH(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* nid) /* throws(IOException) */ override;

    // Generated
    RendezvousSPNFIdentitySerializer(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketNodeHandleFactory* factory);
protected:
    RendezvousSPNFIdentitySerializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, ::java::lang::Object* i) override;

private:
    virtual ::java::lang::Class* getClass0();
};
