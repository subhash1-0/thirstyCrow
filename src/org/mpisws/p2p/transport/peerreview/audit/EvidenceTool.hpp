// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/EvidenceTool.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::audit::EvidenceTool
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual ::rice::p2p::util::tuples::Tuple* checkSnippet(LogSnippet* snippet) = 0;
    virtual bool checkSnippetSignatures(LogSnippet* snippet, ::rice::p2p::commonapi::rawserialization::RawSerializable* subjectHandle, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authStoreOrNull, int8_t flags, ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol, ::int8_tArray* keyNodeHash, int64_t keyNodeMaxSeq) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
