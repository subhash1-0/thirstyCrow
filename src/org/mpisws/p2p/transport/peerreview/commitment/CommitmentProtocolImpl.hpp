// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl
    : public virtual ::java::lang::Object
    , public virtual CommitmentProtocol
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;
    int32_t MAX_PEERS {  };
    int32_t INITIAL_TIMEOUT_MILLIS {  };
    int32_t RETRANSMIT_TIMEOUT_MILLIS {  };
    int32_t RECEIVE_CACHE_SIZE {  };
    int32_t MAX_RETRANSMISSIONS {  };
    int32_t TI_PROGRESS {  };
    int32_t PROGRESS_INTERVAL_MILLIS {  };
    int32_t MAX_ENTRIES_PER_MS {  };

public: /* package */
    ::java::util::Map* peer {  };
    ::java::util::Map* receiveCache {  };
    AuthenticatorStore* authStore {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    int64_t timeToleranceMillis {  };
    int32_t nextReceiveCacheEntry {  };
    int32_t signatureSizeBytes {  };
    int32_t hashSizeBytes {  };
    ::rice::selector::TimerTask* makeProgressTask {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, AuthenticatorStore* authStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, int64_t timeToleranceMillis) /* throws(IOException) */;

public: /* protected */
    virtual void initReceiveCache() /* throws(IOException) */;
    virtual void addToReceiveCache(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t senderSeq, int64_t indexInLocalHistory);
    virtual PeerInfo* lookupPeer(::rice::p2p::commonapi::rawserialization::RawSerializable* handle);

public:
    void notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id) override;
    ::rice::p2p::util::tuples::Tuple* logMessageIfNew(::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* udm) override;
    virtual void notifyStatusChange(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus);

public: /* protected */
    virtual void makeProgressAllPeers();
    virtual void makeProgress(::rice::p2p::commonapi::rawserialization::RawSerializable* idx);
    virtual int64_t findRecvEntry(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq);
    virtual int64_t findAckEntry(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq);

public:
    void handleIncomingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* msg, ::java::util::Map* options) /* throws(IOException) */ override;
    ::org::mpisws::p2p::transport::MessageRequestHandle* handleOutgoingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void handleIncomingAck(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::AckMessage* ackMessage, ::java::util::Map* options) /* throws(IOException) */ override;
    void setTimeToleranceMillis(int64_t timeToleranceMillis) override;

    // Generated
    CommitmentProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, AuthenticatorStore* authStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, int64_t timeToleranceMillis);
protected:
    CommitmentProtocolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class CommitmentProtocolImpl_CommitmentProtocolImpl_1;
    friend class CommitmentProtocolImpl_initReceiveCache_2;
};
