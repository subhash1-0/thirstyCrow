// Generated from /pastry-2.1/src/rice/pastry/transport/TransportPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>

struct default_init_tag;

class rice::pastry::transport::TransportPastryNodeFactory
    : public ::rice::pastry::PastryNodeFactory
{

public:
    typedef ::rice::pastry::PastryNodeFactory super;

public: /* protected */
    int32_t leafSetMaintFreq {  };
    int32_t routeSetMaintFreq {  };
protected:
    void ctor(::rice::environment::Environment* env);

public:
    virtual ::rice::pastry::PastryNode* nodeHandleHelper(::rice::pastry::PastryNode* pn) /* throws(IOException) */;

public: /* protected */
    virtual ::rice::pastry::routing::RouterStrategy* getRouterStrategy(::rice::pastry::PastryNode* pn);
    virtual void registerApps(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, NodeHandleAdapter* nha, ::rice::pastry::NodeHandleFactory* handleFactory);
    virtual ::rice::pastry::routing::RouteSetProtocol* getRouteSetProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable);
    virtual ::rice::pastry::leafset::LeafSetProtocol* getLeafSetProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable);
    virtual ::rice::pastry::join::JoinProtocol* getJoinProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::ReadyStrategy* lsProtocol);
    virtual TLDeserializer* getTLDeserializer(::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::PastryNode* pn);
    virtual ::rice::pastry::standard::ProximityNeighborSelector* getProximityNeighborSelector(::rice::pastry::PastryNode* pn);
    virtual ::rice::pastry::NodeHandle* getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory) /* throws(IOException) */ = 0;
    virtual NodeHandleAdapter* getNodeHandleAdapter(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory, TLDeserializer* deserializer) /* throws(IOException) */ = 0;
    virtual ::rice::pastry::NodeHandleFactory* getNodeHandleFactory(::rice::pastry::PastryNode* pn) /* throws(IOException) */ = 0;
    virtual ::rice::pastry::boot::Bootstrapper* getBootstrapper(::rice::pastry::PastryNode* pn, NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns) = 0;

    // Generated

public:
    TransportPastryNodeFactory(::rice::environment::Environment* env);
protected:
    TransportPastryNodeFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class TransportPastryNodeFactory_getProximityNeighborSelector_1;
};
