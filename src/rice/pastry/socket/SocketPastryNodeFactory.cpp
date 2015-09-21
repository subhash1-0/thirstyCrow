// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/StackOverflowError.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/net/BindException.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/ServerSocket.hpp>
#include <java/net/Socket.hpp>
#include <java/net/SocketException.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayer.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/identity/BindStrategy.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentitySerializer.hpp>
#include <org/mpisws/p2p/transport/identity/LowerIdentity.hpp>
#include <org/mpisws/p2p/transport/identity/UpperIdentity.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/liveness/OverrideLiveness.hpp>
#include <org/mpisws/p2p/transport/liveness/Pinger.hpp>
#include <org/mpisws/p2p/transport/multiaddress/AddressStrategy.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayer.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/multiaddress/SimpleAddressStrategy.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ProbeStrategy.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/proximity/MinRTTProximityProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteForwardStrategy.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayer.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/MultiAddressSourceRouteFactory.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteStrategy.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/NextHopStrategy.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/SimpleSourceRouteStrategy.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/CloneableLogManager.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/environment/processing/simple/SimpleProcessor.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/socket/LivenesSourceRouteForwardStrategy.hpp>
#include <rice/pastry/socket/SPNFIdentitySerializer.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getSocketCountListener_1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getIpServiceTransportLayer_2.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getIdentityImpl_3.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getIdentityImpl_4.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getLivenessTransportLayer_5.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getSourceRouteManagerLayer_6.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getUpperIdentityLayer_7.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getCommonAPITransportLayer_8.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getCommonAPITransportLayer_9.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getOptionsAdder_10.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_newNode_11.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLiveness.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLivenessProximity.hpp>
#include <rice/pastry/socket/nat/probe/ProbeApp.hpp>
#include <rice/pastry/transport/BogusNodeHandle.hpp>
#include <rice/pastry/transport/LeafSetNHStrategy.hpp>
#include <rice/pastry/transport/NodeHandleAdapter.hpp>
#include <rice/pastry/transport/TLDeserializer.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <Array.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
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

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
}
extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::socket::SocketPastryNodeFactory::SocketPastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::SocketPastryNodeFactory::SocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)  /* throws(IOException) */
    : SocketPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,startPort,env);
}

rice::pastry::socket::SocketPastryNodeFactory::SocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)  /* throws(IOException) */
    : SocketPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,bindAddress,startPort,env);
}

void rice::pastry::socket::SocketPastryNodeFactory::init()
{
    livenesSourceRouteForwardStrategy = new ::java::util::HashMap();
}

java::lang::String*& rice::pastry::socket::SocketPastryNodeFactory::PROXY_ADDRESS()
{
    clinit();
    return PROXY_ADDRESS_;
}
java::lang::String* rice::pastry::socket::SocketPastryNodeFactory::PROXY_ADDRESS_;

java::lang::String*& rice::pastry::socket::SocketPastryNodeFactory::IP_SERVICE()
{
    clinit();
    return IP_SERVICE_;
}
java::lang::String* rice::pastry::socket::SocketPastryNodeFactory::IP_SERVICE_;

java::lang::String*& rice::pastry::socket::SocketPastryNodeFactory::MULTI_INET_TL()
{
    clinit();
    return MULTI_INET_TL_;
}
java::lang::String* rice::pastry::socket::SocketPastryNodeFactory::MULTI_INET_TL_;

java::lang::String*& rice::pastry::socket::SocketPastryNodeFactory::PRIORITY_TL()
{
    clinit();
    return PRIORITY_TL_;
}
java::lang::String* rice::pastry::socket::SocketPastryNodeFactory::PRIORITY_TL_;

java::lang::String*& rice::pastry::socket::SocketPastryNodeFactory::MULTI_ADDRESS_STRATEGY()
{
    clinit();
    return MULTI_ADDRESS_STRATEGY_;
}
java::lang::String* rice::pastry::socket::SocketPastryNodeFactory::MULTI_ADDRESS_STRATEGY_;

int8_tArray*& rice::pastry::socket::SocketPastryNodeFactory::PASTRY_MAGIC_NUMBER()
{
    clinit();
    return PASTRY_MAGIC_NUMBER_;
}
int8_tArray* rice::pastry::socket::SocketPastryNodeFactory::PASTRY_MAGIC_NUMBER_;

void rice::pastry::socket::SocketPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */
{
    ctor(nf, nullptr, startPort, env);
}

void rice::pastry::socket::SocketPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
    init();
    environment = env;
    nidFactory = nf;
    port = startPort;
    auto params = npc(env)->getParameters();
    firewallSearchTries = npc(params)->getInt(u"nat_find_port_max_tries"_j);
    firewallAppName = npc(params)->getString(u"nat_app_name"_j);
    localAddress = bindAddress;
    if(localAddress == nullptr) {
        if(npc(params)->contains(u"socket_bindAddress"_j)) {
            localAddress = npc(params)->getInetAddress(u"socket_bindAddress"_j);
        }
    }
    if(localAddress == nullptr) {
        localAddress = ::java::net::InetAddress::getLocalHost();
        ::java::net::Socket* temp = nullptr;
        ::java::net::ServerSocket* test2 = nullptr;
        if(npc(localAddress)->isLoopbackAddress() && !npc(params)->getBoolean(u"pastry_socket_allow_loopback"_j)) {
            {
                auto finally0 = finally([&] {
                    try {
                        if(test2 != nullptr)
                            npc(test2)->close();

                    } catch (::java::lang::Exception* e) {
                    }
                    try {
                        if(temp != nullptr)
                            npc(temp)->close();

                    } catch (::java::lang::Exception* e) {
                    }
                });
                {
                    temp = new ::java::net::Socket(npc(params)->getString(u"pastry_socket_known_network_address"_j), npc(params)->getInt(u"pastry_socket_known_network_address_port"_j));
                    if(npc(npc(temp)->getLocalAddress())->equals(static_cast< ::java::lang::Object* >(localAddress)))
                        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Cannot bind to "_j)->append(static_cast< ::java::lang::Object* >(localAddress))
                            ->append(u":"_j)
                            ->append(port)->toString());

                    localAddress = npc(temp)->getLocalAddress();
                    npc(temp)->close();
                    temp = nullptr;
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Error binding to default IP, using "_j)->append(static_cast< ::java::lang::Object* >(localAddress))
                            ->append(u":"_j)
                            ->append(port)->toString());

                    try {
                        test2 = new ::java::net::ServerSocket();
                        npc(test2)->bind(new ::java::net::InetSocketAddress(localAddress, port));
                    } catch (::java::net::SocketException* e2) {
                        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Cannot bind to "_j)->append(static_cast< ::java::lang::Object* >(localAddress))
                            ->append(u":"_j)
                            ->append(port)->toString(), e2);
                    }
                }
            }

        }
    }
}

java::net::InetAddress* rice::pastry::socket::SocketPastryNodeFactory::getBindAddress()
{
    return localAddress;
}

java::net::InetSocketAddress* rice::pastry::socket::SocketPastryNodeFactory::getNextInetSocketAddress()
{
    return new ::java::net::InetSocketAddress(localAddress, port);
}

void rice::pastry::socket::SocketPastryNodeFactory::registerApps(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::transport::NodeHandleAdapter* nha, ::rice::pastry::NodeHandleFactory* handleFactory)
{
    super::registerApps(pn, leafSet, routeTable, nha, handleFactory);
    auto probeStrategy = getProbeStrategy(pn);
}

org::mpisws::p2p::transport::networkinfo::ProbeStrategy* rice::pastry::socket::SocketPastryNodeFactory::getProbeStrategy(::rice::pastry::PastryNode* pn)
{
    auto ipService = java_cast< ::org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(IP_SERVICE_)));
    auto tl = java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayer* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(MULTI_INET_TL_)));
    auto probeApp = new ::rice::pastry::socket::nat::probe::ProbeApp(pn, ipService, npc(tl)->getAddressStrategy());
    npc(probeApp)->register_();
    npc(ipService)->setProbeStrategy(probeApp);
    return probeApp;
}

rice::pastry::NodeHandle* rice::pastry::socket::SocketPastryNodeFactory::getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf)
{
    auto pnhf = java_cast< SocketNodeHandleFactory* >(nhf);
    auto proxyAddress = java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(PROXY_ADDRESS_)));
    return npc(pnhf)->getNodeHandle(proxyAddress, npc(npc(npc(pn)->getEnvironment())->getTimeSource())->currentTimeMillis(), npc(pn)->getNodeId());
}

java::lang::String*& rice::pastry::socket::SocketPastryNodeFactory::NODE_HANDLE_FACTORY()
{
    clinit();
    return NODE_HANDLE_FACTORY_;
}
java::lang::String* rice::pastry::socket::SocketPastryNodeFactory::NODE_HANDLE_FACTORY_;

rice::pastry::NodeHandleFactory* rice::pastry::socket::SocketPastryNodeFactory::getNodeHandleFactory(::rice::pastry::PastryNode* pn)
{
    if(npc(npc(pn)->getVars())->containsKey(NODE_HANDLE_FACTORY_)) {
        return java_cast< ::rice::pastry::NodeHandleFactory* >(java_cast< ::java::lang::Object* >(npc(npc(pn)->getVars())->get(NODE_HANDLE_FACTORY_)));
    }
    ::rice::pastry::NodeHandleFactory* ret = new SocketNodeHandleFactory(pn);
    npc(npc(pn)->getVars())->put(NODE_HANDLE_FACTORY_, ret);
    return ret;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getBottomLayers(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress) /* throws(IOException) */
{
    auto wtl = getWireTransportLayer(npc(proxyAddress)->getInnermostAddress(), pn);
    auto mntl = getMagicNumberTransportLayer(wtl, pn);
    auto lstl = getLimitSocketsTransportLayer(mntl, pn);
    auto iptl = getIpServiceTransportLayer(lstl, pn);
    return iptl;
}

rice::pastry::transport::NodeHandleAdapter* rice::pastry::socket::SocketPastryNodeFactory::getNodeHandleAdapter(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory2, ::rice::pastry::transport::TLDeserializer* deserializer) /* throws(IOException) */
{
    auto environment = npc(pn)->getEnvironment();
    auto localhandle = java_cast< SocketNodeHandle* >(npc(pn)->getLocalHandle());
    auto const handleFactory = java_cast< SocketNodeHandleFactory* >(handleFactory2);
    auto proxyAddress = npc(localhandle)->eaddress;
    auto esrFactory = getMultiAddressSourceRouteFactory(pn);
    auto iptl = getBottomLayers(pn, proxyAddress);
    auto etl = getMultiAddressSourceRouteTransportLayer(iptl, pn, proxyAddress);
    npc(npc(pn)->getVars())->put(MULTI_INET_TL_, etl);
    auto srl = getSourceRouteTransportLayer(etl, pn, esrFactory);
    auto identity = getIdentityImpl(pn, handleFactory);
    auto lowerIdentityLayer = getLowerIdentityLayer(srl, pn, identity);
    auto ltl = getLivenessTransportLayer(lowerIdentityLayer, pn);
    notifyLivenessTransportLayerConstructed(pn, ltl);
    auto srm = getSourceRouteManagerLayer(npc(ltl)->getTransportLayer(), npc(ltl)->getLivenessProvider(), npc(ltl)->getPinger(), pn, proxyAddress, esrFactory);
    auto priorityTL = getPriorityTransportLayer(npc(srm)->getTransportLayer(), npc(srm)->getLivenessProvider(), npc(srm)->getProximityProvider(), pn);
    auto upperIdentityLayer = getUpperIdentityLayer(priorityTL, pn, identity, npc(srm)->getLivenessProvider(), npc(srm)->getProximityProvider(), npc(ltl)->getOverrideLiveness());
    auto commonAPItl = getCommonAPITransportLayer(npc(upperIdentityLayer)->getTransportLayer(), pn, deserializer);
    auto nha = new ::rice::pastry::transport::NodeHandleAdapter(commonAPItl, npc(upperIdentityLayer)->getLivenessProvider(), npc(upperIdentityLayer)->getProximityProvider());
    return nha;
}

org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* rice::pastry::socket::SocketPastryNodeFactory::getMultiAddressSourceRouteFactory(::rice::pastry::PastryNode* pn)
{
    return new ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory();
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto environment = npc(pn)->getEnvironment();
    auto wtl = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(innermostAddress, environment, nullptr);
    npc(wtl)->addSocketCountListener(getSocketCountListener(pn));
    return wtl;
}

org::mpisws::p2p::transport::SocketCountListener* rice::pastry::socket::SocketPastryNodeFactory::getSocketCountListener(::rice::pastry::PastryNode* pn)
{
    return new SocketPastryNodeFactory_getSocketCountListener_1(this, pn);
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getMagicNumberTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::pastry::PastryNode* pn)
{
    auto environment = npc(pn)->getEnvironment();
    auto mntl = new ::org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer(wtl, environment, nullptr, PASTRY_MAGIC_NUMBER_, int32_t(5000));
    return mntl;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getLimitSocketsTransportLayer(::org::mpisws::p2p::transport::TransportLayer* mntl, ::rice::pastry::PastryNode* pn)
{
    auto environment = npc(pn)->getEnvironment();
    auto lstl = new ::org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer(npc(npc(environment)->getParameters())->getInt(u"pastry_socket_scm_max_open_sockets"_j), mntl, nullptr, environment);
    return lstl;
}

constexpr int8_t rice::pastry::socket::SocketPastryNodeFactory::NETWORK_INFO_NODE_HANDLE_INDEX;

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getIpServiceTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto environment = npc(pn)->getEnvironment();
    auto const ipTL = new ::org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer(wtl, environment, nullptr);
    npc(npc(pn)->getVars())->put(IP_SERVICE_, ipTL);
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    npc(npc(pn)->getLocalHandle())->serialize(static_cast< ::rice::p2p::commonapi::rawserialization::OutputBuffer* >(sob));
    npc(ipTL)->setId(NETWORK_INFO_NODE_HANDLE_INDEX, npc(sob)->getBytes());
    npc(pn)->setNodeHandleFetcher(new SocketPastryNodeFactory_getIpServiceTransportLayer_2(this, ipTL, pn));
    return ipTL;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getMultiAddressSourceRouteTransportLayer(::org::mpisws::p2p::transport::TransportLayer* mntl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* localAddress)
{
    ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* adrStrat = new ::org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy();
    npc(npc(pn)->getVars())->put(MULTI_ADDRESS_STRATEGY_, adrStrat);
    return new ::org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl(localAddress, mntl, npc(pn)->getEnvironment(), nullptr, adrStrat);
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getSourceRouteTransportLayer(::org::mpisws::p2p::transport::TransportLayer* etl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory)
{
    auto environment = npc(pn)->getEnvironment();
    ::org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer* srl = new ::org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl(esrFactory, etl, getSourceRouteForwardStrategy(pn, esrFactory), environment, nullptr);
    return srl;
}

org::mpisws::p2p::transport::sourceroute::SourceRouteForwardStrategy* rice::pastry::socket::SocketPastryNodeFactory::getSourceRouteForwardStrategy(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory)
{
    auto ret = new LivenesSourceRouteForwardStrategy(esrFactory, npc(pn)->getEnvironment());
    npc(livenesSourceRouteForwardStrategy)->put(pn, ret);
    return ret;
}

void rice::pastry::socket::SocketPastryNodeFactory::notifyLivenessTransportLayerConstructed(::rice::pastry::PastryNode* pn, SocketPastryNodeFactory_TransLiveness* ltl)
{
    auto srFs = java_cast< LivenesSourceRouteForwardStrategy* >(npc(livenesSourceRouteForwardStrategy)->remove(pn));
    if(srFs != nullptr) {
        npc(srFs)->setLivenessProvider(npc(ltl)->getLivenessProvider());
    }
}

org::mpisws::p2p::transport::identity::IdentitySerializer* rice::pastry::socket::SocketPastryNodeFactory::getIdentiySerializer(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* handleFactory)
{
    return new SPNFIdentitySerializer(pn, handleFactory);
}

org::mpisws::p2p::transport::identity::IdentityImpl* rice::pastry::socket::SocketPastryNodeFactory::getIdentityImpl(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* handleFactory) /* throws(IOException) */
{
    auto environment = npc(pn)->getEnvironment();
    auto localhandle = java_cast< SocketNodeHandle* >(npc(pn)->getLocalHandle());
    auto serializer = getIdentiySerializer(pn, handleFactory);
    auto buf = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    npc(serializer)->serialize(buf, localhandle);
    auto localHandleBytes = new ::int8_tArray(npc(buf)->getWritten());
    ::java::lang::System::arraycopy(npc(buf)->getBytes(), 0, localHandleBytes, 0, npc(localHandleBytes)->length);
    auto const identity = new ::org::mpisws::p2p::transport::identity::IdentityImpl(localHandleBytes, serializer, new SocketPastryNodeFactory_getIdentityImpl_3(this), new SocketPastryNodeFactory_getIdentityImpl_4(this), getBindStrategy(), environment);
    return identity;
}

org::mpisws::p2p::transport::identity::BindStrategy* rice::pastry::socket::SocketPastryNodeFactory::getBindStrategy()
{
    return nullptr;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getLowerIdentityLayer(::org::mpisws::p2p::transport::TransportLayer* srl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::identity::IdentityImpl* identity)
{
    npc(identity)->initLowerLayer(srl, nullptr);
    auto lowerIdentityLayer = npc(identity)->getLowerIdentity();
    return lowerIdentityLayer;
}

rice::pastry::socket::SocketPastryNodeFactory_TransLiveness* rice::pastry::socket::SocketPastryNodeFactory::getLivenessTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::pastry::PastryNode* pn)
{
    auto environment = npc(pn)->getEnvironment();
    auto checkDeadThrottle = npc(npc(environment)->getParameters())->getInt(u"pastry_socket_srm_check_dead_throttle"_j);
    auto const ltl = new ::org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl(tl, environment, nullptr, checkDeadThrottle);
    return new SocketPastryNodeFactory_getLivenessTransportLayer_5(this, ltl);
}

rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity* rice::pastry::socket::SocketPastryNodeFactory::getSourceRouteManagerLayer(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */
{
    auto environment = npc(pn)->getEnvironment();
    auto srStrategy = getSourceRouteStrategy(ltl, livenessProvider, pinger, pn, proxyAddress, esrFactory);
    auto prox = new ::org::mpisws::p2p::transport::proximity::MinRTTProximityProvider(pinger, environment);
    ::org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManager* const srm = new ::org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl(esrFactory, ltl, livenessProvider, prox, environment, srStrategy);
    return new SocketPastryNodeFactory_getSourceRouteManagerLayer_6(this, srm);
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteStrategy* rice::pastry::socket::SocketPastryNodeFactory::getSourceRouteStrategy(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */
{
    auto nhStrategy = getNextHopStrategy(ltl, livenessProvider, pinger, pn, proxyAddress, esrFactory);
    return new ::org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy(proxyAddress, esrFactory, nhStrategy, environment);
}

org::mpisws::p2p::transport::sourceroute::manager::simple::NextHopStrategy* rice::pastry::socket::SocketPastryNodeFactory::getNextHopStrategy(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */
{
    return new ::rice::pastry::transport::LeafSetNHStrategy(npc(pn)->getLeafSet());
}

org::mpisws::p2p::transport::priority::PriorityTransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getPriorityTransportLayer(::org::mpisws::p2p::transport::TransportLayer* trans, ::org::mpisws::p2p::transport::liveness::LivenessProvider* liveness, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::rice::pastry::PastryNode* pn)
{
    auto environment = npc(pn)->getEnvironment();
    ::org::mpisws::p2p::transport::priority::PriorityTransportLayer* priorityTL = new ::org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl(trans, liveness, prox, environment, npc(npc(environment)->getParameters())->getInt(u"pastry_socket_writer_max_msg_size"_j), npc(npc(environment)->getParameters())->getInt(u"pastry_socket_writer_max_queue_length"_j), nullptr);
    npc(npc(pn)->getVars())->put(PRIORITY_TL_, priorityTL);
    return priorityTL;
}

rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity* rice::pastry::socket::SocketPastryNodeFactory::getUpperIdentityLayer(::org::mpisws::p2p::transport::TransportLayer* priorityTL, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::identity::IdentityImpl* identity, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::org::mpisws::p2p::transport::liveness::OverrideLiveness* overrideLiveness)
{
    auto localhandle = java_cast< SocketNodeHandle* >(npc(pn)->getLocalHandle());
    npc(identity)->initUpperLayer(localhandle, priorityTL, live, prox, overrideLiveness);
    auto const upperIdentityLayer = npc(identity)->getUpperIdentity();
    return new SocketPastryNodeFactory_getUpperIdentityLayer_7(this, upperIdentityLayer);
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::SocketPastryNodeFactory::getCommonAPITransportLayer(::org::mpisws::p2p::transport::TransportLayer* upperIdentity, ::rice::pastry::PastryNode* pn, ::rice::pastry::transport::TLDeserializer* deserializer)
{
    auto const environment = npc(pn)->getEnvironment();
    ::org::mpisws::p2p::transport::commonapi::IdFactory* idFactory = new SocketPastryNodeFactory_getCommonAPITransportLayer_8(this);
    ::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayer* commonAPItl = new ::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl(upperIdentity, idFactory, deserializer, getOptionsAdder(pn), new SocketPastryNodeFactory_getCommonAPITransportLayer_9(this, environment), environment);
    return commonAPItl;
}

org::mpisws::p2p::transport::commonapi::OptionsAdder* rice::pastry::socket::SocketPastryNodeFactory::getOptionsAdder(::rice::pastry::PastryNode* pn)
{
    auto foo = npc(npc(pn)->getId())->toByteArray_();
    return new SocketPastryNodeFactory_getOptionsAdder_10(this);
}

rice::pastry::boot::Bootstrapper* rice::pastry::socket::SocketPastryNodeFactory::getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns)
{
    auto bootstrapper = new SocketPastryNodeFactory_TLBootstrapper(this, pn, npc(tl)->getTL(), java_cast< SocketNodeHandleFactory* >(handleFactory), pns);
    return bootstrapper;
}

rice::pastry::NodeHandle* rice::pastry::socket::SocketPastryNodeFactory::getNodeHandle(::java::net::InetSocketAddress* bootstrap, int32_t i)
{
    return getNodeHandle(bootstrap);
}

rice::pastry::NodeHandle* rice::pastry::socket::SocketPastryNodeFactory::getNodeHandle(::java::net::InetSocketAddress* bootstrap)
{
    return new ::rice::pastry::transport::BogusNodeHandle(bootstrap);
}

void rice::pastry::socket::SocketPastryNodeFactory::getNodeHandle(::java::net::InetSocketAddressArray* bootstraps, ::rice::Continuation* c)
{
    npc(c)->receiveResult(getNodeHandle(bootstraps, int32_t(0)));
}

rice::pastry::NodeHandle* rice::pastry::socket::SocketPastryNodeFactory::getNodeHandle(::java::net::InetSocketAddressArray* bootstraps, int32_t int1)
{
    return new ::rice::pastry::transport::BogusNodeHandle(bootstraps);
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::rice::pastry::NodeHandle* bootstrap)
{
    return newNode(bootstrap, npc(nidFactory)->generateNodeId());
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::rice::pastry::NodeHandle* bootstrap, ::java::net::InetSocketAddress* proxy)
{
    return newNode(bootstrap, npc(nidFactory)->generateNodeId(), proxy);
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::rice::pastry::NodeHandle* bootstrap, ::rice::pastry::Id* nodeId)
{
    return newNode(bootstrap, nodeId, nullptr);
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode()
{
    return newNode(npc(nidFactory)->generateNodeId(), static_cast< ::java::net::InetSocketAddress* >(nullptr));
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::rice::pastry::Id* id)
{
    return newNode(id, static_cast< ::java::net::InetSocketAddress* >(nullptr));
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::java::net::InetSocketAddress* proxyAddress)
{
    return newNode(npc(nidFactory)->generateNodeId(), proxyAddress);
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::rice::pastry::NodeHandle* nodeHandle, ::rice::pastry::Id* id, ::java::net::InetSocketAddress* proxyAddress)
{
    auto n = newNode(id, proxyAddress);
    if(nodeHandle == nullptr) {
        npc(npc(n)->getBootstrapper())->boot(nullptr);
    } else {
        auto bnh = java_cast< ::rice::pastry::transport::BogusNodeHandle* >(nodeHandle);
        npc(npc(n)->getBootstrapper())->boot(npc(bnh)->addresses);
    }
    return n;
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* pAddress)
{
    if(pAddress == nullptr) {
        if(npc(npc(environment)->getParameters())->contains(u"external_address"_j)) {
            try {
                pAddress = npc(npc(environment)->getParameters())->getInetSocketAddress(u"external_address"_j);
            } catch (::java::io::IOException* ioe) {
                npc(ioe)->printStackTrace();
            }
        }
    }
    try {
        ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* multiAddress;
        if(pAddress == nullptr) {
            multiAddress = new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(new ::java::net::InetSocketAddress(localAddress, port));
        } else {
            multiAddress = new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(pAddress, new ::java::net::InetSocketAddress(localAddress, port));
        }
        auto ret = newNode(nodeId, multiAddress);
        if(npc(npc(environment)->getParameters())->getBoolean(u"pastry_socket_increment_port_after_construction"_j)) {
            port++;
        }
        return ret;
    } catch (::java::net::BindException* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Warning: "_j, e);

        if(npc(npc(environment)->getParameters())->getBoolean(u"pastry_socket_increment_port_after_construction"_j)) {
            port++;
            try {
                return newNode(nodeId, pAddress);
            } catch (::java::lang::StackOverflowError* soe) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"SEVERE: SocketPastryNodeFactory: Could not bind on any ports!"_j)->append(static_cast< ::java::lang::Object* >(soe))->toString());

                throw soe;
            }
        } else {
            if(npc(npc(this->environment)->getParameters())->getBoolean(u"pastry_factory_multipleNodes"_j)) {
                npc(environment)->destroy();
            }
            throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
        }
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

rice::pastry::PastryNode* rice::pastry::socket::SocketPastryNodeFactory::newNode(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* pAddress) /* throws(IOException) */
{
    auto const pn = new ::java::util::ArrayList(int32_t(1));
    auto const re = new ::java::util::ArrayList(int32_t(1));
    ::java::lang::Runnable* r = new SocketPastryNodeFactory_newNode_11(this, pn, nodeId, pAddress, re);
    if(npc(npc(environment)->getSelectorManager())->isSelectorThread()) {
        npc(r)->run();
    } else {
        npc(npc(environment)->getSelectorManager())->invoke(r);
    }
    {
        synchronized synchronized_0(pn);
        {
            if(npc(pn)->isEmpty() && npc(re)->isEmpty()) {
                try {
                    npc(pn)->wait();
                } catch (::java::lang::InterruptedException* ie) {
                    throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ie));
                }
            }
        }
    }
    if(npc(pn)->isEmpty()) {
        throw java_cast< ::java::io::IOException* >(npc(re)->get(int32_t(0)));
    }
    return java_cast< ::rice::pastry::PastryNode* >(npc(pn)->get(int32_t(0)));
}

void rice::pastry::socket::SocketPastryNodeFactory::newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars)
{
    try {
        auto environment = cloneEnvironment(this->environment, nodeId);
        auto params = npc(environment)->getParameters();
        auto pn = new ::rice::pastry::PastryNode(nodeId, environment);
        if(initialVars != nullptr)
            npc(npc(pn)->getVars())->putAll(initialVars);

        npc(npc(pn)->getVars())->put(PROXY_ADDRESS_, proxyAddress);
        nodeHandleHelper(pn);
        npc(deliverResultToMe)->receiveResult(pn);
    } catch (::java::io::IOException* ioe) {
        npc(deliverResultToMe)->receiveException(ioe);
    }
}

rice::environment::Environment* rice::pastry::socket::SocketPastryNodeFactory::cloneEnvironment(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId)
{
    auto ret = rootEnvironment;
    if(npc(npc(rootEnvironment)->getParameters())->getBoolean(u"pastry_factory_multipleNodes"_j)) {
        auto lman = cloneLogManager(rootEnvironment, nodeId);
        auto sman = cloneSelectorManager(rootEnvironment, nodeId, lman);
        auto proc = cloneProcessor(rootEnvironment, nodeId, lman);
        auto rand = cloneRandomSource(rootEnvironment, nodeId, lman);
        ret = new ::rice::environment::Environment(sman, proc, rand, npc(rootEnvironment)->getTimeSource(), lman, npc(rootEnvironment)->getParameters(), npc(rootEnvironment)->getExceptionStrategy());
        npc(rootEnvironment)->addDestructable(ret);
    }
    return ret;
}

rice::environment::logging::LogManager* rice::pastry::socket::SocketPastryNodeFactory::cloneLogManager(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId)
{
    auto lman = npc(rootEnvironment)->getLogManager();
    if(dynamic_cast< ::rice::environment::logging::CloneableLogManager* >(lman) != nullptr) {
        lman = npc((java_cast< ::rice::environment::logging::CloneableLogManager* >(npc(rootEnvironment)->getLogManager())))->clone(::java::lang::StringBuilder().append(u"0x"_j)->append(npc(nodeId)->toStringBare())->toString());
    }
    return lman;
}

rice::selector::SelectorManager* rice::pastry::socket::SocketPastryNodeFactory::cloneSelectorManager(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman)
{
    auto sman = npc(rootEnvironment)->getSelectorManager();
    if(npc(npc(rootEnvironment)->getParameters())->getBoolean(u"pastry_factory_selectorPerNode"_j)) {
        sman = new ::rice::selector::SelectorManager(::java::lang::StringBuilder().append(npc(nodeId)->toString())->append(u" Selector"_j)->toString(), npc(rootEnvironment)->getTimeSource(), lman, npc(rootEnvironment)->getRandomSource());
    }
    return sman;
}

rice::environment::processing::Processor* rice::pastry::socket::SocketPastryNodeFactory::cloneProcessor(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman)
{
    auto proc = npc(rootEnvironment)->getProcessor();
    if(npc(npc(rootEnvironment)->getParameters())->getBoolean(u"pastry_factory_processorPerNode"_j)) {
        proc = new ::rice::environment::processing::simple::SimpleProcessor(::java::lang::StringBuilder().append(npc(nodeId)->toString())->append(u" Processor"_j)->toString());
    }
    return proc;
}

rice::environment::random::RandomSource* rice::pastry::socket::SocketPastryNodeFactory::cloneRandomSource(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman)
{
    auto randSeed = npc(npc(rootEnvironment)->getRandomSource())->nextLong();
    return new ::rice::environment::random::simple::SimpleRandomSource(randSeed, lman);
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* rice::pastry::socket::SocketPastryNodeFactory::getEpochAddress(int32_t portNumber)
{
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* result = nullptr;
    result = new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(new ::java::net::InetSocketAddress(localAddress, portNumber));
    return result;
}

java::net::InetSocketAddress* rice::pastry::socket::SocketPastryNodeFactory::verifyConnection(int32_t i, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddressArray* addr2, ::rice::environment::Environment* env, ::rice::environment::logging::Logger* l)
{
    clinit();
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.SocketPastryNodeFactory", 42);
    return c;
}

void rice::pastry::socket::SocketPastryNodeFactory::clinit()
{
struct string_init_ {
    string_init_() {
    PROXY_ADDRESS_ = u"SocketPastryNodeFactory.proxyAddress"_j;
    IP_SERVICE_ = u"SocketPastryNodeFactory.ip-service"_j;
    MULTI_INET_TL_ = u"SocketPastryNodeFactory.milti-inet-tl"_j;
    PRIORITY_TL_ = u"PriorityTransportLayer.PRIORITY_TL"_j;
    MULTI_ADDRESS_STRATEGY_ = u"SocketPastryNodeFactory.milti-inet-addressStrategy"_j;
    NODE_HANDLE_FACTORY_ = u"SocketPastryNodeFactory.NODE_HANDLE_FACTORY"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        PASTRY_MAGIC_NUMBER_ = new ::int8_tArray({
            static_cast< int8_t >(int32_t(39))
            , static_cast< int8_t >(int32_t(64))
            , static_cast< int8_t >(int32_t(117))
            , static_cast< int8_t >(int32_t(58))
        });
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory::getClass0()
{
    return class_();
}

