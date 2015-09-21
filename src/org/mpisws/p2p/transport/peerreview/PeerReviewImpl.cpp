// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/IdentifierExtractor.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_sendMessage_1.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_requestCertificate_2.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_notifyStatusChange_3.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_init_4.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_init_5.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_init_6.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceTool.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializerImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStoreImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceSerializerImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofInconsistent.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashSeq.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceSerializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/IdStrTranslator.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStoreImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AccusationMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AckMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AuthPushMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AuthRequest.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AuthResponse.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/ChallengeMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/ResponseMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierFactoryImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSM.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/Statement.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/StatementProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::PeerReviewImpl::PeerReviewImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::PeerReviewImpl::PeerReviewImpl(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, IdentifierExtractor* identifierExtractor, ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* stringTranslator) 
    : PeerReviewImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(transport,env,handleSerializer,idSerializer,identifierExtractor,stringTranslator);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::init()
{
    nextEvidenceSeq = int64_t(0LL);
    lastLogEntry = -int32_t(1);
    initialized = false;
    timeToleranceMillis = PeerReviewConstants::DEFAULT_TIME_TOLERANCE_MILLIS;
}

rice::environment::random::RandomSource* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getRandomSource()
{
    return random;
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::ctor(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, IdentifierExtractor* identifierExtractor, ::org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator* stringTranslator)
{
    super::ctor();
    init();
    if(!(dynamic_cast< ::org::mpisws::p2p::transport::peerreview::replay::record::RecordSM* >(npc(env)->getSelectorManager()) != nullptr)) {
        throw new ::java::lang::IllegalArgumentException(u"Environment.getSelectorManager() must return a RecordSM"_j);
    }
    this->transport = transport;
    npc(java_cast< ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* >(this->transport))->setCallback(this);
    this->stringTranslator = stringTranslator;
    this->env = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(PeerReviewImpl::class_(), nullptr);
    this->idSerializer = idSerializer;
    this->handleSerializer = handleSerializer;
    this->identifierExtractor = identifierExtractor;
    this->authenticatorSerialilzer = new ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl(npc(transport)->getHashSizeBytes(), npc(transport)->getSignatureSizeBytes());
    this->evidenceSerializer = new ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceSerializerImpl(handleSerializer, idSerializer, npc(transport)->getHashSizeBytes(), npc(transport)->getSignatureSizeBytes());
    this->historyFactory = getSecureHistoryFactory(transport, env);
    random = new ::rice::environment::random::simple::SimpleRandomSource(npc(env)->getLogManager(), u"peerreview"_j);
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getSecureHistoryFactory(::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::rice::environment::Environment* env)
{
    return new ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl(transport, env);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::setTimeToleranceMillis(int64_t timeToleranceMicros)
{
    this->timeToleranceMillis = timeToleranceMicros;
    if(commitmentProtocol != nullptr)
        npc(commitmentProtocol)->setTimeToleranceMillis(timeToleranceMicros);

}

int64_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getEvidenceSeq()
{
    if(nextEvidenceSeq < getTime()) {
        nextEvidenceSeq = getTime();
    }
    return nextEvidenceSeq++;
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::updateLogTime()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(u"updateLogTime()"_j);

    auto now = npc(npc(env)->getTimeSource())->currentTimeMillis();
    if(now > lastLogEntry) {
        if(!npc(history)->setNextSeq(now * int32_t(1000000)))
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(u"PeerReview: Cannot roll back history sequence number from "_j)->append(npc(history)->getLastSeq())
                ->append(u" to "_j)
                ->append(now * int32_t(1000000))->toString())->append(u"; did you change the local time?"_j)->toString());

        lastLogEntry = now;
    }
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::sendMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(options != nullptr && npc(options)->containsKey(DONT_COMMIT())) {
        auto const ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(target, message, options);
        auto msg = ::java::nio::ByteBuffer::allocate(npc(message)->remaining() + int32_t(1));
        npc(msg)->put(PEER_REVIEW_PASSTHROUGH);
        npc(msg)->put(message);
        npc(msg)->flip();
        npc(ret)->setSubCancellable(npc(transport)->sendMessage(target, msg, new PeerReviewImpl_sendMessage_1(this, deliverAckToMe, ret), options));
        return ret;
    }
    /* assert((initialized)) */ ;
    updateLogTime();
    return npc(commitmentProtocol)->handleOutgoingMessage(target, message, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::setApp(PeerReviewCallback* callback)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"setApp("_j)->append(static_cast< ::java::lang::Object* >(callback))
            ->append(u")"_j)->toString());

    this->callback = callback;
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    setApp(java_cast< PeerReviewCallback* >(callback));
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::messageReceived(::rice::p2p::commonapi::rawserialization::RawSerializable* handle, ::java::nio::ByteBuffer* message, ::java::util::Map* options) /* throws(IOException) */
{
    /* assert((initialized)) */ ;
    if(npc(infoStore)->getStatus(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(identifierExtractor)->extractIdentifier(handle))) == STATUS_EXPOSED) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received a message from an exposed node "_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" -- ignoring"_j)->toString());

        return;
    }
    auto passthrough = npc(message)->get();
    {
        ::org::mpisws::p2p::transport::peerreview::statement::Statement* m;
        int8_t type;
        ::rice::p2p::util::rawserialization::SimpleInputBuffer* sib;
        switch (passthrough) {
        case PEER_REVIEW_PASSTHROUGH:
            npc(callback)->messageReceived(handle, message, options);
            break;
        case PEER_REVIEW_COMMIT:
            m = nullptr;
            updateLogTime();
            type = npc(message)->get();
            sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(message);
            {
                ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* challenge;
                ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* udm;
                switch (type) {
                case MSG_AUTHPUSH:
                    npc(authPushProtocol)->handleIncomingAuthenticators(handle, ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::build(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(message), idSerializer, authenticatorSerialilzer));
                    break;
                case MSG_AUTHREQ:
                    npc(auditProtocol)->handleIncomingDatagram(handle, new ::org::mpisws::p2p::transport::peerreview::message::AuthRequest(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(message)), static_cast< ::org::mpisws::p2p::transport::util::Serializer* >(idSerializer)));
                    break;
                case MSG_AUTHRESP:
                    npc(auditProtocol)->handleIncomingDatagram(handle, new ::org::mpisws::p2p::transport::peerreview::message::AuthResponse(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(message), idSerializer, npc(transport)->getHashSizeBytes(), npc(transport)->getSignatureSizeBytes()));
                    break;
                case MSG_ACK:
                    npc(commitmentProtocol)->handleIncomingAck(handle, ::org::mpisws::p2p::transport::peerreview::message::AckMessage::build(sib, idSerializer, npc(transport)->getHashSizeBytes(), npc(transport)->getSignatureSizeBytes()), options);
                    break;
                case MSG_CHALLENGE:
                    challenge = new ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(sib), static_cast< ::org::mpisws::p2p::transport::util::Serializer* >(idSerializer), evidenceSerializer);
                    npc(challengeProtocol)->handleChallenge(handle, challenge, options);
                    break;
                case MSG_ACCUSATION:
                    npc(statementProtocol)->handleIncomingStatement(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(handle), static_cast< ::org::mpisws::p2p::transport::peerreview::statement::Statement* >(new ::org::mpisws::p2p::transport::peerreview::message::AccusationMessage(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(sib), static_cast< ::org::mpisws::p2p::transport::util::Serializer* >(idSerializer), evidenceSerializer)), options);
                    break;
                case MSG_RESPONSE:
                    npc(statementProtocol)->handleIncomingStatement(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(handle), static_cast< ::org::mpisws::p2p::transport::peerreview::statement::Statement* >(new ::org::mpisws::p2p::transport::peerreview::message::ResponseMessage(sib, idSerializer, evidenceSerializer)), options);
                    break;
                case MSG_USERDATA:
                    udm = ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage::build(sib, handleSerializer, npc(transport)->getHashSizeBytes(), npc(transport)->getSignatureSizeBytes());
                    npc(challengeProtocol)->handleIncomingMessage(handle, udm, options);
                    break;
                default:
                    throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Unknown message type in PeerReview: #"_j)->append(type)->toString());
                }
            }

        }
    }

}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

java::lang::String* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getStatusString(int32_t status)
{
    clinit();
    switch (status) {
    case STATUS_EXPOSED:
        return u"exposed"_j;
    case STATUS_TRUSTED:
        return u"trusted"_j;
    case STATUS_SUSPECTED:
        return u"suspected"_j;
    }

    return ::java::lang::StringBuilder().append(u"unknown status:"_j)->append(status)->toString();
}

bool org::mpisws::p2p::transport::peerreview::PeerReviewImpl::addAuthenticatorIfValid(::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* store, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth)
{
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* existingAuth = nullptr;
    if(store != nullptr)
        existingAuth = npc(store)->statAuthenticator(subject, npc(auth)->getSeq());

    if(existingAuth != nullptr) {
        if(npc(auth)->equals(static_cast< ::java::lang::Object* >(existingAuth))) {
            return true;
        }
    }
    /* assert((npc(transport)->hasCertificate(subject))) */ ;
    try {
        auto signedHash = npc(transport)->hash(new ::java::nio::ByteBufferArray({npc(auth)->getPartToHashThenSign()}));
        auto sigResult = npc(transport)->verify(subject, signedHash, npc(auth)->getSignature());
        /* assert(((sigResult == SIGNATURE_OK) || sigResult == SIGNATURE_BAD)) */ ;
        if(sigResult != SIGNATURE_OK)
            return false;

        if(!verify(subject, auth)) {
            return false;
        }
        if(existingAuth != nullptr) {
            if(npc(logger)->level < ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Authenticator conflict for "_j)->append(static_cast< ::java::lang::Object* >(subject))
                    ->append(u" seq #"_j)
                    ->append(npc(auth)->getSeq())->toString());

            if(npc(logger)->level < ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Existing: ["_j)->append(static_cast< ::java::lang::Object* >(existingAuth))
                    ->append(u"]"_j)->toString());

            if(npc(logger)->level < ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"New:      ["_j)->append(static_cast< ::java::lang::Object* >(auth))
                    ->append(u"]"_j)->toString());

            auto proof = new ::org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent(auth, existingAuth);
            auto evidenceSeq = getEvidenceSeq();
            npc(infoStore)->addEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(identifierExtractor)->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(transport)->getLocalIdentifier()))), subject, evidenceSeq, proof, nullptr);
            sendEvidenceToWitnesses(subject, evidenceSeq, static_cast< ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* >(proof));
            return false;
        }
        if(store != nullptr)
            npc(store)->addAuthenticator(subject, auth);

        return true;
    } catch (::java::lang::Exception* e) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
    }
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::requestCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder, ::rice::Continuation* c, ::java::util::Map* options)
{
    return npc(transport)->requestCertificate(source, certHolder, c, options);
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::requestCertificate(::java::lang::Object* source, ::java::lang::Object* certHolder, ::rice::Continuation* c, ::java::util::Map* options)
{ 
    return requestCertificate(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(source), dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(certHolder), c, options);
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::requestCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder)
{
    return npc(transport)->requestCertificate(source, certHolder, new PeerReviewImpl_requestCertificate_2(this, certHolder, source), nullptr);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    npc(commitmentProtocol)->notifyCertificateAvailable(id);
    npc(authPushProtocol)->notifyCertificateAvailable(id);
    npc(statementProtocol)->notifyCertificateAvailable(id);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::notifyCertificateAvailable(::java::lang::Object* id)
{ 
    notifyCertificateAvailable(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::writeCheckpoint() /* throws(IOException) */
{
    auto size = int32_t(0);
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    ;
    npc(callback)->storeCheckpoint(sob);
    updateLogTime();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Writing checkpoint ("_j)->append(npc(sob)->getWritten())
            ->append(u" bytes)"_j)->toString());

    npc(history)->appendEntry(EVT_CHECKPOINT, true, new ::java::nio::ByteBufferArray({npc(sob)->getByteBuffer()}));
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::doAuthPush()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Doing authenticator push"_j);

    npc(authPushProtocol)->push();
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::doMaintenance()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"Doing maintenance"_j);

    try {
        npc(authInStore)->garbageCollect();
        npc(authOutStore)->garbageCollect();
        npc(authPendingStore)->garbageCollect();
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::doCheckpoint()
{
    auto foo = npc(history)->getTopLevelEntry();
    auto topSeq = npc(foo)->getSeq();
    try {
        auto topIdx = npc(history)->findSeq(topSeq);
        if(npc(npc(history)->statEntry(topIdx))->getType() != EVT_CHECKPOINT) {
            writeCheckpoint();
        }
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(u"Error during checkpoint"_j, ioe);
    }
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::notifyStatusChange(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Status change: <"_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u"> becomes "_j)
            ->append(getStatusString(newStatus))->toString());

    npc(challengeProtocol)->notifyStatusChange(id, newStatus);
    npc(commitmentProtocol)->notifyStatusChange(id, newStatus);
    npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new PeerReviewImpl_notifyStatusChange_3(this, id, newStatus)), static_cast< int64_t >(int32_t(3)));
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), newStatus);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::init_(::java::lang::String* dirname) /* throws(IOException) */
{
    /* assert((callback != nullptr)) */ ;
    auto dir = new ::java::io::File(dirname);
    if(!npc(dir)->exists()) {
        if(!npc(dir)->mkdirs()) {
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Cannot open PeerReview directory: "_j)->append(npc(dir)->getAbsolutePath())->toString());
        }
    }
    if(!npc(dir)->isDirectory())
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Cannot open PeerReview directory: "_j)->append(npc(dir)->getAbsolutePath())->toString());

    auto namebuf = new ::java::io::File(dir, u"peers"_j);
    infoStore = new ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStoreImpl(transport, stringTranslator, authenticatorSerialilzer, evidenceSerializer, env);
    npc(infoStore)->setStatusChangeListener(this);
    auto newLogCreated = false;
    auto historyName = ::java::lang::StringBuilder().append(dirname)->append(u"/local"_j)->toString();
    this->history = npc(historyFactory)->open(historyName, u"w"_j);
    if(this->history == nullptr) {
        this->history = npc(historyFactory)->create(historyName, 0, npc(transport)->getEmptyHash());
        newLogCreated = true;
    }
    updateLogTime();
    if(!npc(infoStore)->setStorageDirectory(namebuf)) {
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Cannot open info storage directory '"_j)->append(static_cast< ::java::lang::Object* >(namebuf))
            ->append(u"'"_j)->toString());
    }
    authInStore = new ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl(this);
    npc(authInStore)->setFilename(new ::java::io::File(dir, u"authenticators.in"_j));
    authOutStore = new ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl(this);
    npc(authOutStore)->setFilename(new ::java::io::File(dir, u"authenticators.out"_j));
    authPendingStore = new ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl(this, true);
    npc(authPendingStore)->setFilename(new ::java::io::File(dir, u"authenticators.pending"_j));
    authCacheStore = new ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl(this, true);
    npc(authCacheStore)->setFilename(new ::java::io::File(dir, u"authenticators.cache"_j));
    this->evidenceTransferProtocol = new ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl(this, transport, infoStore);
    this->commitmentProtocol = new ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl(this, transport, infoStore, authOutStore, history, timeToleranceMillis);
    this->authPushProtocol = new ::org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl(this, authInStore, authOutStore, authPendingStore, transport, infoStore, evidenceTransferProtocol, env);
    this->auditProtocol = new ::org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl(this, history, infoStore, authInStore, transport, authOutStore, evidenceTransferProtocol, authCacheStore);
    this->challengeProtocol = new ::org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl(this, transport, infoStore, history, authOutStore, auditProtocol, commitmentProtocol);
    this->statementProtocol = new ::org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl(this, challengeProtocol, infoStore, transport);
    this->evidenceTool = new ::org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl(this, handleSerializer, idSerializer, npc(transport)->getHashSizeBytes(), npc(transport)->getSignatureSizeBytes());
    this->verifierFactory = new ::org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl(this);
    initialized = true;
    maintenanceTask = npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new PeerReviewImpl_init_4(this)), MAINTENANCE_INTERVAL_MILLIS, MAINTENANCE_INTERVAL_MILLIS);
    authPushTask = npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new PeerReviewImpl_init_5(this)), DEFAULT_AUTH_PUSH_INTERVAL_MILLIS, DEFAULT_AUTH_PUSH_INTERVAL_MILLIS);
    checkpointTask = npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new PeerReviewImpl_init_6(this)), newLogCreated ? static_cast< int64_t >(int32_t(1)) : DEFAULT_CHECKPOINT_INTERVAL_MILLIS, DEFAULT_CHECKPOINT_INTERVAL_MILLIS);
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(transport)->getLocalIdentifier()))->serialize(sob);
    npc(history)->appendEntry(EVT_INIT, true, new ::java::nio::ByteBufferArray({npc(sob)->getByteBuffer()}));
    npc(callback)->init_();
    writeCheckpoint();
}

org::mpisws::p2p::transport::peerreview::PeerReviewCallback* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getApp()
{
    return callback;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::openSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return npc(transport)->openSocket(i, deliverSocketToMe, options);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(callback)->incomingSocket(s);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::acceptMessages(bool b)
{
    npc(transport)->acceptMessages(b);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::acceptSockets(bool b)
{
    npc(transport)->acceptSockets(b);
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getLocalId()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(identifierExtractor)->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(transport)->getLocalIdentifier())));
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getLocalHandle()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(transport)->getLocalIdentifier());
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getLocalIdentifier()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(transport)->getLocalIdentifier());
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::destroy()
{
    npc(transport)->destroy();
}

org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getAuthenticatorSerializer()
{
    return authenticatorSerialilzer;
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getEnvironment()
{
    return env;
}

org::mpisws::p2p::transport::util::Serializer* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getIdSerializer()
{
    return idSerializer;
}

int64_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getTime()
{
    return npc(npc(env)->getTimeSource())->currentTimeMillis();
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::extractAuthenticator(int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature)
{
    auto hash = npc(transport)->hash(seq, entryType, hTopMinusOne, entryHash);
    auto ret = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(seq, hash, signature);
    return ret;
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::extractAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq, int16_t entryType, ::int8_tArray* entryHash, ::int8_tArray* hTopMinusOne, ::int8_tArray* signature)
{
    auto ret = extractAuthenticator(seq, entryType, entryHash, hTopMinusOne, signature);
    if(addAuthenticatorIfValid(authOutStore, id, ret)) {
        return ret;
    }
    return nullptr;
}

org::mpisws::p2p::transport::util::Serializer* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getHandleSerializer()
{
    return handleSerializer;
}

int32_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getHashSizeInBytes()
{
    return npc(transport)->getHashSizeBytes();
}

int32_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getSignatureSizeInBytes()
{
    return npc(transport)->getSignatureSizeBytes();
}

org::mpisws::p2p::transport::peerreview::IdentifierExtractor* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getIdentifierExtractor()
{
    return identifierExtractor;
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* handle)
{
    npc(challengeProtocol)->challengeSuspectedNode(handle);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::sendEvidenceToWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence)
{
    auto accusation = new ::org::mpisws::p2p::transport::peerreview::message::AccusationMessage(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(getLocalId()), subject, evidenceSeq, evidence);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Relaying evidence to <"_j)->append(static_cast< ::java::lang::Object* >(subject))
            ->append(u">'s witnesses"_j)->toString());

    npc(evidenceTransferProtocol)->sendMessageToWitnesses(subject, accusation, nullptr, nullptr);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::transmit(::rice::p2p::commonapi::rawserialization::RawSerializable* dest, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob)->writeByte(PeerReview::PEER_REVIEW_COMMIT);
        npc(sob)->writeByte(static_cast< int8_t >(npc(message)->getType()));
        npc(message)->serialize(sob);
        auto buf = npc(sob)->getByteBuffer();
        npc(transport)->sendMessage(dest, buf, deliverAckToMe, options);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Error serializing:"_j)->append(static_cast< ::java::lang::Object* >(message))->toString(), ioe);
    }
}

bool org::mpisws::p2p::transport::peerreview::PeerReviewImpl::hasCertificate(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    return npc(transport)->hasCertificate(id);
}

bool org::mpisws::p2p::transport::peerreview::PeerReviewImpl::hasCertificate(::java::lang::Object* id)
{ 
    return hasCertificate(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

int8_tArray* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::sign(::int8_tArray* bytes)
{
    return npc(transport)->sign(bytes);
}

int16_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getSignatureSizeBytes()
{
    return npc(transport)->getSignatureSizeBytes();
}

bool org::mpisws::p2p::transport::peerreview::PeerReviewImpl::verify(::rice::p2p::commonapi::rawserialization::RawSerializable* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth)
{
    auto signedHash = npc(transport)->hash(new ::java::nio::ByteBufferArray({npc(auth)->getPartToHashThenSign()}));
    auto result = npc(transport)->verify(id, signedHash, npc(auth)->getSignature());
    return result == SIGNATURE_OK;
}

int32_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::verify(::rice::p2p::commonapi::rawserialization::RawSerializable* id, ::int8_tArray* msg, ::int8_tArray* signature)
{
    return npc(transport)->verify(id, msg, signature);
}

int32_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::verify(::java::lang::Object* id, ::int8_tArray* msg, ::int8_tArray* signature)
{ 
    return verify(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), msg, signature);
}

int8_tArray* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getEmptyHash()
{
    return npc(transport)->getEmptyHash();
}

int16_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getHashSizeBytes()
{
    return npc(transport)->getHashSizeBytes();
}

int8_tArray* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash)
{
    return npc(transport)->hash(seq, type, nodeHash, contentHash);
}

int8_tArray* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::hash(::java::nio::ByteBufferArray*/*...*/ hashMe)
{
    return npc(transport)->hash(hashMe);
}

org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getEvidenceSerializer()
{
    return evidenceSerializer;
}

org::mpisws::p2p::transport::peerreview::audit::EvidenceTool* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getEvidenceTool()
{
    return evidenceTool;
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getHistoryFactory()
{
    return historyFactory;
}

org::mpisws::p2p::transport::peerreview::replay::VerifierFactory* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getVerifierFactory()
{
    return verifierFactory;
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::disableAuthenticatorProcessing()
{
    /* assert((initialized)) */ ;
    npc(maintenanceTask)->cancel();
    npc(authInStore)->disableMemoryBuffer();
    npc(authOutStore)->disableMemoryBuffer();
    npc(authPendingStore)->disableMemoryBuffer();
}

org::mpisws::p2p::transport::peerreview::history::SecureHistory* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getHistory()
{
    return history;
}

int64_t org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getTimeToleranceMillis()
{
    return timeToleranceMillis;
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl::sendEvidence(::rice::p2p::commonapi::rawserialization::RawSerializable* dest, ::rice::p2p::commonapi::rawserialization::RawSerializable* evidenceAgainst)
{
    npc(evidenceTransferProtocol)->sendEvidence(dest, evidenceAgainst);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.PeerReviewImpl", 50);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl::getClass0()
{
    return class_();
}

