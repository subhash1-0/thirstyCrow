// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifier.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::Cancellable* findExternalNodes(::java::net::InetSocketAddress* local, ::java::util::Collection* probeAddresses, ::rice::Continuation* deliverResultToMe) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* findExternalAddress(::java::net::InetSocketAddress* local, ::java::util::Collection* probeAddresses, ::rice::Continuation* deliverResultToMe) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* verifyConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::Collection* probeAddresses, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
