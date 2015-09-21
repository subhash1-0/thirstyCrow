// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/AddressStrategy.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::multiaddress::AddressStrategy
    : public virtual ::java::lang::Object
{
    virtual ::java::net::InetSocketAddress* getAddress(MultiInetSocketAddress* local, MultiInetSocketAddress* remote) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
