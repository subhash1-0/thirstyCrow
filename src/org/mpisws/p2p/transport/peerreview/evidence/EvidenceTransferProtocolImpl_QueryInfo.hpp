// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_QueryInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Map* subjectList {  };
    ::rice::Continuation* c {  };
    int32_t numWitnessesWaitingFor {  };
    bool done_ {  };
protected:
    void ctor(::java::util::Collection* subjects, ::rice::Continuation* c);

public:
    virtual void updateWitnesses(EvidenceTransferProtocolImpl_CacheInfo* idx);
    virtual void done();

    // Generated
    EvidenceTransferProtocolImpl_QueryInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, ::java::util::Collection* subjects, ::rice::Continuation* c);
protected:
    EvidenceTransferProtocolImpl_QueryInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class EvidenceTransferProtocolImpl;
    friend class EvidenceTransferProtocolImpl_CacheInfo;
    friend class EvidenceTransferProtocolImpl_MessageInfo;
};
