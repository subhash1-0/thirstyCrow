// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/PingListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::liveness::PingListener
    : public virtual ::java::lang::Object
{
    virtual void pingResponse(::java::lang::Object* i, int32_t rtt, ::java::util::Map* options) = 0;
    virtual void pingReceived(::java::lang::Object* i, ::java::util::Map* options) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
