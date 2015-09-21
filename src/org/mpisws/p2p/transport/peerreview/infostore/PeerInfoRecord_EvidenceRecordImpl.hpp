// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/PeerInfoRecord.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceRecord.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::infostore::PeerInfoRecord_EvidenceRecordImpl
    : public virtual ::java::lang::Object
    , public virtual EvidenceRecord
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::Object* originator {  };
    int64_t timestamp {  };

public: /* package */
    ::java::lang::Object* interestedParty {  };
    bool isProof_ {  };
protected:
    void ctor(::java::lang::Object* originator, int64_t timestamp);
    void ctor(::java::lang::Object* originator, int64_t timestamp, bool isProof, ::java::lang::Object* interestedParty);

public:
    bool hasResponse() override;
    void setIsProof(bool isProof) override;
    void setInterestedParty(::java::lang::Object* interestedParty) override;
    void setHasResponse() override;
    bool isProof() override;
    int64_t getTimeStamp() override;
    ::java::lang::Object* getOriginator() override;
    ::java::lang::Object* getInterestedParty() override;

    // Generated
    PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord *PeerInfoRecord_this, ::java::lang::Object* originator, int64_t timestamp);
    PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord *PeerInfoRecord_this, ::java::lang::Object* originator, int64_t timestamp, bool isProof, ::java::lang::Object* interestedParty);
protected:
    PeerInfoRecord_EvidenceRecordImpl(PeerInfoRecord *PeerInfoRecord_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    PeerInfoRecord *PeerInfoRecord_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerInfoRecord;
};
