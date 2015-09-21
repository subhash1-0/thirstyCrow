// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/EvidenceRecord.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord
    : public virtual ::java::lang::Object
{
    virtual void setInterestedParty(::java::lang::Object* interestedParty) = 0;
    virtual void setIsProof(bool isProof) = 0;
    virtual bool isProof() = 0;
    virtual void setHasResponse() = 0;
    virtual bool hasResponse() = 0;
    virtual int64_t getTimeStamp() = 0;
    virtual ::java::lang::Object* getOriginator() = 0;
    virtual ::java::lang::Object* getInterestedParty() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
