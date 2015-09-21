// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity
    : public virtual ::java::lang::Object
{
    virtual ::org::mpisws::p2p::transport::TransportLayer* getTransportLayer() = 0;
    virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider* getLivenessProvider() = 0;
    virtual ::org::mpisws::p2p::transport::proximity::ProximityProvider* getProximityProvider() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
