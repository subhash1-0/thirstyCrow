// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_getInetSocketAddressLookup_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    ConnectivityVerifierImpl_getInetSocketAddressLookup_1(ConnectivityVerifierImpl *ConnectivityVerifierImpl_this, ::rice::p2p::util::AttachableCancellable* ret, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe);
    static ::java::lang::Class *class_();
    ConnectivityVerifierImpl *ConnectivityVerifierImpl_this;
    ::rice::p2p::util::AttachableCancellable* ret;
    ::java::net::InetSocketAddress* bindAddress;
    ::rice::Continuation* deliverResultToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ConnectivityVerifierImpl;
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
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_receiveException_6_2_3;
};
