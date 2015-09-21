// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/commonapi/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/TransportPastryNodeFactory.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::InetAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > InetAddressArray;
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

struct default_init_tag;

class rice::pastry::socket::SocketPastryNodeFactory
    : public ::rice::pastry::transport::TransportPastryNodeFactory
{

public:
    typedef ::rice::pastry::transport::TransportPastryNodeFactory super;

private:
    static ::java::lang::String* PROXY_ADDRESS_;
    static ::java::lang::String* IP_SERVICE_;
    static ::java::lang::String* MULTI_INET_TL_;
    static ::java::lang::String* PRIORITY_TL_;
    static ::java::lang::String* MULTI_ADDRESS_STRATEGY_;
    static ::int8_tArray* PASTRY_MAGIC_NUMBER_;
    int32_t port {  };

public: /* protected */
    ::rice::pastry::NodeIdFactory* nidFactory {  };
    ::java::net::InetAddress* localAddress {  };

public: /* package */
    ::java::net::InetAddressArray* addressList {  };

public: /* protected */
    int32_t testFireWallPolicy {  };
    int32_t findFireWallPolicy {  };

public: /* package */
    ::java::lang::String* firewallAppName {  };
    int32_t firewallSearchTries {  };
protected:
    void ctor(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */;
    void ctor(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */;

public:
    virtual ::java::net::InetAddress* getBindAddress();
    virtual ::java::net::InetSocketAddress* getNextInetSocketAddress();

public: /* protected */
    void registerApps(::rice::pastry::PastryNode* pn, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::pastry::routing::RoutingTable* routeTable, ::rice::pastry::transport::NodeHandleAdapter* nha, ::rice::pastry::NodeHandleFactory* handleFactory) override;
    virtual ::org::mpisws::p2p::transport::networkinfo::ProbeStrategy* getProbeStrategy(::rice::pastry::PastryNode* pn);

public:
    ::rice::pastry::NodeHandle* getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf) override;

private:
    static ::java::lang::String* NODE_HANDLE_FACTORY_;

public:
    ::rice::pastry::NodeHandleFactory* getNodeHandleFactory(::rice::pastry::PastryNode* pn) override;
    virtual ::org::mpisws::p2p::transport::TransportLayer* getBottomLayers(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress) /* throws(IOException) */;
    ::rice::pastry::transport::NodeHandleAdapter* getNodeHandleAdapter(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory2, ::rice::pastry::transport::TLDeserializer* deserializer) /* throws(IOException) */ override;

public: /* protected */
    virtual ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* getMultiAddressSourceRouteFactory(::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::SocketCountListener* getSocketCountListener(::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::TransportLayer* getMagicNumberTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::TransportLayer* getLimitSocketsTransportLayer(::org::mpisws::p2p::transport::TransportLayer* mntl, ::rice::pastry::PastryNode* pn);

public:
    static constexpr int8_t NETWORK_INFO_NODE_HANDLE_INDEX { int8_t(1) };

public: /* protected */
    virtual ::org::mpisws::p2p::transport::TransportLayer* getIpServiceTransportLayer(::org::mpisws::p2p::transport::TransportLayer* wtl, ::rice::pastry::PastryNode* pn) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::TransportLayer* getMultiAddressSourceRouteTransportLayer(::org::mpisws::p2p::transport::TransportLayer* mntl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* localAddress);
    virtual ::org::mpisws::p2p::transport::TransportLayer* getSourceRouteTransportLayer(::org::mpisws::p2p::transport::TransportLayer* etl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory);

public: /* package */
    ::java::util::Map* livenesSourceRouteForwardStrategy {  };

public: /* protected */
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRouteForwardStrategy* getSourceRouteForwardStrategy(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory);

private:
    void notifyLivenessTransportLayerConstructed(::rice::pastry::PastryNode* pn, SocketPastryNodeFactory_TransLiveness* ltl);

public: /* protected */
    virtual ::org::mpisws::p2p::transport::identity::IdentitySerializer* getIdentiySerializer(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* handleFactory);
    virtual ::org::mpisws::p2p::transport::identity::IdentityImpl* getIdentityImpl(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* handleFactory) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::identity::BindStrategy* getBindStrategy();
    virtual ::org::mpisws::p2p::transport::TransportLayer* getLowerIdentityLayer(::org::mpisws::p2p::transport::TransportLayer* srl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::identity::IdentityImpl* identity);
    virtual SocketPastryNodeFactory_TransLiveness* getLivenessTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::pastry::PastryNode* pn);
    virtual SocketPastryNodeFactory_TransLivenessProximity* getSourceRouteManagerLayer(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::sourceroute::manager::SourceRouteStrategy* getSourceRouteStrategy(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::sourceroute::manager::simple::NextHopStrategy* getNextHopStrategy(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::priority::PriorityTransportLayer* getPriorityTransportLayer(::org::mpisws::p2p::transport::TransportLayer* trans, ::org::mpisws::p2p::transport::liveness::LivenessProvider* liveness, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::rice::pastry::PastryNode* pn);
    virtual SocketPastryNodeFactory_TransLivenessProximity* getUpperIdentityLayer(::org::mpisws::p2p::transport::TransportLayer* priorityTL, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::identity::IdentityImpl* identity, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::org::mpisws::p2p::transport::liveness::OverrideLiveness* overrideLiveness);
    virtual ::org::mpisws::p2p::transport::TransportLayer* getCommonAPITransportLayer(::org::mpisws::p2p::transport::TransportLayer* upperIdentity, ::rice::pastry::PastryNode* pn, ::rice::pastry::transport::TLDeserializer* deserializer);
    virtual ::org::mpisws::p2p::transport::commonapi::OptionsAdder* getOptionsAdder(::rice::pastry::PastryNode* pn);
    ::rice::pastry::boot::Bootstrapper* getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns) override;

public:
    virtual ::rice::pastry::NodeHandle* getNodeHandle(::java::net::InetSocketAddress* bootstrap, int32_t i);
    virtual ::rice::pastry::NodeHandle* getNodeHandle(::java::net::InetSocketAddress* bootstrap);
    virtual void getNodeHandle(::java::net::InetSocketAddressArray* bootstraps, ::rice::Continuation* c);
    virtual ::rice::pastry::NodeHandle* getNodeHandle(::java::net::InetSocketAddressArray* bootstraps, int32_t int1);
    ::rice::pastry::PastryNode* newNode(::rice::pastry::NodeHandle* bootstrap) override;
    virtual ::rice::pastry::PastryNode* newNode(::rice::pastry::NodeHandle* bootstrap, ::java::net::InetSocketAddress* proxy);
    ::rice::pastry::PastryNode* newNode(::rice::pastry::NodeHandle* bootstrap, ::rice::pastry::Id* nodeId) override;
    ::rice::pastry::PastryNode* newNode() override;
    ::rice::pastry::PastryNode* newNode(::rice::pastry::Id* id) override;
    virtual ::rice::pastry::PastryNode* newNode(::java::net::InetSocketAddress* proxyAddress);
    virtual ::rice::pastry::PastryNode* newNode(::rice::pastry::NodeHandle* nodeHandle, ::rice::pastry::Id* id, ::java::net::InetSocketAddress* proxyAddress);
    virtual ::rice::pastry::PastryNode* newNode(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* pAddress);
    virtual ::rice::pastry::PastryNode* newNode(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* pAddress) /* throws(IOException) */;

public: /* protected */
    virtual void newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars);
    virtual ::rice::environment::Environment* cloneEnvironment(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId);
    virtual ::rice::environment::logging::LogManager* cloneLogManager(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId);
    virtual ::rice::selector::SelectorManager* cloneSelectorManager(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman);
    virtual ::rice::environment::processing::Processor* cloneProcessor(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman);
    virtual ::rice::environment::random::RandomSource* cloneRandomSource(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman);

private:
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* getEpochAddress(int32_t portNumber);

public:
    static ::java::net::InetSocketAddress* verifyConnection(int32_t i, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddressArray* addr2, ::rice::environment::Environment* env, ::rice::environment::logging::Logger* l);

    // Generated
    SocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    SocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env);
protected:
    SocketPastryNodeFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::java::lang::String*& PROXY_ADDRESS();
    static ::java::lang::String*& IP_SERVICE();
    static ::java::lang::String*& MULTI_INET_TL();
    static ::java::lang::String*& PRIORITY_TL();
    static ::java::lang::String*& MULTI_ADDRESS_STRATEGY();
    static ::int8_tArray*& PASTRY_MAGIC_NUMBER();
    static ::java::lang::String*& NODE_HANDLE_FACTORY();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SocketPastryNodeFactory_TransLiveness;
    friend class SocketPastryNodeFactory_TransLivenessProximity;
    friend class SocketPastryNodeFactory_getSocketCountListener_1;
    friend class SocketPastryNodeFactory_getIpServiceTransportLayer_2;
    friend class SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1;
    friend class SocketPastryNodeFactory_getIdentityImpl_3;
    friend class SocketPastryNodeFactory_getIdentityImpl_4;
    friend class SocketPastryNodeFactory_getLivenessTransportLayer_5;
    friend class SocketPastryNodeFactory_getSourceRouteManagerLayer_6;
    friend class SocketPastryNodeFactory_getUpperIdentityLayer_7;
    friend class SocketPastryNodeFactory_getCommonAPITransportLayer_8;
    friend class SocketPastryNodeFactory_getCommonAPITransportLayer_9;
    friend class SocketPastryNodeFactory_getOptionsAdder_10;
    friend class SocketPastryNodeFactory_TLBootstrapper;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_1;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_2;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_3;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_4;
    friend class SocketPastryNodeFactory_newNode_11;
    friend class SocketPastryNodeFactory_newNode_11_run_11_1;
};
