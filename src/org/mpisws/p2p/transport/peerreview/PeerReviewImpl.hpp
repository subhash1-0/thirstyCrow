// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::PeerReviewImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
    , public virtual PeerReview
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    PeerReviewCallback* callback {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    ::org::mpisws::p2p::transport::util::Serializer* handleSerializer {  };
    ::org::mpisws::p2p::transport::util::Serializer* idSerializer {  };
    IdentifierExtractor* identifierExtractor {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* stringTranslator {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evidenceSerializer {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authenticatorSerialilzer {  };
    ::org::mpisws::p2p::transport::peerreview::audit::EvidenceTool* evidenceTool {  };
    ::rice::environment::Environment* env {  };
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authInStore {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authCacheStore {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authPendingStore {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* historyFactory {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };
    ::org::mpisws::p2p::transport::peerreview::replay::VerifierFactory* verifierFactory {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocol* authPushProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::audit::AuditProtocol* auditProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocol* challengeProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl* statementProtocol {  };

public: /* package */
    int64_t nextEvidenceSeq {  };

private:
    ::rice::selector::TimerTask* maintenanceTask {  };
    ::rice::selector::TimerTask* authPushTask {  };
    ::rice::selector::TimerTask* checkpointTask {  };

public: /* protected */
    ::rice::environment::random::RandomSource* random {  };

public:
    ::rice::environment::random::RandomSource* getRandomSource() override;

public: /* package */
    int64_t lastLogEntry {  };
    bool initialized {  };

public: /* protected */
    int64_t timeToleranceMillis {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, IdentifierExtractor* identifierExtractor, ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* stringTranslator);

public: /* protected */
    virtual ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* getSecureHistoryFactory(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env);

public:
    virtual void setTimeToleranceMillis(int64_t timeToleranceMicros);
    int64_t getEvidenceSeq() override;

public: /* protected */
    virtual void updateLogTime();

public:
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void setApp(PeerReviewCallback* callback) override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    virtual void messageReceived(::rice::p2p::commonapi::rawserialization::RawSerializable* handle, ::java::nio::ByteBuffer* message, ::java::util::Map* options) /* throws(IOException) */;
    static ::java::lang::String* getStatusString(int32_t status);
    bool addAuthenticatorIfValid(::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* store, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) override;
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder, ::rice::Continuation* c, ::java::util::Map* options);
    ::rice::p2p::commonapi::Cancellable* requestCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder) override;
    virtual void notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    virtual void writeCheckpoint() /* throws(IOException) */;

public: /* protected */
    virtual void doAuthPush();
    virtual void doMaintenance();
    virtual void doCheckpoint();

public:
    virtual void notifyStatusChange(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus);
    void init_(::java::lang::String* dirname) /* throws(IOException) */ override;
    PeerReviewCallback* getApp() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* getLocalId() override;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* getLocalHandle() override;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* getLocalIdentifier() override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* getAuthenticatorSerializer() override;
    ::rice::environment::Environment* getEnvironment() override;
    ::org::mpisws::p2p::transport::util::Serializer* getIdSerializer() override;
    int64_t getTime() override;
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* extractAuthenticator(int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature) override;
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* extractAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature) override;
    ::org::mpisws::p2p::transport::util::Serializer* getHandleSerializer() override;
    int32_t getHashSizeInBytes() override;
    int32_t getSignatureSizeInBytes() override;
    IdentifierExtractor* getIdentifierExtractor() override;
    void challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* handle) override;
    void sendEvidenceToWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence) override;
    void transmit(::rice::p2p::commonapi::rawserialization::RawSerializable* dest, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    bool hasCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* id) override;
    ::int8_tArray* sign(::int8_tArray* bytes) override;
    int16_t getSignatureSizeBytes() override;
    bool verify(::rice::p2p::commonapi::rawserialization::RawSerializable* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) override;
    virtual int32_t verify(::rice::p2p::commonapi::rawserialization::RawSerializable* id, ::int8_tArray* msg, ::int8_tArray* signature);
    ::int8_tArray* getEmptyHash() override;
    int16_t getHashSizeBytes() override;
    ::int8_tArray* hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash) override;
    ::int8_tArray* hash(::java::nio::ByteBufferArray*/*...*/ hashMe) override;
    virtual ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* getEvidenceSerializer();
    ::org::mpisws::p2p::transport::peerreview::audit::EvidenceTool* getEvidenceTool() override;
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* getHistoryFactory() override;
    ::org::mpisws::p2p::transport::peerreview::replay::VerifierFactory* getVerifierFactory() override;

public: /* package */
    virtual void disableAuthenticatorProcessing();

public:
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* getHistory() override;
    int64_t getTimeToleranceMillis() override;
    void sendEvidence(::rice::p2p::commonapi::rawserialization::RawSerializable* dest, ::rice::p2p::commonapi::rawserialization::RawSerializable* evidenceAgainst) override;

    // Generated
    PeerReviewImpl(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, IdentifierExtractor* identifierExtractor, ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* stringTranslator);
protected:
    PeerReviewImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual bool hasCertificate(::java::lang::Object* id) override;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual void notifyCertificateAvailable(::java::lang::Object* id) override;
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(::java::lang::Object* source, ::java::lang::Object* certHolder, ::rice::Continuation* c, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    virtual int32_t verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerReviewImpl_sendMessage_1;
    friend class PeerReviewImpl_requestCertificate_2;
    friend class PeerReviewImpl_notifyStatusChange_3;
    friend class PeerReviewImpl_init_4;
    friend class PeerReviewImpl_init_5;
    friend class PeerReviewImpl_init_6;
};
