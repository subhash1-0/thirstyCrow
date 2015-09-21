// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.java

#pragma once

#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/CertificateManager.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::identity::IdentityTransport
    : public virtual CertificateManager
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::peerreview::history::HashProvider
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual ::rice::environment::Environment* getEnvironment() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
