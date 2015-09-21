// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>

struct org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup
    : public virtual ::rice::Destructable
{
    virtual ::rice::p2p::commonapi::Cancellable* getExternalNodes(::java::net::InetSocketAddress* bootstrap, ::rice::Continuation* c, ::java::util::Map* options) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* getMyInetAddress(::java::net::InetSocketAddress* bootstrap, ::rice::Continuation* c, ::java::util::Map* options) = 0;
    virtual ::rice::p2p::commonapi::Cancellable* verifyConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::net::InetSocketAddress* probeAddresses, ConnectivityResult* deliverResultToMe, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
