// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/join/JoinProtocol.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardJoinProtocol
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::rice::pastry::join::JoinProtocol
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

public: /* protected */
    ::rice::pastry::NodeHandle* localHandle {  };
    ::rice::pastry::routing::RoutingTable* routeTable {  };
    ::rice::pastry::leafset::LeafSet* leafSet {  };
protected:
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls);
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);

public:
    int32_t getAddress() override;

public: /* protected */
    ::rice::pastry::ScheduledMessage* joinEvent {  };

public:
    void initiateJoin(::java::util::Collection* bootstrap) override;
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;

public: /* protected */
    virtual void handleInitiateJoin(::rice::pastry::join::InitiateJoin* ij);
    virtual void getJoinRequest(::rice::pastry::NodeHandle* bootstrap, ::rice::Continuation* deliverJRToMe);
    virtual void handleIntermediateHop(::rice::pastry::routing::RouteMessage* rm);
    virtual void handleJoinRequest(::rice::pastry::join::JoinRequest* jr);
    virtual void respondToJoiner(::rice::pastry::join::JoinRequest* jr);
    virtual ::java::util::Map* getOptions(::rice::pastry::join::JoinRequest* jr, ::java::util::Map* existing);
    virtual void completeJoin(::rice::pastry::join::JoinRequest* jr);
    virtual void setReady();

public:
    virtual void broadcastRows(::rice::pastry::join::JoinRequest* jr);
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    bool deliverWhenNotReady() override;

    // Generated
    StandardJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls);
    StandardJoinProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::NodeHandle* lh, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);
protected:
    StandardJoinProtocol(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardJoinProtocol_SJPDeserializer;
    friend class StandardJoinProtocol_handleInitiateJoin_1;
    friend class StandardJoinProtocol_handleIntermediateHop_2;
    friend class StandardJoinProtocol_respondToJoiner_3;
};
