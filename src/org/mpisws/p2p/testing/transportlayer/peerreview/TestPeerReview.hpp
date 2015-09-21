// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/AuthenticatorStoreTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.hpp>

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

class org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReview
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::Environment* env {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* aSer {  };
protected:
    void ctor(::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* aSer);

public:
    ::org::mpisws::p2p::transport::util::Serializer* getIdSerializer() override;
    ::rice::environment::Environment* getEnvironment() override;
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* getAuthenticatorSerializer() override;
    int64_t getTime() override;
    ::org::mpisws::p2p::transport::util::Serializer* getHandleSerializer() override;
    int32_t getHashSizeInBytes() override;
    int32_t getSignatureSizeInBytes() override;
    ::org::mpisws::p2p::transport::peerreview::IdentifierExtractor* getIdentifierExtractor() override;
    virtual ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* extractAuthenticator(MyInetSocketAddress* id, int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* topMinusOne, ::int8_tArray* signature);
    virtual void challengeSuspectedNode(MyInetSocketAddress* h);
    int64_t getEvidenceSeq() override;
    virtual void sendEvidenceToWitnesses(MyInetSocketAddress* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence);
    virtual void notifyCertificateAvailable(MyInetSocketAddress* id);
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(MyInetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual bool hasCertificate(MyInetSocketAddress* id);
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(MyInetSocketAddress* source, MyInetSocketAddress* certHolder, ::rice::Continuation* c, ::java::util::Map* options);
    ::int8_tArray* sign(::int8_tArray* bytes) override;
    int16_t getSignatureSizeBytes() override;
    virtual void verify(MyInetSocketAddress* id, ::int8_tArray* msg, int32_t moff, int32_t mlen, ::int8_tArray* signature, int32_t soff, int32_t slen) /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException, SignatureException, UnknownCertificateException) */;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    MyInetSocketAddress* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(MyInetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(MyInetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    ::int8_tArray* getEmptyHash() override;
    int16_t getHashSizeBytes() override;
    ::int8_tArray* hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash) override;
    ::int8_tArray* hash(::java::nio::ByteBufferArray*/*...*/ hashMe) override;
    ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* getApp() override;
    virtual int32_t verify(MyInetSocketAddress* id, ::java::nio::ByteBuffer* msg, ::java::nio::ByteBuffer* signature);
    virtual bool addAuthenticatorIfValid(::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* store, MyInetSocketAddress* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth);
    virtual void transmit(MyInetSocketAddress* dest, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    ::org::mpisws::p2p::transport::peerreview::audit::EvidenceTool* getEvidenceTool() override;
    MyInetSocketAddress* getLocalId() override;
    virtual bool verify(MyInetSocketAddress* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth);
    MyInetSocketAddress* getLocalHandle() override;
    ::rice::environment::random::RandomSource* getRandomSource() override;
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* getHistoryFactory() override;
    ::org::mpisws::p2p::transport::peerreview::replay::VerifierFactory* getVerifierFactory() override;
    void init_(::java::lang::String* dirname) /* throws(IOException) */ override;
    void setApp(::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* callback) override;
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(MyInetSocketAddress* source, MyInetSocketAddress* certHolder);
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* getHistory() override;
    int64_t getTimeToleranceMillis() override;
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* extractAuthenticator(int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* topMinusOne, ::int8_tArray* signature) override;
    virtual int32_t verify(MyInetSocketAddress* id, ::int8_tArray* msg, ::int8_tArray* signature);
    virtual void sendEvidence(MyInetSocketAddress* destination, MyInetSocketAddress* evidenceAgainst);

    // Generated
    TestPeerReview(::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* aSer);
protected:
    TestPeerReview(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool addAuthenticatorIfValid(::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* store, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) override;
    virtual void challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* h) override;
    virtual ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* extractAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature) override;
    virtual bool hasCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* id) override;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual void notifyCertificateAvailable(::java::lang::Object* id) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(::java::lang::Object* source, ::java::lang::Object* certHolder, ::rice::Continuation* c, ::java::util::Map* options) override;
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder) override;
    virtual void sendEvidence(::rice::p2p::commonapi::rawserialization::RawSerializable* destination, ::rice::p2p::commonapi::rawserialization::RawSerializable* evidenceAgainst) override;
    virtual void sendEvidenceToWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    virtual void transmit(::rice::p2p::commonapi::rawserialization::RawSerializable* dest, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    virtual bool verify(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) override;
    virtual int32_t verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AuthenticatorStoreTest;
    friend class TestAuthenticatorStore;
};
