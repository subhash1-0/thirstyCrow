// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::Object* subject {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* lastCheckedAuth {  };
    int32_t status {  };
    PeerInfoStore* store {  };

public: /* package */
    ::java::util::Map* answeredEvidence {  };
    ::java::util::Map* unansweredEvidence {  };
protected:
    void ctor(::java::lang::Object* id, PeerInfoStore* store);

public:
    virtual PeerInfoRecord_EvidenceRecordImpl* findEvidence(::java::lang::Object* originator, int64_t timestamp, bool create);
    virtual int32_t getStatus();
    virtual ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* getLastCheckedAuth();
    virtual void setLastCheckedAuth(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth, ::java::io::File* dir, IdStrTranslator* translator) /* throws(IOException) */;
    virtual EvidenceRecord* getFirstUnansweredChallenge();

public: /* protected */
    virtual EvidenceRecord* getFirstUnansweredChallenge(bool proof);

public:
    virtual EvidenceRecord* getFirstProof();

    // Generated
    PeerInfoRecord(::java::lang::Object* id, PeerInfoStore* store);
protected:
    PeerInfoRecord(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerInfoRecord_EvidenceRecordImpl;
};
