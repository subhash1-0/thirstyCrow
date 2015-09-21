// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocol.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocol
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual void continuePush(::java::util::Map* subjects) = 0;
    virtual void handleIncomingAuthenticators(::java::lang::Object* source, ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage* msg) = 0;
    virtual void notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id) = 0;
    virtual void push() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
