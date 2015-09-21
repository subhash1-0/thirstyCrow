// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl
    : public virtual ::java::lang::Object
    , public virtual EvidenceTransferProtocol
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t MAX_CACHE_ENTRIES { int32_t(500) };
    static constexpr int32_t MAX_PENDING_MESSAGES { int32_t(100) };
    static constexpr int32_t MAX_PENDING_QUERIES { int32_t(100) };
    static constexpr int32_t WITNESS_SET_VALID_MICROS { int32_t(300000000) };
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore {  };
    ::java::util::Map* witnessCache {  };
    ::java::util::Map* pendingMessage {  };
    ::java::util::Collection* pendingQuery {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore);

public:
    virtual void notifyWitnessSet(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::java::util::Collection* witnesses);

public: /* package */
    virtual void doSendMessageToWitnesses(::java::util::Collection* witnesses, EvidenceTransferProtocolImpl_MessageInfo* m);

public:
    virtual void sendMessageToWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void requestWitnesses(::java::util::Collection* subjectList, ::rice::Continuation* c) override;

public: /* protected */
    virtual ::java::util::Collection* getWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject);
    virtual void requestWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject);

public:
    virtual void sendEvidence(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject);

    // Generated
    EvidenceTransferProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore);
protected:
    EvidenceTransferProtocolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void notifyWitnessSet(::java::lang::Object* subject, ::java::util::Collection* witnesses) override;
    virtual void sendEvidence(::java::lang::Object* source, ::java::lang::Object* id) override;
    virtual void sendMessageToWitnesses(::java::lang::Object* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EvidenceTransferProtocolImpl_CacheInfo;
    friend class EvidenceTransferProtocolImpl_MessageInfo;
    friend class EvidenceTransferProtocolImpl_QueryInfo;
};
