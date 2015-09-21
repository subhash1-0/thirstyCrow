// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/UpperIdentity.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>

struct org::mpisws::p2p::transport::identity::UpperIdentity
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityProvider
{

    // Generated
    static ::java::lang::Class *class_();
    virtual void clearState(::java::lang::Object* i) = 0;
};
