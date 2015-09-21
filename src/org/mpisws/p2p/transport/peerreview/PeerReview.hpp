// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReview.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
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
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>

struct org::mpisws::p2p::transport::peerreview::PeerReview
    : public virtual ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransportCallback
    , public virtual PeerReviewConstants
    , public virtual ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport
{

private:
    static ::java::lang::String* RELEVANT_LENGTH_;
    static ::java::lang::String* DONT_COMMIT_;

public:
    static constexpr int8_t PEER_REVIEW_PASSTHROUGH { int8_t(0) };
    static constexpr int8_t PEER_REVIEW_COMMIT { int8_t(1) };
    virtual ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* extractAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature) = 0;
    virtual bool addAuthenticatorIfValid(::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* store, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) = 0;
    virtual bool hasCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* id) = 0;
    /*::rice::environment::Environment* getEnvironment(); (already declared) */
    virtual ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* getAuthenticatorSerializer() = 0;
    virtual ::org::mpisws::p2p::transport::util::Serializer* getHandleSerializer() = 0;
    virtual ::org::mpisws::p2p::transport::util::Serializer* getIdSerializer() = 0;
    virtual void challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* h) = 0;
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getLocalId() = 0;
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getLocalHandle() = 0;
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder) = 0;
    virtual ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* extractAuthenticator(int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature) = 0;
    virtual void transmit(::rice::p2p::commonapi::rawserialization::RawSerializable* dest, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) = 0;
    virtual int64_t getTime() = 0;
    virtual int32_t getHashSizeInBytes() = 0;
    virtual int32_t getSignatureSizeInBytes() = 0;
    virtual IdentifierExtractor* getIdentifierExtractor() = 0;
    virtual int64_t getEvidenceSeq() = 0;
    virtual void sendEvidenceToWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence) = 0;
    virtual void init_(::java::lang::String* dirname) /* throws(IOException) */ = 0;
    virtual void setApp(PeerReviewCallback* callback) = 0;
    virtual PeerReviewCallback* getApp() = 0;
    virtual ::org::mpisws::p2p::transport::peerreview::audit::EvidenceTool* getEvidenceTool() = 0;
    virtual bool verify(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth) = 0;
    virtual ::rice::environment::random::RandomSource* getRandomSource() = 0;
    virtual ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* getHistoryFactory() = 0;
    virtual ::org::mpisws::p2p::transport::peerreview::replay::VerifierFactory* getVerifierFactory() = 0;
    virtual ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* getHistory() = 0;
    virtual int64_t getTimeToleranceMillis() = 0;
    virtual void sendEvidence(::rice::p2p::commonapi::rawserialization::RawSerializable* destination, ::rice::p2p::commonapi::rawserialization::RawSerializable* evidenceAgainst) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(::java::lang::Object* source, ::java::lang::Object* certHolder, ::rice::Continuation* c, ::java::util::Map* options) = 0;
    virtual int32_t verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature) = 0;
    static ::java::lang::String*& RELEVANT_LENGTH();
    static ::java::lang::String*& DONT_COMMIT();
};
