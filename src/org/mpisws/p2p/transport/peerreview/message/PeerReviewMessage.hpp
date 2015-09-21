// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
    , public virtual ::rice::p2p::commonapi::rawserialization::RawSerializable
{
    virtual int16_t getType() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
