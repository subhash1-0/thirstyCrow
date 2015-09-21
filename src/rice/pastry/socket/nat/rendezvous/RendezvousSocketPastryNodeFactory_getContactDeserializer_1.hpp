// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDeserializer.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getContactDeserializer_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::rendezvous::ContactDeserializer
{

public:
    typedef ::java::lang::Object super;
    virtual ::java::util::Map* getOptions(RendezvousSocketNodeHandle* high);
    RendezvousSocketNodeHandle* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* sib) /* throws(IOException) */ override;
    virtual ::java::net::InetSocketAddress* convert(RendezvousSocketNodeHandle* high);
    virtual void serialize(RendezvousSocketNodeHandle* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual ::java::nio::ByteBuffer* serialize(RendezvousSocketNodeHandle* i) /* throws(IOException) */;

    // Generated
    RendezvousSocketPastryNodeFactory_getContactDeserializer_1(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this, ::rice::pastry::PastryNode* pn);
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* convert(::java::lang::Object* high) override;
    virtual ::java::util::Map* getOptions(::java::lang::Object* high) override;
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) override;
    virtual ::java::nio::ByteBuffer* serialize(::java::lang::Object* i) override;
    RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this;
    ::rice::pastry::PastryNode* pn;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousSocketPastryNodeFactory;
    friend class RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_3;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1;
};
