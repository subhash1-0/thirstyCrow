// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl_MessageInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* subject {  };
    ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message {  };
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe {  };
    ::java::util::Map* options {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);

    // Generated

public:
    EvidenceTransferProtocolImpl_MessageInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
protected:
    EvidenceTransferProtocolImpl_MessageInfo(EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    EvidenceTransferProtocolImpl *EvidenceTransferProtocolImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EvidenceTransferProtocolImpl;
    friend class EvidenceTransferProtocolImpl_CacheInfo;
    friend class EvidenceTransferProtocolImpl_QueryInfo;
};
