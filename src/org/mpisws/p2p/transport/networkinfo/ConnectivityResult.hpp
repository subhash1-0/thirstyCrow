// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/ConnectivityResult.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::networkinfo::ConnectivityResult
    : public virtual ::java::lang::Object
{
    virtual void udpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) = 0;
    virtual void tcpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options) = 0;
    virtual void receiveException(::java::lang::Exception* e) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
