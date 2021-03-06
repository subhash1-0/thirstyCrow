// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifier.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl
    : public virtual ::java::lang::Object
    , public virtual ConnectivityVerifier
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::pastry::socket::SocketPastryNodeFactory* spnf {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::socket::SocketPastryNodeFactory* spnf);

public: /* protected */
    virtual ::rice::p2p::commonapi::Cancellable* getInetSocketAddressLookup(::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe);

public:
    ::rice::p2p::commonapi::Cancellable* findExternalNodes(::java::net::InetSocketAddress* local, ::java::util::Collection* probeAddresses, ::rice::Continuation* deliverResultToMe) override;
    virtual void findExternalNodesHelper(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::rice::p2p::util::AttachableCancellable* ret, ::java::net::InetSocketAddress* local, ::java::util::List* probeList, ::rice::Continuation* deliverResultToMe);
    ::rice::p2p::commonapi::Cancellable* findExternalAddress(::java::net::InetSocketAddress* local, ::java::util::Collection* probeAddresses, ::rice::Continuation* deliverResultToMe) override;
    virtual void findExternalAddressHelper(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::rice::p2p::util::AttachableCancellable* ret, ::java::net::InetSocketAddress* local, ::java::util::List* probeList, ::rice::Continuation* deliverResultToMe);
    ::rice::p2p::commonapi::Cancellable* verifyConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::Collection* probeAddresses, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe) override;
    virtual void verifyConnectivityHelper(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::rice::p2p::util::AttachableCancellable* ret, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::List* probeList, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe);

    // Generated
    ConnectivityVerifierImpl(::rice::pastry::socket::SocketPastryNodeFactory* spnf);
protected:
    ConnectivityVerifierImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
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
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2;
    friend class ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_receiveException_6_2_3;
};
