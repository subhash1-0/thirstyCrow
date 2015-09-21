// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/AuthenticatorStoreTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/TestPeerReview.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::TestPeerReview(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::TestPeerReview(::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* aSer) 
    : TestPeerReview(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,aSer);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::ctor(::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* aSer)
{
    super::ctor();
    this->env = env;
    this->aSer = aSer;
}

org::mpisws::p2p::transport::util::Serializer* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getIdSerializer()
{
    return MyInetSocketAddress::serializer();
}

rice::environment::Environment* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getEnvironment()
{
    return env;
}

org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getAuthenticatorSerializer()
{
    return aSer;
}

int64_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getTime()
{
    return npc(npc(env)->getTimeSource())->currentTimeMillis();
}

org::mpisws::p2p::transport::util::Serializer* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getHandleSerializer()
{
    return nullptr;
}

int32_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getHashSizeInBytes()
{
    return 0;
}

int32_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getSignatureSizeInBytes()
{
    return 0;
}

org::mpisws::p2p::transport::peerreview::IdentifierExtractor* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getIdentifierExtractor()
{
    return nullptr;
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::extractAuthenticator(MyInetSocketAddress* id, int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* topMinusOne, ::int8_tArray* signature)
{
    return nullptr;
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::extractAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature)
{ 
    return extractAuthenticator(dynamic_cast< MyInetSocketAddress* >(id), seq, entryType, entryHash, hTopMinusOne, signature);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::challengeSuspectedNode(MyInetSocketAddress* h)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* h)
{ 
    challengeSuspectedNode(dynamic_cast< MyInetSocketAddress* >(h));
}

int64_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getEvidenceSeq()
{
    return 0;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::sendEvidenceToWitnesses(MyInetSocketAddress* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::sendEvidenceToWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence)
{ 
    sendEvidenceToWitnesses(dynamic_cast< MyInetSocketAddress* >(subject), timestamp, evidence);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::notifyCertificateAvailable(MyInetSocketAddress* id)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::notifyCertificateAvailable(::java::lang::Object* id)
{ 
    notifyCertificateAvailable(dynamic_cast< MyInetSocketAddress* >(id));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::messageReceived(MyInetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< MyInetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::hasCertificate(MyInetSocketAddress* id)
{
    return false;
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::hasCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{ 
    return hasCertificate(dynamic_cast< MyInetSocketAddress* >(id));
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::requestCertificate(MyInetSocketAddress* source, MyInetSocketAddress* certHolder, ::rice::Continuation* c, ::java::util::Map* options)
{
    return nullptr;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::requestCertificate(::java::lang::Object* source, ::java::lang::Object* certHolder, ::rice::Continuation* c, ::java::util::Map* options)
{ 
    return requestCertificate(dynamic_cast< MyInetSocketAddress* >(source), dynamic_cast< MyInetSocketAddress* >(certHolder), c, options);
}

int8_tArray* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::sign(::int8_tArray* bytes)
{
    return nullptr;
}

int16_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getSignatureSizeBytes()
{
    return 0;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::verify(MyInetSocketAddress* id, ::int8_tArray* msg, int32_t moff, int32_t mlen, ::int8_tArray* signature, int32_t soff, int32_t slen) /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException, SignatureException, UnknownCertificateException) */
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::acceptMessages(bool b)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::acceptSockets(bool b)
{
}

org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getLocalIdentifier()
{
    return nullptr;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::openSocket(MyInetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return nullptr;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< MyInetSocketAddress* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::sendMessage(MyInetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return nullptr;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< MyInetSocketAddress* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::destroy()
{
}

int8_tArray* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getEmptyHash()
{
    return nullptr;
}

int16_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getHashSizeBytes()
{
    return 0;
}

int8_tArray* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash)
{
    return nullptr;
}

int8_tArray* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::hash(::java::nio::ByteBufferArray*/*...*/ hashMe)
{
    return nullptr;
}

org::mpisws::p2p::transport::peerreview::PeerReviewCallback* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getApp()
{
    return nullptr;
}

int32_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::verify(MyInetSocketAddress* id, ::java::nio::ByteBuffer* msg, ::java::nio::ByteBuffer* signature)
{
    return SIGNATURE_BAD;
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::addAuthenticatorIfValid(::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* store, MyInetSocketAddress* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth)
{
    return false;
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::addAuthenticatorIfValid(::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* store, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth)
{ 
    return addAuthenticatorIfValid(dynamic_cast< ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* >(store), dynamic_cast< MyInetSocketAddress* >(subject), auth);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::transmit(MyInetSocketAddress* dest, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::transmit(::rice::p2p::commonapi::rawserialization::RawSerializable* dest, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    transmit(dynamic_cast< MyInetSocketAddress* >(dest), message, dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

org::mpisws::p2p::transport::peerreview::audit::EvidenceTool* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getEvidenceTool()
{
    return nullptr;
}

org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getLocalId()
{
    return nullptr;
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::verify(MyInetSocketAddress* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth)
{
    return false;
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::verify(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth)
{ 
    return verify(dynamic_cast< MyInetSocketAddress* >(subject), auth);
}

org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getLocalHandle()
{
    return nullptr;
}

rice::environment::random::RandomSource* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getRandomSource()
{
    return nullptr;
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getHistoryFactory()
{
    return nullptr;
}

org::mpisws::p2p::transport::peerreview::replay::VerifierFactory* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getVerifierFactory()
{
    return nullptr;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::init_(::java::lang::String* dirname) /* throws(IOException) */
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::setApp(::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* callback)
{
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::requestCertificate(MyInetSocketAddress* source, MyInetSocketAddress* certHolder)
{
    return nullptr;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::requestCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder)
{ 
    return requestCertificate(dynamic_cast< MyInetSocketAddress* >(source), dynamic_cast< MyInetSocketAddress* >(certHolder));
}

org::mpisws::p2p::transport::peerreview::history::SecureHistory* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getHistory()
{
    return nullptr;
}

int64_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getTimeToleranceMillis()
{
    return 0;
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::extractAuthenticator(int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* topMinusOne, ::int8_tArray* signature)
{
    return nullptr;
}

int32_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::verify(MyInetSocketAddress* id, ::int8_tArray* msg, ::int8_tArray* signature)
{
    return 0;
}

int32_t org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature)
{ 
    return verify(dynamic_cast< MyInetSocketAddress* >(id), msg, signature);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::sendEvidence(MyInetSocketAddress* destination, MyInetSocketAddress* evidenceAgainst)
{
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::sendEvidence(::rice::p2p::commonapi::rawserialization::RawSerializable* destination, ::rice::p2p::commonapi::rawserialization::RawSerializable* evidenceAgainst)
{ 
    sendEvidence(dynamic_cast< MyInetSocketAddress* >(destination), dynamic_cast< MyInetSocketAddress* >(evidenceAgainst));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.TestPeerReview", 63);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::TestPeerReview::getClass0()
{
    return class_();
}

