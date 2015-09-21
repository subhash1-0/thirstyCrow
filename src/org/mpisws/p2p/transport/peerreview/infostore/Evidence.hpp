// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/Evidence.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::infostore::Evidence
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual int16_t getEvidenceType() = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
