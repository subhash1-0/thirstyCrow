// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/IdentityTransportCallback.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct org::mpisws::p2p::transport::peerreview::identity::IdentityTransportCallback
    : public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{
    virtual void notifyCertificateAvailable(::java::lang::Object* id) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
