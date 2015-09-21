// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/AddressStrategy.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/multiaddress/SimpleAddressStrategy.hpp>
#include <org/mpisws/p2p/transport/nat/FirewallTLImpl.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDeserializer.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDirectStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotFinder.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotManager.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousGenerationStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ResponseStrategy.hpp>
#include <org/mpisws/p2p/transport/rendezvous/TimeoutResponseStrategy.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>
#include <rice/pastry/socket/nat/rendezvous/LeafSetPilotFinder.hpp>
#include <rice/pastry/socket/nat/rendezvous/LeafSetPilotStrategy.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousApp.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousContactDirectStrategy.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousJoinProtocol.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousLeafSetNHStrategy.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousRouterStrategy.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSNHFactory.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSPNFIdentitySerializer.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getContactDeserializer_1.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getBootstrapper_3.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getBootstrapper_4.hpp>
#include <rice/pastry/standard/StandardRouter.hpp>
#include <rice/pastry/transport/NodeHandleAdapter.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>
#include <Array.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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

rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RendezvousSocketPastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RendezvousSocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, bool firewalled)  /* throws(IOException) */
    : RendezvousSocketPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,bindAddress,startPort,env,firewalled);
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RendezvousSocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env, bool firewalled)  /* throws(IOException) */
    : RendezvousSocketPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,startPort,env,firewalled);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::init()
{
    CONTACT_STATE = u"RendezvousSocketPastryNodeFactory.CONTACT_STATE"_j;
    localContactState = RendezvousSocketNodeHandle::CONTACT_DIRECT;
    firstNode = true;
}

java::lang::String*& rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RENDEZVOUS_STRATEGY()
{
    clinit();
    return RENDEZVOUS_STRATEGY_;
}
java::lang::String* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RENDEZVOUS_STRATEGY_;

java::lang::String*& rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RENDEZVOUS_TL()
{
    clinit();
    return RENDEZVOUS_TL_;
}
java::lang::String* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RENDEZVOUS_TL_;

java::lang::String*& rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::SIMULATE_FIREWALL()
{
    clinit();
    return SIMULATE_FIREWALL_;
}
java::lang::String* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::SIMULATE_FIREWALL_;

java::lang::String*& rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RENDEZVOUS_CONTACT_DIRECT_STRATEGY()
{
    clinit();
    return RENDEZVOUS_CONTACT_DIRECT_STRATEGY_;
}
java::lang::String* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::RENDEZVOUS_CONTACT_DIRECT_STRATEGY_;

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, bool firewalled) /* throws(IOException) */
{
    super::ctor(nf, bindAddress, startPort, env);
    init();
    init_(firewalled);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env, bool firewalled) /* throws(IOException) */
{
    super::ctor(nf, startPort, env);
    init();
    init_(firewalled);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::init_(bool firewalled)
{
    random = npc(environment)->getRandomSource();
    if(firewalled)
        setContactState(RendezvousSocketNodeHandle::CONTACT_FIREWALLED);

}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::setContactState(int8_t contactState)
{
    this->localContactState = contactState;
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, bool firewalled)
{
    auto contactState = localContactState;
    if(firewalled) {
        contactState = RendezvousSocketNodeHandle::CONTACT_FIREWALLED;
    } else {
        contactState = RendezvousSocketNodeHandle::CONTACT_DIRECT;
    }
    newNodeSelector(nodeId, proxyAddress, deliverResultToMe, initialVars, contactState);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, int8_t contactState)
{
    initialVars = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(initialVars, CONTACT_STATE, ::java::lang::Byte::valueOf(contactState));
    super::newNodeSelector(nodeId, proxyAddress, deliverResultToMe, initialVars);
}

rice::pastry::join::JoinProtocol* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getJoinProtocol(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::ReadyStrategy* lsProtocol)
{
    auto jProtocol = new RendezvousJoinProtocol(pn, npc(pn)->getLocalHandle(), routeTable, leafSet, lsProtocol, java_cast< ::org::mpisws::p2p::transport::rendezvous::PilotManager* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(RENDEZVOUS_TL_))));
    npc(jProtocol)->register_();
    return jProtocol;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getIpServiceTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto mtl = java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(super::getIpServiceTransportLayer(wtl, pn));
    if(npc(pn)->getLocalHandle() == nullptr)
        return mtl;

    return getRendezvousTransportLayer(mtl, pn);
}

org::mpisws::p2p::transport::identity::IdentitySerializer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getIdentiySerializer(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketNodeHandleFactory* handleFactory)
{
    return new RendezvousSPNFIdentitySerializer(pn, handleFactory);
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getRendezvousTransportLayer(::org::mpisws::p2p::transport::TransportLayer* mtl, ::rice::pastry::PastryNode* pn)
{
    auto ret = new ::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl(mtl, ::org::mpisws::p2p::transport::identity::IdentityImpl::NODE_HANDLE_FROM_INDEX(), java_cast< RendezvousSocketNodeHandle* >(npc(pn)->getLocalHandle()), getContactDeserializer(pn), getRendezvousGenerator(pn), getPilotFinder(pn), getRendezvousStrategyHelper(pn), getResponseStrategy(pn), getContactDirectStrategy(pn), npc(pn)->getEnvironment());
    npc(npc(pn)->getVars())->put(RENDEZVOUS_TL_, ret);
    npc((java_cast< ::org::mpisws::p2p::transport::rendezvous::RendezvousStrategy* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(RENDEZVOUS_STRATEGY_)))))->setTransportLayer(ret);
    generatePilotStrategy(pn, ret);
    return ret;
}

org::mpisws::p2p::transport::sourceroute::manager::simple::NextHopStrategy* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getNextHopStrategy(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */
{
    return new RendezvousLeafSetNHStrategy(npc(pn)->getLeafSet());
}

org::mpisws::p2p::transport::rendezvous::ResponseStrategy* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getResponseStrategy(::rice::pastry::PastryNode* pn)
{
    return new ::org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy(int32_t(3000), npc(pn)->getEnvironment());
}

org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getContactDirectStrategy(::rice::pastry::PastryNode* pn)
{
    auto adrStrat = java_cast< ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(MULTI_ADDRESS_STRATEGY())));
    if(adrStrat == nullptr) {
        adrStrat = new ::org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy();
    }
    ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* ret = new RendezvousContactDirectStrategy(java_cast< RendezvousSocketNodeHandle* >(npc(pn)->getLocalNodeHandle()), adrStrat, npc(pn)->getEnvironment());
    npc(npc(pn)->getVars())->put(RENDEZVOUS_CONTACT_DIRECT_STRATEGY_, ret);
    return ret;
}

org::mpisws::p2p::transport::rendezvous::PilotFinder* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getPilotFinder(::rice::pastry::PastryNode* pn)
{
    return new LeafSetPilotFinder(pn);
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::generatePilotStrategy(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl* rendezvousLayer)
{
    auto handle = java_cast< RendezvousSocketNodeHandle* >(npc(pn)->getLocalHandle());
    if(handle != nullptr && !npc(handle)->canContactDirect())
        new LeafSetPilotStrategy(npc(pn)->getLeafSet(), rendezvousLayer, npc(pn)->getEnvironment());

}

org::mpisws::p2p::transport::rendezvous::ContactDeserializer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getContactDeserializer(::rice::pastry::PastryNode* pn)
{
    return new RendezvousSocketPastryNodeFactory_getContactDeserializer_1(this, pn);
}

org::mpisws::p2p::transport::rendezvous::RendezvousGenerationStrategy* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getRendezvousGenerator(::rice::pastry::PastryNode* pn)
{
    return nullptr;
}

rice::pastry::standard::ProximityNeighborSelector* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getProximityNeighborSelector(::rice::pastry::PastryNode* pn)
{
    if(npc(npc(environment)->getParameters())->getBoolean(u"transport_use_pns"_j)) {
        auto pns = new RendezvousPNSApplication(pn, java_cast< ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(RENDEZVOUS_CONTACT_DIRECT_STRATEGY_))));
        npc(pns)->register_();
        return pns;
    }
    return new RendezvousSocketPastryNodeFactory_getProximityNeighborSelector_2(this);
}

org::mpisws::p2p::transport::rendezvous::RendezvousStrategy* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getRendezvousStrategyHelper(::rice::pastry::PastryNode* pn)
{
    auto app = getRendezvousStrategy(pn);
    npc(npc(pn)->getVars())->put(RENDEZVOUS_STRATEGY_, app);
    return app;
}

org::mpisws::p2p::transport::rendezvous::RendezvousStrategy* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getRendezvousStrategy(::rice::pastry::PastryNode* pn)
{
    auto app = new RendezvousApp(pn);
    return app;
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::registerApps(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::transport::NodeHandleAdapter* nha, ::rice::pastry::NodeHandleFactory* handleFactory)
{
    super::registerApps(pn, leafSet, routeTable, nha, handleFactory);
    auto app = java_cast< ::org::mpisws::p2p::transport::rendezvous::RendezvousStrategy* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(RENDEZVOUS_STRATEGY_)));
    if(dynamic_cast< RendezvousApp* >(app) != nullptr) {
        npc((java_cast< RendezvousApp* >(app)))->register_();
    }
}

rice::pastry::NodeHandleFactory* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getNodeHandleFactory(::rice::pastry::PastryNode* pn)
{
    return new RendezvousSNHFactory(pn);
}

rice::pastry::NodeHandle* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf)
{
    auto contactState = localContactState;
    if(npc(npc(pn)->getVars())->containsKey(CONTACT_STATE)) {
        contactState = (npc(java_cast< ::java::lang::Byte* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(CONTACT_STATE)))))->byteValue();
    }
    auto p = npc(environment)->getParameters();
    if(firstNode && npc(p)->getBoolean(u"rendezvous_test_makes_bootstrap"_j)) {
        firstNode = false;
    } else if(npc(p)->getBoolean(u"rendezvous_test_firewall"_j)) {
        if(npc(random)->nextFloat() <= npc(p)->getFloat(u"rendezvous_test_num_firewalled"_j)) {
            npc(npc(pn)->getVars())->put(SIMULATE_FIREWALL_, ::java::lang::Boolean::valueOf(true));
            contactState = RendezvousSocketNodeHandle::CONTACT_FIREWALLED;
        }
    }
    auto pnhf = java_cast< RendezvousSNHFactory* >(nhf);
    auto proxyAddress = java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(PROXY_ADDRESS())));
    auto ret = npc(pnhf)->getNodeHandle(proxyAddress, npc(npc(npc(pn)->getEnvironment())->getTimeSource())->currentTimeMillis(), npc(pn)->getNodeId(), contactState);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE || (contactState != localContactState && npc(logger)->level <= ::rice::environment::logging::Logger::INFO)) {
        switch (contactState) {
        case RendezvousSocketNodeHandle::CONTACT_DIRECT:
            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(ret))->append(u" is not firewalled."_j)->toString());
            break;
        case RendezvousSocketNodeHandle::CONTACT_FIREWALLED:
            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(ret))->append(u" is firewalled."_j)->toString());
            break;
        }

    }
    return ret;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto baseTl = java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(super::getWireTransportLayer(innermostAddress, pn));
    auto p = npc(npc(pn)->getEnvironment())->getParameters();
    if((npc(npc(pn)->getVars())->containsKey(SIMULATE_FIREWALL_) && npc((java_cast< ::java::lang::Boolean* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(SIMULATE_FIREWALL_)))))->booleanValue()) || (npc(p)->contains(SIMULATE_FIREWALL_) && npc(p)->getBoolean(SIMULATE_FIREWALL_))) {
        return new ::org::mpisws::p2p::transport::nat::FirewallTLImpl(baseTl, int32_t(5000), npc(pn)->getEnvironment());
    }
    return baseTl;
}

org::mpisws::p2p::transport::priority::PriorityTransportLayer* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getPriorityTransportLayer(::org::mpisws::p2p::transport::TransportLayer* trans, ::org::mpisws::p2p::transport::liveness::LivenessProvider* liveness, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::rice::pastry::PastryNode* pn)
{
    auto ret = java_cast< ::org::mpisws::p2p::transport::priority::PriorityTransportLayer* >(super::getPriorityTransportLayer(trans, liveness, prox, pn));
    npc((java_cast< ::rice::pastry::standard::StandardRouter* >(npc(pn)->getRouter())))->setRouterStrategy(new RendezvousRouterStrategy(ret, npc(pn)->getEnvironment()));
    return ret;
}

rice::pastry::boot::Bootstrapper* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns)
{
    auto const manager = java_cast< ::org::mpisws::p2p::transport::rendezvous::PilotManager* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(RENDEZVOUS_TL_)));
    if(npc((java_cast< RendezvousSocketNodeHandle* >(npc(pn)->getLocalHandle())))->canContactDirect())
        return java_cast< ::rice::pastry::boot::Bootstrapper* >(super::getBootstrapper(pn, tl, handleFactory, pns));

    auto const booted = new ::boolArray(int32_t(1));
    (*booted)[int32_t(0)] = false;
    auto const closeMeWhenReady = new ::java::util::ArrayList();
    ::java::util::Observer* obs = new RendezvousSocketPastryNodeFactory_getBootstrapper_3(this, closeMeWhenReady, booted, manager);
    npc(pn)->addObserver(obs);
    ::rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper* bootstrapper = new RendezvousSocketPastryNodeFactory_getBootstrapper_4(this, manager, closeMeWhenReady, booted, pn, npc(tl)->getTL(), java_cast< ::rice::pastry::socket::SocketNodeHandleFactory* >(handleFactory), pns);
    return bootstrapper;
}

bool rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::isInternetRoutablePrefix(::java::net::InetAddress* address)
{
    auto ip = npc(address)->getHostAddress();
    auto nattedNetworkPrefixes = npc(npc(environment)->getParameters())->getString(u"nat_network_prefixes"_j);
    auto nattedNetworkPrefix = npc(nattedNetworkPrefixes)->split(u";"_j);
    for (auto i = int32_t(0); i < npc(nattedNetworkPrefix)->length; i++) {
        if(npc(ip)->startsWith((*nattedNetworkPrefix)[i])) {
            return false;
        }
    }
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousSocketPastryNodeFactory", 67);
    return c;
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::clinit()
{
struct string_init_ {
    string_init_() {
    RENDEZVOUS_STRATEGY_ = u"RendezvousSocketPastryNodeFactory.RENDEZVOUS_STRATEGY"_j;
    RENDEZVOUS_TL_ = u"RendezvousSocketPastryNodeFactory.RENDEZVOUS_TL"_j;
    SIMULATE_FIREWALL_ = u"rendezvous_simulate_firewall"_j;
    RENDEZVOUS_CONTACT_DIRECT_STRATEGY_ = u"RendezvousSocketPastryNodeFactory.ContactDirectStrategy"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars)
{
    super::newNodeSelector(nodeId, proxyAddress, deliverResultToMe, initialVars);
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory::getClass0()
{
    return class_();
}

