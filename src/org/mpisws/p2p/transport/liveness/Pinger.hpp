// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/Pinger.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::liveness::Pinger
    : public virtual ::java::lang::Object
{
    virtual bool ping(::java::lang::Object* i, ::java::util::Map* options) = 0;
    virtual void addPingListener(PingListener* name) = 0;
    virtual bool removePingListener(PingListener* name) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
