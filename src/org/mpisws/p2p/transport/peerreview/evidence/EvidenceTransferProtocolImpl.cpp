// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl_CacheInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl_MessageInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocolImpl_QueryInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceRecord.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AccusationMessage.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

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

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::EvidenceTransferProtocolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::EvidenceTransferProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore) 
    : EvidenceTransferProtocolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,transport,infoStore);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::init()
{
    witnessCache = new ::java::util::HashMap();
    pendingMessage = new ::java::util::HashMap();
    pendingQuery = new ::java::util::HashSet();
}

constexpr int32_t org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::MAX_CACHE_ENTRIES;

constexpr int32_t org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::MAX_PENDING_MESSAGES;

constexpr int32_t org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::MAX_PENDING_QUERIES;

constexpr int32_t org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::WITNESS_SET_VALID_MICROS;

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore)
{
    super::ctor();
    init();
    this->peerreview = peerreview;
    this->transport = transport;
    this->infoStore = infoStore;
    logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(EvidenceTransferProtocolImpl::class_(), nullptr);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::notifyWitnessSet(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::java::util::Collection* witnesses)
{
    auto idx = java_cast< EvidenceTransferProtocolImpl_CacheInfo* >(npc(witnessCache)->get(subject));
    if(idx == nullptr) {
        idx = new EvidenceTransferProtocolImpl_CacheInfo(this, subject);
        npc(witnessCache)->put(subject, idx);
    }
    npc(idx)->updateWitnesses(witnesses);
    ::java::util::Collection* sendMe = java_cast< ::java::util::LinkedList* >(npc(pendingMessage)->remove(subject));
    if(sendMe != nullptr) {
        for (auto _i = npc(sendMe)->iterator(); _i->hasNext(); ) {
            EvidenceTransferProtocolImpl_MessageInfo* m = java_cast< EvidenceTransferProtocolImpl_MessageInfo* >(_i->next());
            {
                doSendMessageToWitnesses(npc(idx)->witness, m);
            }
        }
    }
    for (auto _i = npc(pendingQuery)->iterator(); _i->hasNext(); ) {
        EvidenceTransferProtocolImpl_QueryInfo* qi = java_cast< EvidenceTransferProtocolImpl_QueryInfo* >(_i->next());
        {
            npc(qi)->updateWitnesses(idx);
        }
    }
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::notifyWitnessSet(::java::lang::Object* subject, ::java::util::Collection* witnesses)
{ 
    notifyWitnessSet(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject), dynamic_cast< ::java::util::Collection* >(witnesses));
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::doSendMessageToWitnesses(::java::util::Collection* witnesses, EvidenceTransferProtocolImpl_MessageInfo* m)
{
    for (auto _i = npc(witnesses)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::rawserialization::RawSerializable* h = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(_i->next());
        {
            npc(peerreview)->transmit(h, npc(m)->message, npc(m)->deliverAckToMe, npc(m)->options);
        }
    }
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::sendMessageToWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    auto m = new EvidenceTransferProtocolImpl_MessageInfo(this, subject, message, deliverAckToMe, options);
    auto witnesses = getWitnesses(subject);
    if(witnesses == nullptr) {
        auto foo = java_cast< ::java::util::LinkedList* >(npc(pendingMessage)->get(subject));
        if(foo == nullptr) {
            foo = new ::java::util::LinkedList();
            npc(pendingMessage)->put(subject, foo);
        }
        npc(foo)->addLast(static_cast< ::java::lang::Object* >(m));
        requestWitnesses(subject);
    } else {
        doSendMessageToWitnesses(witnesses, m);
    }
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::sendMessageToWitnesses(::java::lang::Object* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    sendMessageToWitnesses(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject), message, dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::requestWitnesses(::java::util::Collection* subjectList, ::rice::Continuation* c)
{
    new EvidenceTransferProtocolImpl_QueryInfo(this, subjectList, c);
}

java::util::Collection* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::getWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject)
{
    auto foo = java_cast< EvidenceTransferProtocolImpl_CacheInfo* >(npc(witnessCache)->get(subject));
    if(foo == nullptr || npc(foo)->witness == nullptr || npc(npc(foo)->witness)->isEmpty() || !npc(foo)->isValid()) {
        return nullptr;
    }
    return npc(foo)->witness;
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::requestWitnesses(::rice::p2p::commonapi::rawserialization::RawSerializable* subject)
{
    auto foo = java_cast< EvidenceTransferProtocolImpl_CacheInfo* >(npc(witnessCache)->get(subject));
    if(foo != nullptr && npc(foo)->witnessesRequested)
        return;

    foo = new EvidenceTransferProtocolImpl_CacheInfo(this, subject);
    npc(witnessCache)->put(subject, foo);
    npc(npc(peerreview)->getApp())->getWitnesses(subject, this);
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::sendEvidence(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendEvidence("_j)->append(static_cast< ::java::lang::Object* >(target))
            ->append(u", subject="_j)
            ->append(static_cast< ::java::lang::Object* >(subject))
            ->append(u")"_j)->toString());

    auto status = npc(infoStore)->getStatus(subject);
    /* assert((status != STATUS_TRUSTED)) */ ;
    ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* evidenceRecord = nullptr;
    if(status == STATUS_EXPOSED) {
        evidenceRecord = npc(infoStore)->statProof(subject);
    } else {
        evidenceRecord = npc(infoStore)->statFirstUnansweredChallenge(subject);
    }
    /* assert((evidenceRecord != nullptr)) */ ;
    try {
        auto evidence = npc(infoStore)->getEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evidenceRecord)->getOriginator()), subject, npc(evidenceRecord)->getTimeStamp());
        auto accusation = new ::org::mpisws::p2p::transport::peerreview::message::AccusationMessage(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject), static_cast< ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceRecord* >(evidenceRecord), evidence);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Sending "_j)->append(static_cast< ::java::lang::Object* >(accusation))
                ->append(u" "_j)
                ->append(((status == STATUS_EXPOSED) ? u"proof"_j : u"challenge"_j))
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(target))->toString());

        npc(peerreview)->transmit(target, accusation, nullptr, nullptr);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Error sending evidence."_j);

    }
}

void org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::sendEvidence(::java::lang::Object* source, ::java::lang::Object* id)
{ 
    sendEvidence(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(source), dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.evidence.EvidenceTransferProtocolImpl", 73);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocolImpl::getClass0()
{
    return class_();
}

