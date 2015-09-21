// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_CacheInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* subject {  };
    bool witnessesRequested {  };
    ::java::util::Collection* witness {  };

private:
    int64_t validUntil {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject);

public:
    virtual void updateWitnesses(::java::util::Collection* witnesses);
    virtual bool isValid();

    // Generated
    EvidenceTransferProtocolImpl_CacheInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject);
protected:
    EvidenceTransferProtocolImpl_CacheInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EvidenceTransferProtocolImpl;
    friend class EvidenceTransferProtocolImpl_MessageInfo;
    friend class EvidenceTransferProtocolImpl_QueryInfo;
};
