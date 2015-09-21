// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousJoinProtocol
    : public ::rice::pastry::standard::ConsistentJoinProtocol
{

public:
    typedef ::rice::pastry::standard::ConsistentJoinProtocol super;

public: /* package */
    ::org::mpisws::p2p::transport::rendezvous::PilotManager* pilotManager {  };
protected:
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::org::mpisws::p2p::transport::rendezvous::PilotManager* pilotManager);

public: /* protected */
    void getJoinRequest(::rice::pastry::NodeHandle* b, ::rice::Continuation* deliverJRToMe) override;
    ::java::util::Map* getOptions(::rice::pastry::join::JoinRequest* jr, ::java::util::Map* existing) override;

    // Generated

public:
    RendezvousJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::ReadyStrategy* nextReadyStrategy, ::org::mpisws::p2p::transport::rendezvous::PilotManager* pilotManager);
protected:
    RendezvousJoinProtocol(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousJoinProtocol_getJoinRequest_1;
    friend class RendezvousJoinProtocol_RCJPDeserializer;
};
