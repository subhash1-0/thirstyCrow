// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/peerreview/IdentifierExtractor.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl_CommitmentProtocolImpl_1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocolImpl_initReceiveCache_2.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/PeerInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/ReceiveInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashSeq.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtAck.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtRecv.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSend.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtSign.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AckMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/OutgoingUserDataMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
#include <rice/selector/SelectorManager.hpp>
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

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::CommitmentProtocolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::CommitmentProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, AuthenticatorStore* authStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, int64_t timeToleranceMillis)  /* throws(IOException) */
    : CommitmentProtocolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,transport,infoStore,authStore,history,timeToleranceMillis);
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::init()
{
    MAX_PEERS = int32_t(250);
    INITIAL_TIMEOUT_MILLIS = int32_t(1000);
    RETRANSMIT_TIMEOUT_MILLIS = int32_t(1000);
    RECEIVE_CACHE_SIZE = int32_t(100);
    MAX_RETRANSMISSIONS = int32_t(2);
    TI_PROGRESS = int32_t(1);
    PROGRESS_INTERVAL_MILLIS = int32_t(1000);
    MAX_ENTRIES_PER_MS = int32_t(1000000);
    peer = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, AuthenticatorStore* authStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, int64_t timeToleranceMillis) /* throws(IOException) */
{
    super::ctor();
    init();
    this->peerreview = peerreview;
    this->transport = transport;
    this->infoStore = infoStore;
    this->authStore = authStore;
    this->history = history;
    this->nextReceiveCacheEntry = 0;
    this->timeToleranceMillis = timeToleranceMillis;
    this->logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(CommitmentProtocolImpl::class_(), nullptr);
    initReceiveCache();
    makeProgressTask = new CommitmentProtocolImpl_CommitmentProtocolImpl_1(this);
    npc(npc(npc(peerreview)->getEnvironment())->getSelectorManager())->schedule(makeProgressTask, static_cast< int64_t >(PROGRESS_INTERVAL_MILLIS), static_cast< int64_t >(PROGRESS_INTERVAL_MILLIS));
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::initReceiveCache() /* throws(IOException) */
{
    receiveCache = new CommitmentProtocolImpl_initReceiveCache_2(this, RECEIVE_CACHE_SIZE, 0.75f, true);
    for (auto i = npc(history)->getNumEntries() - int32_t(1); (i >= 1) && (npc(receiveCache)->size() < RECEIVE_CACHE_SIZE); i--) {
        auto hIndex = npc(history)->statEntry(i);
        if(npc(hIndex)->getType() == ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants::EVT_RECV) {
            auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(history)->getEntry(hIndex, npc(hIndex)->getSizeInFile()));
            auto thisSender = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdSerializer())->deserialize(sib));
            addToReceiveCache(thisSender, npc(sib)->readLong(), i);
        }
    }
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::addToReceiveCache(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t senderSeq, int64_t indexInLocalHistory)
{
    npc(receiveCache)->put(new ::rice::p2p::util::tuples::Tuple(id, ::java::lang::Long::valueOf(senderSeq)), new ReceiveInfo(id, senderSeq, indexInLocalHistory));
}

org::mpisws::p2p::transport::peerreview::commitment::PeerInfo* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::lookupPeer(::rice::p2p::commonapi::rawserialization::RawSerializable* handle)
{
    auto ret = java_cast< PeerInfo* >(npc(peer)->get(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(handle))));
    if(ret != nullptr)
        return ret;

    ret = new PeerInfo(handle);
    npc(peer)->put(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(handle)), ret);
    return ret;
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    makeProgress(id);
}

rice::p2p::util::tuples::Tuple* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::logMessageIfNew(::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* udm)
{
    try {
        bool loggedPreviously;
        int64_t seqOfRecvEntry;
        ::int8_tArray* myHashTop;
        ::int8_tArray* myHashTopMinusOne;
        auto indexOfRecvEntry = findRecvEntry(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle()))), npc(udm)->getTopSeq());
        if(indexOfRecvEntry < 0LL) {
            myHashTopMinusOne = npc(npc(history)->getTopLevelEntry())->getHash();
            auto recv = npc(udm)->getReceiveEvent(transport);
            npc(history)->appendEntry(EVT_RECV, true, new ::java::nio::ByteBufferArray({npc(recv)->serialize()}));
            auto foo = npc(history)->getTopLevelEntry();
            myHashTop = npc(foo)->getHash();
            seqOfRecvEntry = npc(foo)->getSeq();
            addToReceiveCache(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle()))), npc(udm)->getTopSeq(), npc(history)->getNumEntries() - int32_t(1));
            if(npc(logger)->level < ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"New message logged as seq#"_j)->append(seqOfRecvEntry)->toString());

            npc(history)->appendEntry(EVT_SIGN, true, new ::java::nio::ByteBufferArray({(new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSign(npc(udm)->getHTopMinusOne(), npc(udm)->getSignature()))->serialize()}));
            loggedPreviously = false;
        } else {
            loggedPreviously = true;
            auto i2 = npc(history)->statEntry(indexOfRecvEntry);
            auto i1 = npc(history)->statEntry(indexOfRecvEntry - int32_t(1));
            /* assert((i1 != nullptr && i2 != nullptr && npc(i2)->getType() == EVT_RECV) : ::java::lang::StringBuilder().append(u"i1:"_j)->append(static_cast< ::java::lang::Object* >(i1))
                ->append(u" i2:"_j)
                ->append(static_cast< ::java::lang::Object* >(i2))->toString()) */ ;
            seqOfRecvEntry = npc(i2)->getSeq();
            myHashTop = npc(i2)->getNodeHash();
            myHashTopMinusOne = npc(i1)->getNodeHash();
            if(npc(logger)->level < ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"This message has already been logged as seq#"_j)->append(seqOfRecvEntry)->toString());

        }
        auto hToSign = npc(transport)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(::rice::p2p::util::MathUtils::longToByteArray_(seqOfRecvEntry)), ::java::nio::ByteBuffer::wrap(myHashTop)}));
        auto ack = new ::org::mpisws::p2p::transport::peerreview::message::AckMessage(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()), npc(udm)->getTopSeq(), seqOfRecvEntry, myHashTopMinusOne, npc(transport)->sign(hToSign));
        return new ::rice::p2p::util::tuples::Tuple(ack, ::java::lang::Boolean::valueOf(loggedPreviously));
    } catch (::java::io::IOException* ioe) {
        auto throwMe = new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Unexpect error logging message :"_j)->append(static_cast< ::java::lang::Object* >(udm))->toString());
        npc(throwMe)->initCause(ioe);
        throw throwMe;
    }
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::notifyStatusChange(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus)
{
    makeProgressAllPeers();
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), newStatus);
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::makeProgressAllPeers()
{
    for (auto _i = npc(npc(peer)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::rawserialization::RawSerializable* i = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(_i->next());
        {
            makeProgress(i);
        }
    }
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::makeProgress(::rice::p2p::commonapi::rawserialization::RawSerializable* idx)
{
    auto info = java_cast< PeerInfo* >(npc(peer)->get(idx));
    if(info == nullptr || (npc(npc(info)->xmitQueue)->isEmpty() && npc(npc(info)->recvQueue)->isEmpty())) {
        return;
    }
    if(!npc(transport)->hasCertificate(idx)) {
        npc(peerreview)->requestCertificate(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle), idx);
        return;
    }
    if(!npc(npc(info)->xmitQueue)->isEmpty()) {
        auto status = npc(infoStore)->getStatus(idx);
        switch (status) {
        case STATUS_EXPOSED:
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Releasing messages sent to exposed node "_j)->append(static_cast< ::java::lang::Object* >(idx))->toString());

            npc(info)->clearXmitQueue();
            return;
        case STATUS_SUSPECTED:
            if(npc(info)->lastChallenge < (npc(peerreview)->getTime() - npc(info)->currentChallengeInterval)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Pending message for SUSPECTED node "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->getHandle())))
                        ->append(u"; challenging node (interval="_j)
                        ->append(npc(info)->currentChallengeInterval)
                        ->append(u")"_j)->toString());

                npc(info)->lastChallenge = npc(peerreview)->getTime();
                npc(info)->currentChallengeInterval *= 2;
                npc(peerreview)->challengeSuspectedNode(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle));
            }
            return;
        case STATUS_TRUSTED:
            npc(info)->lastChallenge = -int32_t(1);
            npc(info)->currentChallengeInterval = PeerInfo::INITIAL_CHALLENGE_INTERVAL_MICROS;
            break;
        }

        if(npc(info)->numOutstandingPackets == 0) {
            npc(info)->numOutstandingPackets++;
            npc(info)->lastTransmit = npc(peerreview)->getTime();
            npc(info)->currentTimeout = INITIAL_TIMEOUT_MILLIS;
            npc(info)->retransmitsSoFar = 0;
            auto oudm = java_cast< ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage* >(npc(npc(info)->xmitQueue)->getFirst());
            npc(peerreview)->transmit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->getHandle()), oudm, nullptr, npc(oudm)->getOptions());
        } else if(npc(peerreview)->getTime() > (npc(info)->lastTransmit + npc(info)->currentTimeout)) {
            if(npc(info)->retransmitsSoFar < MAX_RETRANSMISSIONS) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Retransmitting a "_j)->append(npc(npc(java_cast< ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage* >(npc(npc(info)->xmitQueue)->getFirst()))->getPayload())->remaining())
                        ->append(u"-byte message to "_j)
                        ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->getHandle())))
                        ->append(u" (lastxmit="_j)
                        ->append(npc(info)->lastTransmit)
                        ->append(u", timeout="_j)
                        ->append(npc(info)->currentTimeout)
                        ->append(u", type="_j)
                        ->append(npc(java_cast< ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage* >(npc(npc(info)->xmitQueue)->getFirst()))->getType())
                        ->append(u")"_j)->toString());

                npc(info)->retransmitsSoFar++;
                npc(info)->currentTimeout = RETRANSMIT_TIMEOUT_MILLIS;
                npc(info)->lastTransmit = npc(peerreview)->getTime();
                auto oudm = java_cast< ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage* >(npc(npc(info)->xmitQueue)->getFirst());
                npc(peerreview)->transmit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle), oudm, nullptr, npc(oudm)->getOptions());
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle)))->append(u" has not acknowledged our message after "_j)
                        ->append(npc(info)->retransmitsSoFar)
                        ->append(u" retransmissions; filing as evidence"_j)->toString());

                auto challenge = java_cast< ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage* >(npc(npc(info)->xmitQueue)->removeFirst());
                npc(challenge)->sendFailed(new ::java::io::IOException(::java::lang::StringBuilder().append(u"Peer Review Giving Up sending message to "_j)->append(static_cast< ::java::lang::Object* >(idx))->toString()));
                auto evidenceSeq = npc(peerreview)->getEvidenceSeq();
                try {
                    npc(infoStore)->addEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle))), evidenceSeq, challenge, nullptr);
                } catch (::java::io::IOException* ioe) {
                    throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
                }
                npc(peerreview)->sendEvidenceToWitnesses(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle))), evidenceSeq, challenge);
                npc(info)->numOutstandingPackets--;
            }
        }
    }
    if(!npc(npc(info)->recvQueue)->isEmpty() && !npc(info)->isReceiving_) {
        npc(info)->isReceiving_ = true;
        auto t = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(npc(info)->recvQueue)->removeFirst());
        auto udm = java_cast< ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* >(npc(t)->a());
        Authenticator* authenticator;
        auto innerHash = npc(udm)->getInnerHash(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId())), static_cast< ::org::mpisws::p2p::transport::peerreview::history::HashProvider* >(transport));
        authenticator = npc(peerreview)->extractAuthenticator(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle()))), npc(udm)->getTopSeq(), EVT_SEND, innerHash, npc(udm)->getHTopMinusOne(), npc(udm)->getSignature());
        if(authenticator != nullptr) {
            auto ret = logMessageIfNew(udm);
            if(!(npc(java_cast< ::java::lang::Boolean* >(npc(ret)->b())))->booleanValue()) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Delivering message from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle())))
                        ->append(u" via "_j)
                        ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle)))
                        ->append(u" ("_j)
                        ->append(npc(udm)->getPayloadLen())
                        ->append(u" bytes; "_j)
                        ->append(npc(udm)->getRelevantLen())
                        ->append(u"/"_j)
                        ->append(npc(udm)->getPayloadLen())
                        ->append(u" relevant)"_j)->toString());

                try {
                    npc(npc(peerreview)->getApp())->messageReceived(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle()), npc(udm)->getPayload(), java_cast< ::java::util::Map* >(npc(t)->b()));
                } catch (::java::io::IOException* ioe) {
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"Error handling "_j)->append(static_cast< ::java::lang::Object* >(udm))->toString(), ioe);
                }
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Message from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle())))
                        ->append(u" via "_j)
                        ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->getHandle())))
                        ->append(u" was previously logged; not delivered"_j)->toString());

            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Returning ACK to"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->getHandle())))->toString());

            npc(peerreview)->transmit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->handle), java_cast< ::org::mpisws::p2p::transport::peerreview::message::AckMessage* >(npc(ret)->a()), nullptr, java_cast< ::java::util::Map* >(npc(t)->b()));
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot verify signature on message "_j)->append(npc(udm)->getTopSeq())
                    ->append(u" from "_j)
                    ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(info)->getHandle())))
                    ->append(u"; discarding"_j)->toString());

        }
        npc(info)->isReceiving_ = false;
        makeProgress(idx);
    }
}

int64_t org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::findRecvEntry(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq)
{
    auto ret = java_cast< ReceiveInfo* >(npc(receiveCache)->get(new ::rice::p2p::util::tuples::Tuple(id, ::java::lang::Long::valueOf(seq))));
    if(ret == nullptr)
        return -int32_t(1);

    return npc(ret)->indexInLocalHistory;
}

int64_t org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::findAckEntry(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq)
{
    return -int32_t(1);
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::handleIncomingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* msg, ::java::util::Map* options) /* throws(IOException) */
{
    auto txmit = (npc(msg)->getTopSeq() / MAX_ENTRIES_PER_MS);
    if((txmit < (npc(peerreview)->getTime() - timeToleranceMillis)) || (txmit > (npc(peerreview)->getTime() + timeToleranceMillis))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Invalid sequence no #"_j)->append(npc(msg)->getTopSeq())
                ->append(u" on incoming message (dt="_j)
                ->append((txmit - npc(peerreview)->getTime()))
                ->append(u"); discarding"_j)->toString());

        return;
    }
    npc(java_cast< ::java::util::LinkedList* >(npc(lookupPeer(source))->recvQueue))->addLast(static_cast< ::java::lang::Object* >(new ::rice::p2p::util::tuples::Tuple(msg, options)));
    makeProgress(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(source)));
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::handleOutgoingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    auto relevantlen = npc(message)->remaining();
    if(options != nullptr && npc(options)->containsKey(::org::mpisws::p2p::transport::peerreview::PeerReview::RELEVANT_LENGTH())) {
        auto n = java_cast< ::java::lang::Number* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::peerreview::PeerReview::RELEVANT_LENGTH())));
        relevantlen = npc(n)->intValue();
    }
    /* assert((relevantlen >= 0)) */ ;
    ::int8_tArray* hTopMinusOne;
    ::int8_tArray* hTop;
    ::int8_tArray* hToSign;
    hTopMinusOne = npc(npc(history)->getTopLevelEntry())->getHash();
    ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend* evtSend;
    if(relevantlen < npc(message)->remaining()) {
        evtSend = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(target)), message, relevantlen, transport);
    } else {
        evtSend = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(target)), message);
    }
    try {
        npc(history)->appendEntry(npc(evtSend)->getType(), true, new ::java::nio::ByteBufferArray({npc(evtSend)->serialize()}));
    } catch (::java::io::IOException* ioe) {
        ::org::mpisws::p2p::transport::MessageRequestHandle* ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(target, message, options);
        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->sendFailed(ret, ioe);

        return ret;
    }
    auto top = npc(history)->getTopLevelEntry();
    hToSign = npc(transport)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(::rice::p2p::util::MathUtils::longToByteArray_(npc(top)->getSeq())), ::java::nio::ByteBuffer::wrap(npc(top)->getHash())}));
    auto signature = npc(transport)->sign(hToSign);
    auto relevantMsg = message;
    if(relevantlen < npc(message)->remaining()) {
        relevantMsg = ::java::nio::ByteBuffer::wrap(npc(message)->array(), npc(message)->position(), relevantlen);
    } else {
        relevantMsg = ::java::nio::ByteBuffer::wrap(npc(message)->array(), npc(message)->position(), npc(message)->remaining());
    }
    try {
        npc(history)->appendEntry(EVT_SENDSIGN, true, new ::java::nio::ByteBufferArray({relevantMsg, ::java::nio::ByteBuffer::wrap(signature)}));
    } catch (::java::io::IOException* ioe) {
        ::org::mpisws::p2p::transport::MessageRequestHandle* ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(target, message, options);
        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->sendFailed(ret, ioe);

        return ret;
    }
    /* assert(((relevantlen == npc(message)->remaining()) || (relevantlen < 255))) */ ;
    auto pi = lookupPeer(target);
    auto udm = new ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage(npc(top)->getSeq(), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalHandle()), hTopMinusOne, signature, message, relevantlen, options, pi, deliverAckToMe);
    npc(npc(pi)->xmitQueue)->addLast(static_cast< ::java::lang::Object* >(udm));
    makeProgress(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(target)));
    return udm;
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::handleIncomingAck(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::AckMessage* ackMessage, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Received an ACK from "_j)->append(static_cast< ::java::lang::Object* >(source))->toString());

    if(npc(transport)->hasCertificate(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId()))) {
        auto p = lookupPeer(source);
        auto checkAck = true;
        ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage* udm = nullptr;
        if(npc(npc(p)->xmitQueue)->isEmpty()) {
            checkAck = false;
        } else {
            udm = java_cast< ::org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage* >(npc(npc(p)->xmitQueue)->getFirst());
        }
        if(checkAck && npc(ackMessage)->getSendEntrySeq() == npc(udm)->getTopSeq()) {
            auto innerHash = npc(udm)->getInnerHash(transport);
            auto authenticator = npc(peerreview)->extractAuthenticator(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId()), npc(ackMessage)->getRecvEntrySeq(), EVT_RECV, innerHash, npc(ackMessage)->getHashTopMinusOne(), npc(ackMessage)->getSignature());
            if(authenticator != nullptr) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"ACK is okay; logging "_j)->append(static_cast< ::java::lang::Object* >(ackMessage))->toString());

                auto evtAck = new ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId()), npc(ackMessage)->getSendEntrySeq(), npc(ackMessage)->getRecvEntrySeq(), npc(ackMessage)->getHashTopMinusOne(), npc(ackMessage)->getSignature());
                npc(history)->appendEntry(EVT_ACK, true, new ::java::nio::ByteBufferArray({npc(evtAck)->serialize()}));
                npc(udm)->sendComplete();
                npc(npc(p)->xmitQueue)->removeFirst();
                npc(p)->numOutstandingPackets--;
                makeProgress(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(p)->getHandle()))));
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Invalid ACK from <"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId())))
                        ->append(u">; discarding"_j)->toString());

            }
        } else {
            if(findAckEntry(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId()), npc(ackMessage)->getSendEntrySeq()) < 0) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"<"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId())))
                        ->append(u"> has ACKed something we haven't sent ("_j)
                        ->append(npc(ackMessage)->getSendEntrySeq())
                        ->append(u"); discarding"_j)->toString());

            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Duplicate ACK from <"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId())))
                        ->append(u">; discarding"_j)->toString());

            }
        }
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"We got an ACK from <"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ackMessage)->getNodeId())))
                ->append(u">, but we don't have the certificate; discarding"_j)->toString());

    }
}

void org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::setTimeToleranceMillis(int64_t timeToleranceMillis)
{
    this->timeToleranceMillis = timeToleranceMillis;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.commitment.CommitmentProtocolImpl", 69);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocolImpl::getClass0()
{
    return class_();
}

