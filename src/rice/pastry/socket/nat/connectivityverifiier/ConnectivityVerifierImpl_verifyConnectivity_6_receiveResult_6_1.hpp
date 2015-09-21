// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;

    // Generated
    ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1(ConnectivityVerifierImpl_verifyConnectivity_6 *ConnectivityVerifierImpl_verifyConnectivity_6_this, ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup);
    static ::java::lang::Class *class_();
    ConnectivityVerifierImpl_verifyConnectivity_6 *ConnectivityVerifierImpl_verifyConnectivity_6_this;
    ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup;

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
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_receiveException_6_2_3;
};
