// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol_CJPDeserializer.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol_RCJPDeserializer
    : public ::rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer
{

public:
    typedef ::rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer super;
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    ::rice::pastry::messaging::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    RendezvousJoinProtocol_RCJPDeserializer(::rice::pastry::PastryNode* pn);
protected:
    RendezvousJoinProtocol_RCJPDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender);

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousJoinProtocol;
    friend class RendezvousJoinProtocol_getJoinRequest_1;
};
