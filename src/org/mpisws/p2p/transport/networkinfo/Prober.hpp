// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/Prober.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::networkinfo::Prober
    : public virtual ::java::lang::Object
{
    virtual ::rice::p2p::commonapi::Cancellable* probe(::java::net::InetSocketAddress* addr, int64_t uid, ::rice::Continuation* deliverResponseToMe, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
