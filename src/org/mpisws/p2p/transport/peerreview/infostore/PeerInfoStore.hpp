// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore
    : public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{
    virtual void setStatusChangeListener(StatusChangeListener* listener) = 0;
    virtual void addEvidence(::java::lang::Object* localIdentifier, ::java::lang::Object* subject, int64_t evidenceSeq, Evidence* evidence) /* throws(IOException) */ = 0;
    virtual void addEvidence(::java::lang::Object* localIdentifier, ::java::lang::Object* subject, int64_t evidenceSeq, Evidence* evidence, ::java::lang::Object* interestedParty) /* throws(IOException) */ = 0;
    virtual void addResponse(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, Evidence* response) /* throws(IOException) */ = 0;
    virtual int32_t getStatus(::java::lang::Object* id) = 0;
    virtual void notifyStatusChanged(::java::lang::Object* subject, int32_t value) = 0;
    virtual bool setStorageDirectory(::java::io::File* file) /* throws(IOException) */ = 0;
    virtual Evidence* getEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp) /* throws(IOException) */ = 0;
    virtual EvidenceRecord* statFirstUnansweredChallenge(::java::lang::Object* subject) = 0;
    virtual EvidenceRecord* statProof(::java::lang::Object* subject) = 0;
    virtual EvidenceRecord* findEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp) = 0;
    virtual EvidenceRecord* findEvidence(::java::lang::Object* originator, ::java::lang::Object* subject, int64_t timestamp, bool create) = 0;
    virtual ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* getLastCheckedAuth(::java::lang::Object* id) = 0;
    virtual void setLastCheckedAuth(::java::lang::Object* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) = 0;
    virtual ::java::lang::String* getHistoryName(::java::lang::Object* subject) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
