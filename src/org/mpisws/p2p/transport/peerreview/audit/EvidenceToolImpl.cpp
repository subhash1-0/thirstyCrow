// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl.java
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/IdentifierExtractor.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl_SendEntryRecord.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtAck.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtInit.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtRecv.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSend.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSendSign.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSign.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
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

org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl::EvidenceToolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl::EvidenceToolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize) 
    : EvidenceToolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,handleSerializer,idSerializer,hashSize,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize)
{
    super::ctor();
    this->peerreview = peerreview;
    this->logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(EvidenceToolImpl::class_(), nullptr);
    this->handleSerializer = handleSerializer;
    this->idSerializer = idSerializer;
    this->hashSize = hashSize;
    this->signatureSize = signatureSize;
}

rice::p2p::util::tuples::Tuple* org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl::checkSnippet(LogSnippet* snippet)
{
    for (auto _i = npc(npc(snippet)->entries)->iterator(); _i->hasNext(); ) {
        SnippetEntry* entry = java_cast< SnippetEntry* >(_i->next());
        {
            if(npc(entry)->isHash && npc(entry)->type != EVT_CHECKPOINT && npc(entry)->type != EVT_SENDSIGN && npc(entry)->type != EVT_SEND) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Malformed statement: Entry of type #"_j)->append(npc(entry)->type)
                        ->append(u" is hashed"_j)->toString());

                return new ::rice::p2p::util::tuples::Tuple(::java::lang::Integer::valueOf(INVALID), nullptr);
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Entry type "_j)->append(npc(entry)->type)
                    ->append(u", size="_j)
                    ->append(npc(npc(entry)->content)->length)
                    ->append(u" "_j)
                    ->append((npc(entry)->isHash ? u" (hashed)"_j : u""_j))->toString());

            try {
                auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(entry)->content);
                {
                    ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck* evtAck;
                    ::rice::p2p::commonapi::rawserialization::RawSerializable* id;
                    switch (npc(entry)->type) {
                    case EVT_SEND:
                        if(!npc(entry)->isHash) {
                            new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend(sib, idSerializer, hashSize);
                        }
                        break;
                    case EVT_RECV: {
                            auto recv = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(sib), static_cast< ::org::mpisws::p2p::transport::util::Serializer* >(handleSerializer), hashSize);
                            auto id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(recv)->getSenderHandle())));
                            if(!npc(peerreview)->hasCertificate(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id))) {
                                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                    npc(logger)->log(::java::lang::StringBuilder().append(u"AUDIT RESPONSE contains RECV from "_j)->append(static_cast< ::java::lang::Object* >(id))
                                        ->append(u"; certificate needed"_j)->toString());

                                return new ::rice::p2p::util::tuples::Tuple(::java::lang::Integer::valueOf(CERT_MISSING), id);
                            }
                            break;
                        }
                    case EVT_SIGN:
                        new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign(sib, signatureSize, hashSize);
                        break;
                    case EVT_ACK:
                        evtAck = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck(sib, idSerializer, hashSize, signatureSize);
                        id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evtAck)->getRemoteId());
                        if(!npc(peerreview)->hasCertificate(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id))) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"AUDIT RESPONSE contains RECV from "_j)->append(static_cast< ::java::lang::Object* >(id))
                                    ->append(u"; certificate needed"_j)->toString());

                            return new ::rice::p2p::util::tuples::Tuple(::java::lang::Integer::valueOf(CERT_MISSING), id);
                        }
                        break;
                    case EVT_CHECKPOINT:
                    case EVT_VRF:
                    case EVT_CHOOSE_Q:
                    case EVT_CHOOSE_RAND:
                        break;
                    case EVT_INIT: {
                            new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit(sib, handleSerializer);
                            break;
                        }
                    case EVT_SENDSIGN:
                        break;
                    default:
                        /* assert((npc(entry)->type > EVT_MAX_RESERVED)) */ ;
                        break;
                    }
                }

            } catch (::java::io::IOException* ioe) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"Malformed entry:"_j)->append(static_cast< ::java::lang::Object* >(entry))->toString(), ioe);

                return new ::rice::p2p::util::tuples::Tuple(::java::lang::Integer::valueOf(INVALID), nullptr);
            }
        }
    }
    return new ::rice::p2p::util::tuples::Tuple(::java::lang::Integer::valueOf(VALID), nullptr);
}

bool org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl::checkSnippetSignatures(LogSnippet* snippet, ::rice::p2p::commonapi::rawserialization::RawSerializable* subjectHandle, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authStoreOrNull, int8_t flags, ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol, ::int8_tArray* keyNodeHash, int64_t keyNodeMaxSeq)
{
    auto startWithCheckpoint = (flags & FLAG_INCLUDE_CHECKPOINT) == FLAG_INCLUDE_CHECKPOINT;
    auto currentNodeHash = npc(snippet)->baseHash;
    ::int8_tArray* prevNodeHash = nullptr;
    ::int8_tArray* prevPrevNodeHash = nullptr;
    auto firstEntry = true;
    auto keyNodeFound = false;
    SnippetEntry* lastEntry = nullptr;
    auto seqBuf = new ::java::util::HashSet();
    auto numSeqs = int32_t(0);
    try {
        if((commitmentProtocol != nullptr) && (flags & FLAG_FULL_MESSAGES_SENDER) == FLAG_FULL_MESSAGES_SENDER) {
            /* assert((peerreview != nullptr)) */ ;
            auto history = npc(peerreview)->getHistory();
            for (auto i = npc(history)->getNumEntries() - int32_t(1); i >= 1; i--) {
                auto entry = npc(history)->statEntry(i);
                auto type = npc(entry)->getType();
                if(npc(entry)->getSeq() < (npc(snippet)->getFirstSeq() - npc(peerreview)->getTimeToleranceMillis() * int32_t(1000000)))
                    break;

                if(type == EVT_RECV) {
                    auto evtBytes = npc(history)->getEntry(entry, npc(entry)->getSizeInFile());
                    auto evtRecv = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(evtBytes)), static_cast< ::org::mpisws::p2p::transport::util::Serializer* >(handleSerializer), hashSize);
                    auto thisSender = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evtRecv)->getSenderHandle());
                    if(npc(thisSender)->equals(subjectHandle)) {
                        npc(seqBuf)->add(::java::lang::Long::valueOf(npc(evtRecv)->getSenderSeq()));
                    }
                }
            }
        }
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
    ::java::util::Map* secache = new ::java::util::HashMap();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Checking snippet (flags="_j)->append(flags)
            ->append(u")"_j)->toString());

    for (auto _i = npc(npc(snippet)->entries)->iterator(); _i->hasNext(); ) {
        SnippetEntry* entry = java_cast< SnippetEntry* >(_i->next());
        {
            if(!firstEntry) {
                if(npc(entry)->seq <= npc(lastEntry)->seq) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Log snippet attempts to roll back the sequence number from "_j)->append(npc(lastEntry)->seq)
                            ->append(u" to "_j)
                            ->append(npc(entry)->seq)
                            ->append(u"; flagging invalid"_j)->toString());

                    return false;
                }
                if(keyNodeHash != nullptr && !keyNodeFound && (npc(entry)->seq > keyNodeMaxSeq)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Hash of keyNode does not appear in ["_j)->append(npc(snippet)->getFirstSeq())
                            ->append(u","_j)
                            ->append(keyNodeMaxSeq)
                            ->append(u"]; flagging invalid"_j)->toString());

                    return false;
                }
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Entry type "_j)->append(npc(entry)->type)
                    ->append(u", size="_j)
                    ->append(npc(npc(entry)->content)->length)
                    ->append(u", seq="_j)
                    ->append(npc(entry)->seq)
                    ->append(u" "_j)
                    ->append((npc(entry)->isHash ? u" (hashed)"_j : u""_j))->toString());

            if(lastEntry != nullptr && (npc(lastEntry)->type == EVT_RECV) && ((npc(entry)->type != EVT_SIGN) || (npc(entry)->seq != (npc(lastEntry)->seq + int32_t(1))))) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Log snipped omits the mandatory EVT_SIGN after an EVT_RECV; flagging invalid"_j);

                return false;
            }
            prevPrevNodeHash = prevNodeHash;
            prevNodeHash = currentNodeHash;
            ::int8_tArray* contentHash;
            ;
            if(npc(entry)->isHash) {
                contentHash = npc(entry)->content;
            } else {
                contentHash = npc(peerreview)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(npc(entry)->content)}));
            }
            currentNodeHash = npc(peerreview)->hash(npc(entry)->seq, npc(entry)->type, currentNodeHash, contentHash);
            try {
                auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(entry)->content);
                switch (npc(entry)->type) {
                case EVT_SEND:
                    if(!npc(entry)->isHash) {
                        npc(idSerializer)->deserialize(sib);
                        npc(secache)->put(::java::lang::Long::valueOf(npc(entry)->seq), new EvidenceToolImpl_SendEntryRecord(npc(entry)->seq, ::java::nio::ByteBuffer::wrap(npc(entry)->content, npc(npc(entry)->content)->length - npc(sib)->bytesRemaining(), npc(sib)->bytesRemaining())));
                    }
                    break;
                case EVT_RECV:
                    break;
                case EVT_SENDSIGN:
                    if(!npc(entry)->isHash) {
                        /* assert((npc(npc(entry)->content)->length >= signatureSize)) */ ;
                        if(!firstEntry) {
                            if(npc(lastEntry)->type != EVT_SEND) {
                                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                    npc(logger)->log(u"Spurious EVT_SENDSIGN in snippet; flagging invalid"_j);

                                return false;
                            }
                            auto evtSendSign = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSendSign(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(sib), signatureSize);
                            auto sendWasHashed = npc(lastEntry)->isHash;
                            if(sendWasHashed) {
                                auto actualHash = npc(peerreview)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(npc(evtSendSign)->restOfMessage)}));
                                if(!::java::util::Arrays::equals(npc(lastEntry)->content, actualHash)) {
                                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                        npc(logger)->log(u"EVT_SENDSIGN content does not match hash in EVT_SEND"_j);

                                    return false;
                                }
                            } else {
                                if(npc(npc(entry)->content)->length > signatureSize) {
                                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                        npc(logger)->log(u"EVT_SENDSIGN contains extra bytes, but preceding EVT_SEND was not hashed"_j);

                                    return false;
                                }
                            }
                            auto authPrefix = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
                            npc(authPrefix)->writeLong(npc(lastEntry)->seq);
                            npc(authPrefix)->write(prevNodeHash);
                            auto signedHash = npc(peerreview)->hash(new ::java::nio::ByteBufferArray({npc(authPrefix)->getByteBuffer()}));
                            auto verifyResult = npc(peerreview)->verify(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(subjectHandle)), signedHash, npc(evtSendSign)->signature);
                            /* assert(((verifyResult == SIGNATURE_OK) || (verifyResult == SIGNATURE_BAD))) */ ;
                            if(verifyResult != SIGNATURE_OK) {
                                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                    npc(logger)->log(u"Signature in EVT_SENDSIGN does not match node hash of EVT_SEND"_j);

                                return false;
                            }
                            if(commitmentProtocol != nullptr && (flags & FLAG_FULL_MESSAGES_SENDER) == FLAG_FULL_MESSAGES_SENDER) {
                                /* assert((!sendWasHashed)) */ ;
                                auto evtSend = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(lastEntry)->content), idSerializer, hashSize);
                                auto dest = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evtSend)->receiverId);
                                if(npc(dest)->equals(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()))) {
                                    auto previouslyReceived = false;
                                    if(npc(seqBuf)->contains(::java::lang::Long::valueOf(npc(lastEntry)->seq))) {
                                        previouslyReceived = true;
                                    }
                                    if(!previouslyReceived) {
                                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                                            npc(logger)->log(::java::lang::StringBuilder().append(u"XXX accepting new message "_j)->append(npc(lastEntry)->seq)->toString());

                                        auto msg = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
                                        npc(msg)->write(npc(npc(evtSend)->payload)->array(), npc(npc(evtSend)->payload)->position(), npc(npc(evtSend)->payload)->remaining());
                                        npc(msg)->write(npc(evtSendSign)->restOfMessage);
                                        auto message = new ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage(npc(lastEntry)->seq, subjectHandle, prevPrevNodeHash, npc(evtSendSign)->signature, npc(msg)->getByteBuffer(), npc(npc(evtSend)->payload)->remaining());
                                        npc(commitmentProtocol)->handleIncomingMessage(subjectHandle, message, nullptr);
                                    }
                                }
                            }
                        }
                    }
                    break;
                case EVT_SIGN:
                    /* assert((npc(npc(entry)->content)->length == (hashSize + signatureSize))) */ ;
                    if(!firstEntry) {
                        if(npc(lastEntry)->type != EVT_RECV) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(u"Spurious EVT_SIGN in snippet; flagging invalid"_j);

                            return false;
                        }
                        auto evtSign = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign(sib, hashSize, signatureSize);
                        auto evtRecv = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(lastEntry)->content)), static_cast< ::org::mpisws::p2p::transport::util::Serializer* >(handleSerializer), hashSize);
                        auto senderHandle = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evtRecv)->getSenderHandle());
                        auto senderSeq = npc(evtRecv)->getSenderSeq();
                        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
                        auto senderId = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(senderHandle));
                        auto subjectId = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(subjectHandle));
                        npc(subjectId)->serialize(sob);
                        npc(sob)->writeBoolean(npc(evtRecv)->getHash() != nullptr);
                        npc(sob)->write(npc(evtRecv)->getPayload());
                        if(npc(evtRecv)->getHash() != nullptr)
                            npc(sob)->write(npc(evtRecv)->getHash());

                        auto senderContentHash = npc(peerreview)->hash(new ::java::nio::ByteBufferArray({npc(sob)->getByteBuffer()}));
                        auto senderAuth = npc(peerreview)->extractAuthenticator(senderSeq, EVT_SEND, senderContentHash, npc(evtSign)->hTopMinusOne, npc(evtSign)->signature);
                        auto isGoodAuth = npc(peerreview)->addAuthenticatorIfValid(authStoreOrNull, senderId, senderAuth);
                        if(!isGoodAuth) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Snippet contains a RECV from "_j)->append(static_cast< ::java::lang::Object* >(senderHandle))
                                    ->append(u" whose signature does not match; flagging invalid"_j)->toString());

                            return false;
                        }
                    }
                    break;
                case EVT_ACK: {
                        auto evtAck = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck(sib, idSerializer, hashSize, signatureSize);
                        auto seidx = java_cast< EvidenceToolImpl_SendEntryRecord* >(npc(secache)->get(::java::lang::Long::valueOf(npc(evtAck)->getAckedSeq())));
                        if(seidx == nullptr) {
                        } else {
                            npc(secache)->remove(::java::lang::Long::valueOf(npc(evtAck)->getAckedSeq()));
                            auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
                            npc(subjectHandle)->serialize(sob);
                            npc(sob)->writeLong(npc(evtAck)->getAckedSeq());
                            auto receiverContentHash = npc(peerreview)->hash(new ::java::nio::ByteBufferArray({npc(sob)->getByteBuffer(), npc(seidx)->hashedPlusPayload}));
                            auto h = npc(peerreview)->hash(npc(evtAck)->getHisSeq(), EVT_RECV, npc(evtAck)->getHTopMinusOne(), receiverContentHash);
                            auto receiverAuth = new ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator(npc(evtAck)->getHisSeq(), h, npc(evtAck)->getSignature());
                            auto isGoodAuth = npc(peerreview)->addAuthenticatorIfValid(authStoreOrNull, java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evtAck)->getRemoteId()), receiverAuth);
                            if(!isGoodAuth) {
                                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                    npc(logger)->log(::java::lang::StringBuilder().append(u"Snippet contains an ACK from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evtAck)->getRemoteId())))
                                        ->append(u" whose signature does not match; flagging invalid"_j)->toString());

                                return false;
                            }
                        }
                        break;
                    }
                case EVT_CHECKPOINT:
                case EVT_VRF:
                case EVT_INIT:
                case EVT_CHOOSE_Q:
                case EVT_CHOOSE_RAND:
                    break;
                default:
                    /* assert((npc(entry)->type > EVT_MAX_RESERVED)) */ ;
                    break;
                }

            } catch (::java::io::IOException* ioe) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"Error verifying SnippitEntry "_j)->append(static_cast< ::java::lang::Object* >(entry))->toString(), ioe);

                return false;
            }
            lastEntry = entry;
            if(keyNodeHash != nullptr && !keyNodeFound) {
                if(::java::util::Arrays::equals(currentNodeHash, keyNodeHash)) {
                    keyNodeFound = true;
                }
            }
            if(firstEntry) {
                if(startWithCheckpoint) {
                    if((npc(entry)->type != EVT_CHECKPOINT) && (npc(entry)->type != EVT_INIT)) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(u"Previous checkpoint requested, but not included; flagging invalid"_j);

                        return false;
                    }
                    if(npc(entry)->isHash) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(u"Previous checkpoint requested, but only hash is included; flagging invalid"_j);

                        return false;
                    }
                } else {
                }
                firstEntry = false;
            }
        }
    }
    if(npc(lastEntry)->type == EVT_RECV) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Log snippet ends with a RECV event; missing mandatory SIGN"_j);

        return false;
    }
    if(npc(lastEntry)->type == EVT_SEND) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Log snippet ends with a SEND event; missing mandatory SENDSIGN"_j);

        return false;
    }
    if(keyNodeHash != nullptr && !keyNodeFound) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Key node not found in log snippet; flagging invalid"_j);

        return false;
    }
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.audit.EvidenceToolImpl", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl::getClass0()
{
    return class_();
}

