// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool udpSuccess_ {  };
    bool tcpSuccess_ {  };

public:
    void udpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) override;
    void tcpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) override;
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2(ConnectivityVerifierImpl_verifyConnectivity_6 *ConnectivityVerifierImpl_verifyConnectivity_6_this, ::rice::p2p::util::AttachableCancellable* ret, ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::Collection* probeAddresses, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe, ::java::util::ArrayList* probeList);
    static ::java::lang::Class *class_();

private:
    void init();
    ConnectivityVerifierImpl_verifyConnectivity_6 *ConnectivityVerifierImpl_verifyConnectivity_6_this;
    ::rice::p2p::util::AttachableCancellable* ret;
    ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup;
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local;
    ::java::util::Collection* probeAddresses;
    ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe;
    ::java::util::ArrayList* probeList;
    virtual ::java::lang::Class* getClass0();
    friend class ConnectivityVerifierImpl;
    friend class ConnectivityVerifierImpl_getInetSocketAddressLookup_1;
    friend class ConnectivityVerifierImpl_findExternalNodes_2;
    friend class ConnectivityVerifierImpl_findExternalNodesHelper_3;
    friend class ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveResult_3_1;
    friend class ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveException_3_2;
    friend class ConnectivityVerifierImpl_findExternalAddress_4;
    friend class ConnectivityVerifierImpl_findExternalAddressHelper_5;
    friend class ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveResult_5_1;
    friend class ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_receiveException_6_2_3;
};
