// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinRequest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/JoinRequest.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousJoinRequest
    : public ::rice::pastry::join::JoinRequest
{

public:
    typedef ::rice::pastry::join::JoinRequest super;
    static constexpr int16_t TYPE { int16_t(4) };

public: /* protected */
    ::rice::pastry::NodeHandle* pilot {  };
protected:
    void ctor(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp, ::rice::pastry::NodeHandle* pilot);

public:
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode) /* throws(IOException) */;

public:
    virtual ::rice::pastry::NodeHandle* getPilot();

    // Generated
    RendezvousJoinRequest(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp, ::rice::pastry::NodeHandle* pilot);
    RendezvousJoinRequest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode);
protected:
    RendezvousJoinRequest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
