// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/AuditProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::audit::AuditProtocol
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* statOngoingAudit(::java::lang::Object* subject, int64_t evidenceSeq) = 0;
    virtual void processAuditResponse(::java::lang::Object* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* auditResponse) /* throws(IOException) */ = 0;
    virtual void handleIncomingDatagram(::rice::p2p::commonapi::rawserialization::RawSerializable* handle, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
