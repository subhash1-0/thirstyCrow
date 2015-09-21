// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/Verifier.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::replay::Verifier
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual bool makeProgress() = 0;
    virtual bool verifiedOK() = 0;
    virtual void setApplication(::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* app) = 0;
    virtual int64_t getNextEventTime() = 0;
    virtual bool isSuccess() = 0;
    virtual ::rice::environment::Environment* getEnvironment() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
