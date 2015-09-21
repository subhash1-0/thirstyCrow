// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocol.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.hpp>

struct org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocol
    : public virtual ::org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener
{
    virtual void challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* handle) = 0;
    virtual void handleChallenge(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* challenge, ::java::util::Map* options) /* throws(IOException) */ = 0;
    virtual void handleIncomingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* udm, ::java::util::Map* options) /* throws(IOException) */ = 0;
    virtual void handleStatement(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* m, ::java::util::Map* options) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
