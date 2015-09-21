// Generated from /pastry-2.1/src/rice/pastry/transport/TransportPastryNodeFactory.java
#include <rice/pastry/transport/TransportPastryNodeFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/ReadyStrategy.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/join/JoinProtocol.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/LeafSetProtocol.hpp>
#include <rice/pastry/messaging/MessageDispatch.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>
#include <rice/pastry/routing/RouteSetProtocol.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/ConsistentJoinProtocol.hpp>
#include <rice/pastry/standard/PeriodicLeafSetProtocol.hpp>
#include <rice/pastry/standard/ProximityNeighborSelector.hpp>
#include <rice/pastry/standard/RapidRerouter.hpp>
#include <rice/pastry/standard/StandardRouteSetProtocol.hpp>
#include <rice/pastry/standard/StandardRouter.hpp>
#include <rice/pastry/transport/NodeHandleAdapter.hpp>
#include <rice/pastry/transport/TLDeserializer.hpp>
#include <rice/pastry/transport/TransportPastryNodeFactory_getProximityNeighborSelector_1.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::transport::TransportPastryNodeFactory::TransportPastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::transport::TransportPastryNodeFactory::TransportPastryNodeFactory(::rice::environment::Environment* env) 
    : TransportPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::transport::TransportPastryNodeFactory::ctor(::rice::environment::Environment* env)
{
    super::ctor(env);
    auto params = npc(env)->getParameters();
    leafSetMaintFreq = npc(params)->getInt(u"pastry_leafSetMaintFreq"_j);
    routeSetMaintFreq = npc(params)->getInt(u"pastry_routeSetMaintFreq"_j);
}

rice::pastry::PastryNode* rice::pastry::transport::TransportPastryNodeFactory::nodeHandleHelper(::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto handleFactory = getNodeHandleFactory(pn);
    auto localhandle = getLocalHandle(pn, handleFactory);
    auto deserializer = getTLDeserializer(handleFactory, pn);
    auto msgDisp = new ::rice::pastry::messaging::MessageDispatch(pn, deserializer);
    auto routeTable = new ::rice::pastry::routing::RoutingTable(localhandle, rtMax, rtBase, pn);
    auto leafSet = new ::rice::pastry::leafset::LeafSet(localhandle, static_cast< int32_t >(lSetSize), routeTable);
    ::rice::pastry::standard::StandardRouter* router = new ::rice::pastry::standard::RapidRerouter(pn, msgDisp, getRouterStrategy(pn));
    npc(pn)->setElements(localhandle, msgDisp, leafSet, routeTable, router);
    auto nha = getNodeHandleAdapter(pn, handleFactory, deserializer);
    npc(pn)->setSocketElements(leafSetMaintFreq, routeSetMaintFreq, nha, nha, nha, handleFactory);
    npc(router)->register_();
    registerApps(pn, leafSet, routeTable, nha, handleFactory);
    return pn;
}

rice::pastry::routing::RouterStrategy* rice::pastry::transport::TransportPastryNodeFactory::getRouterStrategy(::rice::pastry::PastryNode* pn)
{
    return nullptr;
}

void rice::pastry::transport::TransportPastryNodeFactory::registerApps(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, NodeHandleAdapter* nha, ::rice::pastry::NodeHandleFactory* handleFactory)
{
    auto pns = getProximityNeighborSelector(pn);
    auto bootstrapper = getBootstrapper(pn, nha, handleFactory, pns);
    auto rsProtocol = getRouteSetProtocol(pn, leafSet, routeTable);
    auto lsProtocol = getLeafSetProtocol(pn, leafSet, routeTable);
    ::rice::pastry::ReadyStrategy* readyStrategy;
    if(dynamic_cast< ::rice::pastry::ReadyStrategy* >(lsProtocol) != nullptr) {
        readyStrategy = java_cast< ::rice::pastry::ReadyStrategy* >(lsProtocol);
    } else {
        readyStrategy = npc(pn)->getDefaultReadyStrategy();
    }
    auto jProtocol = getJoinProtocol(pn, leafSet, routeTable, readyStrategy);
    npc(pn)->setJoinProtocols(bootstrapper, jProtocol, lsProtocol, rsProtocol);
}

rice::pastry::routing::RouteSetProtocol* rice::pastry::transport::TransportPastryNodeFactory::getRouteSetProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable)
{
    auto rsProtocol = new ::rice::pastry::standard::StandardRouteSetProtocol(pn, routeTable);
    npc(rsProtocol)->register_();
    return rsProtocol;
}

rice::pastry::leafset::LeafSetProtocol* rice::pastry::transport::TransportPastryNodeFactory::getLeafSetProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable)
{
    auto lsProtocol = new ::rice::pastry::standard::PeriodicLeafSetProtocol(pn, npc(pn)->getLocalHandle(), leafSet, routeTable);
    npc(lsProtocol)->register_();
    return lsProtocol;
}

rice::pastry::join::JoinProtocol* rice::pastry::transport::TransportPastryNodeFactory::getJoinProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::ReadyStrategy* lsProtocol)
{
    auto jProtocol = new ::rice::pastry::standard::ConsistentJoinProtocol(pn, npc(pn)->getLocalHandle(), routeTable, leafSet, lsProtocol);
    npc(jProtocol)->register_();
    return jProtocol;
}

rice::pastry::transport::TLDeserializer* rice::pastry::transport::TransportPastryNodeFactory::getTLDeserializer(::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::PastryNode* pn)
{
    auto deserializer = new TLDeserializer(handleFactory, npc(pn)->getEnvironment());
    return deserializer;
}

rice::pastry::standard::ProximityNeighborSelector* rice::pastry::transport::TransportPastryNodeFactory::getProximityNeighborSelector(::rice::pastry::PastryNode* pn)
{
    if(npc(npc(environment)->getParameters())->getBoolean(u"transport_use_pns"_j)) {
        auto pns = new ::rice::pastry::pns::PNSApplication(pn);
        npc(pns)->register_();
        return pns;
    }
    return new TransportPastryNodeFactory_getProximityNeighborSelector_1(this);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::TransportPastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.transport.TransportPastryNodeFactory", 48);
    return c;
}

java::lang::Class* rice::pastry::transport::TransportPastryNodeFactory::getClass0()
{
    return class_();
}

