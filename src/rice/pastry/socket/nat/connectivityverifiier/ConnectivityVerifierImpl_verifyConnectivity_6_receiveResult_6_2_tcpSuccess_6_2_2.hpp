// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2(ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2 *ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_this, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe, ::java::net::InetSocketAddress* from, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2 *ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_this;
    ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe;
    ::java::net::InetSocketAddress* from;
    ::java::util::Map* options;

private:
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
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_receiveException_6_2_3;
};
