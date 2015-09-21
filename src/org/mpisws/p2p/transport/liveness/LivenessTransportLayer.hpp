// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayer.java

#pragma once

#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/liveness/Pinger.hpp>

struct org::mpisws::p2p::transport::liveness::LivenessTransportLayer
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual LivenessProvider
    , public virtual Pinger
{

    // Generated
    static ::java::lang::Class *class_();
};
