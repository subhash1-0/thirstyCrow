// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/internet/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>

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
    } // net
} // java

struct default_init_tag;

class rice::pastry::socket::internet::InternetPastryNodeFactory
    : public ::rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory super;
    static constexpr int32_t ALWAYS { int32_t(1) };
    static constexpr int32_t PREFIX_MATCH { int32_t(2) };
    static constexpr int32_t NEVER { int32_t(3) };
    static constexpr int32_t BOOT { int32_t(4) };
    static constexpr int32_t OVERWRITE { int32_t(1) };
    static constexpr int32_t USE_DIFFERENT_PORT { int32_t(2) };
    static constexpr int32_t FAIL { int32_t(3) };
    static constexpr int32_t RENDEZVOUS { int32_t(4) };

public: /* package */
    ::rice::pastry::socket::nat::NATHandler* natHandler {  };
    ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* connectivityVerifier {  };
    ::java::util::Collection* probeAddresses {  };
    ::java::net::InetAddressArray* externalAddresses {  };
protected:
    void ctor(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */;
    void ctor(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, ::rice::pastry::socket::nat::NATHandler* handler, ::java::util::Collection* probeAddresses, ::java::net::InetAddressArray* externalAddresses) /* throws(IOException) */;

public: /* protected */
    virtual ::rice::pastry::socket::nat::NATHandler* getDefaultNatHandler(::rice::environment::Environment* env, ::java::net::InetAddress* localAddress);
    virtual bool shouldFindExternalAddress(::java::net::InetAddress* address);
    virtual bool findExternalAddressIfNecessary(::java::net::InetAddress* address) /* throws(IOException) */;
    void newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars) override;
    virtual void findExternalAddress(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe);
    virtual void findExternalNodes(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::java::util::Collection* nonInternetRoutable, ::rice::Continuation* deliverResultToMe);
    virtual void findExternalAddressHelper(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Collection* myProbeAddresses);
    virtual void openFirewallPort(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe, ::java::net::InetAddress* externalAddress, int32_t requestedPort);
    virtual void verifyConnectivityThenMakeNewNode(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe);
    virtual bool isInternetRoutable(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress);
    virtual int32_t getFireWallPolicyVariable(::java::lang::String* key);
    virtual bool shouldCheckConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::java::util::Collection* bootstraps);

    // Generated

public:
    InternetPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    InternetPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, ::rice::pastry::socket::nat::NATHandler* handler, ::java::util::Collection* probeAddresses, ::java::net::InetAddressArray* externalAddresses);
protected:
    InternetPastryNodeFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* protected */
    virtual void newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, bool firewalled);
    virtual void newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, int8_t contactState);

private:
    virtual ::java::lang::Class* getClass0();
    friend class InternetPastryNodeFactory_findExternalNodes_1;
    friend class InternetPastryNodeFactory_findExternalAddressHelper_2;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4;
};
