// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;

public: /* protected */
    ::java::lang::String* CONTACT_STATE {  };
    ::rice::environment::random::RandomSource* random {  };

private:
    static ::java::lang::String* RENDEZVOUS_STRATEGY_;
    static ::java::lang::String* RENDEZVOUS_TL_;
    static ::java::lang::String* SIMULATE_FIREWALL_;
    static ::java::lang::String* RENDEZVOUS_CONTACT_DIRECT_STRATEGY_;

public: /* package */
    int8_t localContactState {  };
protected:
    void ctor(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, bool firewalled) /* throws(IOException) */;
    void ctor(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env, bool firewalled) /* throws(IOException) */;

private:
    void init_(bool firewalled);

public:
    virtual void setContactState(int8_t contactState);

public: /* protected */
    virtual void newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, bool firewalled);
    virtual void newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, int8_t contactState);
    ::rice::pastry::join::JoinProtocol* getJoinProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::ReadyStrategy* lsProtocol) override;
    ::org::mpisws::p2p::transport::TransportLayer* getIpServiceTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;
    ::org::mpisws::p2p::transport::identity::IdentitySerializer* getIdentiySerializer(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketNodeHandleFactory* handleFactory) override;
    virtual ::org::mpisws::p2p::transport::TransportLayer* getRendezvousTransportLayer(::org::mpisws::p2p::transport::TransportLayer* mtl, ::rice::pastry::PastryNode* pn);
    ::org::mpisws::p2p::transport::sourceroute::manager::simple::NextHopStrategy* getNextHopStrategy(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */ override;
    virtual ::org::mpisws::p2p::transport::rendezvous::ResponseStrategy* getResponseStrategy(::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* getContactDirectStrategy(::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::rendezvous::PilotFinder* getPilotFinder(::rice::pastry::PastryNode* pn);
    virtual void generatePilotStrategy(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl* rendezvousLayer);
    virtual ::org::mpisws::p2p::transport::rendezvous::ContactDeserializer* getContactDeserializer(::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::rendezvous::RendezvousGenerationStrategy* getRendezvousGenerator(::rice::pastry::PastryNode* pn);
    ::rice::pastry::standard::ProximityNeighborSelector* getProximityNeighborSelector(::rice::pastry::PastryNode* pn) override;
    virtual ::org::mpisws::p2p::transport::rendezvous::RendezvousStrategy* getRendezvousStrategyHelper(::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::rendezvous::RendezvousStrategy* getRendezvousStrategy(::rice::pastry::PastryNode* pn);
    void registerApps(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::transport::NodeHandleAdapter* nha, ::rice::pastry::NodeHandleFactory* handleFactory) override;

public:
    ::rice::pastry::NodeHandleFactory* getNodeHandleFactory(::rice::pastry::PastryNode* pn) override;

public: /* package */
    bool firstNode {  };

public:
    ::rice::pastry::NodeHandle* getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf) override;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;
    ::org::mpisws::p2p::transport::priority::PriorityTransportLayer* getPriorityTransportLayer(::org::mpisws::p2p::transport::TransportLayer* trans, ::org::mpisws::p2p::transport::liveness::LivenessProvider* liveness, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::rice::pastry::PastryNode* pn) override;
    ::rice::pastry::boot::Bootstrapper* getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns) override;
    virtual bool isInternetRoutablePrefix(::java::net::InetAddress* address);

    // Generated

public:
    RendezvousSocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, bool firewalled);
    RendezvousSocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env, bool firewalled);
protected:
    RendezvousSocketPastryNodeFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public: /* protected */
    virtual void newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars);

public:
    static ::java::lang::String*& RENDEZVOUS_STRATEGY();
    static ::java::lang::String*& RENDEZVOUS_TL();
    static ::java::lang::String*& SIMULATE_FIREWALL();
    static ::java::lang::String*& RENDEZVOUS_CONTACT_DIRECT_STRATEGY();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousSocketPastryNodeFactory_getContactDeserializer_1;
    friend class RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_3;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4;
    friend class RendezvousSocketPastryNodeFactory_getBootstrapper_4_checkLiveness_4_1;
};
