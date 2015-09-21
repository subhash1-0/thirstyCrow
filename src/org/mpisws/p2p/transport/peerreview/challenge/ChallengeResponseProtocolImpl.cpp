// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocolImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/IdentifierExtractor.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceTool.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/ChallengeHashPolicy.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/PacketInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/AuditResponse.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ChallengeAudit.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/EvidenceRecord.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AccusationMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AckMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/ChallengeMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/ResponseMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::ChallengeResponseProtocolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::ChallengeResponseProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* peerReviewImpl, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::audit::AuditProtocol* auditProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol) 
    : ChallengeResponseProtocolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerReviewImpl,transport,infoStore,history,authOutStore,auditProtocol,commitmentProtocol);
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::init()
{
    queue = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* peerReviewImpl, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::audit::AuditProtocol* auditProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol)
{
    super::ctor();
    init();
    this->peerreview = peerReviewImpl;
    this->transport = transport;
    this->infoStore = infoStore;
    this->history = history;
    this->authOutStore = authOutStore;
    this->auditProtocol = auditProtocol;
    this->commitmentProtocol = commitmentProtocol;
    this->logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(ChallengeResponseProtocolImpl::class_(), nullptr);
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::copyAndEnqueueTail(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence, bool isAccusation, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::rice::p2p::commonapi::rawserialization::RawSerializable* originator, int64_t evidenceSeq, ::java::util::Map* options)
{
    auto list = java_cast< ::java::util::LinkedList* >(npc(queue)->get(source));
    if(list == nullptr) {
        list = new ::java::util::LinkedList();
        npc(queue)->put(source, list);
    }
    npc(list)->addLast(static_cast< ::java::lang::Object* >(new PacketInfo(source, evidence, isAccusation, subject, originator, evidenceSeq, options)));
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::deliver(PacketInfo* pi)
{
    try {
        if(npc(pi)->isAccusation) {
            npc(infoStore)->addEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pi)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pi)->subject), npc(pi)->evidenceSeq, npc(pi)->message, java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pi)->source));
        } else {
            npc(commitmentProtocol)->handleIncomingMessage(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pi)->source), java_cast< ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* >(npc(pi)->message), npc(pi)->options);
        }
    } catch (::java::lang::Exception* e) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
    }
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::notifyStatusChange(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus)
{
    {
        ::java::util::LinkedList* list;
        switch (newStatus) {
        case STATUS_TRUSTED:
            list = java_cast< ::java::util::LinkedList* >(npc(queue)->remove(id));
            if(list != nullptr) {
                for (auto _i = npc(list)->iterator(); _i->hasNext(); ) {
                    PacketInfo* pi = java_cast< PacketInfo* >(_i->next());
                    {
                        deliver(pi);
                    }
                }
            }
            break;
        case STATUS_EXPOSED:
            npc(queue)->remove(id);
            break;
        case STATUS_SUSPECTED:
            break;
        }
    }

}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), newStatus);
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::handleChallenge(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* challenge, ::java::util::Map* options) /* throws(IOException) */
{
    auto type = npc(challenge)->getChallengeType();
    switch (type) {
    case CHAL_AUDIT: {
            auto audit = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit* >(npc(challenge)->getChallenge());
            auto flags = npc(audit)->flags;
            auto seqFrom = npc(npc(audit)->from)->getSeq();
            auto seqTo = npc(npc(audit)->to)->getSeq();
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received an AUDIT challenge for ["_j)->append(seqFrom)
                    ->append(u","_j)
                    ->append(seqTo)
                    ->append(u"] from "_j)
                    ->append(static_cast< ::java::lang::Object* >(source))
                    ->append(u" (eseq="_j)
                    ->append(npc(challenge)->evidenceSeq)
                    ->append(u", flags="_j)
                    ->append(npc(audit)->flags)
                    ->append(u")"_j)->toString());

            if(seqTo < seqFrom) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Received an AUDIT challenge with seqTo<seqFrom:"_j)->append(seqTo)
                        ->append(u"<"_j)
                        ->append(seqFrom)->toString());

                return;
            }
            if((seqFrom < npc(history)->getBaseSeq()) || (seqTo > npc(history)->getLastSeq())) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Received an AUDIT whose range ["_j)->append(seqFrom)
                        ->append(u"-"_j)
                        ->append(seqTo)
                        ->append(u"] is outside our history range ["_j)
                        ->append(npc(history)->getBaseSeq())
                        ->append(u"-"_j)
                        ->append(npc(history)->getLastSeq())
                        ->append(u"]"_j)->toString());

                return;
            }
            auto chkpointTypes = new ::int16_tArray({
                EVT_CHECKPOINT
                , EVT_INIT
            });
            auto idxFrom = ((flags & FLAG_INCLUDE_CHECKPOINT) == FLAG_INCLUDE_CHECKPOINT) ? npc(history)->findLastEntry(chkpointTypes, seqFrom) : npc(history)->findSeq(seqFrom);
            auto idxTo = npc(history)->findSeq(seqTo);
            if((idxFrom >= 0) && (idxTo >= 0)) {
                auto fromEntry = npc(history)->statEntry(idxFrom);
                if(fromEntry == nullptr)
                    throw new ::java::lang::RuntimeException(u"Cannot get beginSeq during AUDIT challenge"_j);

                auto beginType = npc(fromEntry)->getType();
                auto beginSeq = npc(fromEntry)->getSeq();
                if(((beginSeq % int32_t(1000000)) > 0) && !((flags & FLAG_INCLUDE_CHECKPOINT) == FLAG_INCLUDE_CHECKPOINT)) {
                    beginSeq -= (beginSeq % int32_t(1000000));
                    idxFrom = npc(history)->findSeq(beginSeq);
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Moving beginSeq to "_j)->append(beginSeq)
                            ->append(u" (idx="_j)
                            ->append(idxFrom)
                            ->append(u")"_j)->toString());

                    /* assert((idxFrom >= 0)) */ ;
                }
                int64_t followingSeq;
                ::org::mpisws::p2p::transport::peerreview::history::IndexEntry* toEntry;
                while ((toEntry = npc(history)->statEntry(idxTo + int32_t(1))) != nullptr) {
                    followingSeq = npc(toEntry)->getSeq();
                    if((followingSeq % int32_t(1000000)) == 0)
                        break;

                    idxTo++;
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Advancing endSeq past "_j)->append(followingSeq)
                            ->append(u" (idx="_j)
                            ->append(idxTo)
                            ->append(u")"_j)->toString());

                }
                if((toEntry = npc(history)->statEntry(idxTo)) == nullptr) {
                    throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Cannot get endType during AUDIT challenge "_j)->append(idxTo)->toString());
                }
                auto endType = npc(toEntry)->getType();
                if(endType == EVT_RECV) {
                    idxTo++;
                }
                ::org::mpisws::p2p::transport::peerreview::history::HashPolicy* hashPolicy = new ChallengeHashPolicy(flags, java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(challenge)->originator), npc(peerreview)->getIdSerializer());
                ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippit;
                if((snippit = npc(history)->serializeRange(idxFrom, idxTo, hashPolicy)) != nullptr) {
                    auto response = new ::org::mpisws::p2p::transport::peerreview::message::ResponseMessage(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(challenge)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()), npc(challenge)->evidenceSeq, new ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalHandle()), snippit));
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Answering AUDIT challenge with "_j)->append(npc(npc(snippit)->entries)->size())
                            ->append(u"-entry log snippet"_j)->toString());

                    npc(peerreview)->transmit(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(source), static_cast< ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* >(response), static_cast< ::org::mpisws::p2p::transport::MessageCallback* >(nullptr), options);
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Error accessing history in handleChallenge("_j)->append(static_cast< ::java::lang::Object* >(source))
                            ->append(u","_j)
                            ->append(static_cast< ::java::lang::Object* >(challenge))
                            ->append(u")"_j)->toString());

                }
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot respond to AUDIT challenge ["_j)->append(seqFrom)
                        ->append(u"-"_j)
                        ->append(seqTo)
                        ->append(u",flags="_j)
                        ->append(flags)
                        ->append(u"]; entries not found (iF="_j)
                        ->append(idxFrom)
                        ->append(u"/iT="_j)
                        ->append(idxTo)
                        ->append(u")"_j)->toString());

            }
            break;
        }
    case CHAL_SEND: {
            auto udm = java_cast< ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* >(npc(challenge)->getChallenge());
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(u"Received a SEND challenge"_j);

            auto ret = npc(commitmentProtocol)->logMessageIfNew(udm);
            auto response = java_cast< ::org::mpisws::p2p::transport::peerreview::message::AckMessage* >(npc(ret)->a());
            bool loggedPreviously = (npc(java_cast< ::java::lang::Boolean* >(npc(ret)->b())))->booleanValue();
            if(!loggedPreviously) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Delivering message in CHAL_SEND "_j)->append(static_cast< ::java::lang::Object* >(udm))->toString());

                npc(npc(peerreview)->getApp())->messageReceived(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle()), npc(udm)->getPayload(), options);
            }
            auto rMsg = new ::org::mpisws::p2p::transport::peerreview::message::ResponseMessage(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(challenge)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()), npc(challenge)->evidenceSeq, java_cast< ::org::mpisws::p2p::transport::peerreview::message::AckMessage* >(npc(ret)->a()));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(u"Returning a  response"_j);

            npc(peerreview)->transmit(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(source), static_cast< ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* >(rMsg), static_cast< ::org::mpisws::p2p::transport::MessageCallback* >(nullptr), options);
            break;
        }
    default: {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Unknown challenge #"_j)->append(type)
                    ->append(u" from "_j)
                    ->append(static_cast< ::java::lang::Object* >(source))->toString());

            break;
        }
    }

}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::handleResponse(::org::mpisws::p2p::transport::peerreview::message::ResponseMessage* message, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator))->equals(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()))) {
        auto auditEvidence = npc(auditProtocol)->statOngoingAudit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), npc(message)->evidenceSeq);
        if(auditEvidence != nullptr) {
            if(isValidResponse(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), auditEvidence, npc(message)->evidence, true)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Received response to ongoing AUDIT from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject)))->toString());

                npc(auditProtocol)->processAuditResponse(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), npc(message)->evidenceSeq, java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* >(npc(message)->evidence));
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Invalid response to ongoing audit of "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject)))->toString());

            }
            return;
        }
    }
    ::rice::p2p::commonapi::rawserialization::RawSerializable* interestedParty = nullptr;
    auto record = npc(infoStore)->findEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), npc(message)->evidenceSeq);
    interestedParty = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(record)->getInterestedParty());
    if(record == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Received response, but matching request is missing; discarding"_j);

        return;
    }
    if(npc(record)->isProof()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Received an alleged response to a proof; discarding"_j);

        return;
    }
    if(npc(record)->hasResponse()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Received duplicate response; discarding"_j);

        return;
    }
    try {
        auto evidence = npc(infoStore)->getEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), npc(message)->evidenceSeq);
        if(isValidResponse(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), evidence, npc(message)->evidence)) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received valid response (orig="_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator)))
                    ->append(u", subject="_j)
                    ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject)))
                    ->append(u", t="_j)
                    ->append(npc(message)->evidenceSeq)
                    ->append(u"); adding"_j)->toString());

            npc(infoStore)->addResponse(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), npc(message)->evidenceSeq, npc(message)->evidence);
            if(interestedParty != nullptr) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Relaying response to interested party "_j)->append(static_cast< ::java::lang::Object* >(interestedParty))->toString());

                npc(peerreview)->transmit(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(interestedParty), static_cast< ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* >(message), static_cast< ::org::mpisws::p2p::transport::MessageCallback* >(nullptr), options);
            }
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Invalid response; discarding"_j);

        }
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

bool org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::isValidResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* response) /* throws(IOException) */
{
    return isValidResponse(subject, evidence, response, false);
}

bool org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::isValidResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* response, bool extractAuthsFromResponse)
{
    if(npc(evidence)->getEvidenceType() != npc(response)->getEvidenceType()) {
        return false;
    }
    switch (npc(evidence)->getEvidenceType()) {
    case CHAL_AUDIT: {
            auto evidenceAudit = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit* >(evidence);
            auto responseAudit = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* >(response);
            auto requestedBeginSeq = npc(npc(evidenceAudit)->from)->getSeq();
            auto finalSeq = npc(npc(evidenceAudit)->to)->getSeq();
            auto includePrevCheckpoint = npc(evidenceAudit)->isIncludePrevCheckpoint();
            auto firstSeq = npc(responseAudit)->getFirstSeq();
            if((requestedBeginSeq % int32_t(1000000)) > 0) {
                requestedBeginSeq -= requestedBeginSeq % int32_t(1000000);
            }
            auto fromNodeMaxSeq = requestedBeginSeq + int32_t(999999);
            if((firstSeq > requestedBeginSeq) || (!includePrevCheckpoint && (firstSeq < requestedBeginSeq))) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Log snippet starts at "_j)->append(firstSeq)
                        ->append(u", but we asked for "_j)
                        ->append(requestedBeginSeq)
                        ->append(u" (ilc="_j)
                        ->append((includePrevCheckpoint ? u"yes"_j : u"no"_j))
                        ->append(u"); flagging invalid"_j)->toString());

                return false;
            }
            auto snippetOK = npc(npc(peerreview)->getEvidenceTool())->checkSnippetSignatures(npc(responseAudit)->getLogSnippet(), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(responseAudit)->getLogOwner()), extractAuthsFromResponse ? authOutStore : static_cast< ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* >(nullptr), npc(evidenceAudit)->flags, commitmentProtocol, npc(npc(evidenceAudit)->from)->getHash(), fromNodeMaxSeq);
            if(!snippetOK)
                return false;

            break;
        }
    case CHAL_SEND: {
            auto evidenceUDM = java_cast< ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* >(evidence);
            auto senderSeq = npc(evidenceUDM)->getTopSeq();
            auto senderHandle = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(evidenceUDM)->getSenderHandle());
            auto senderHtopMinusOne = npc(evidenceUDM)->getHTopMinusOne();
            auto senderSignature = npc(evidenceUDM)->getSignature();
            auto relevantLen = npc(evidenceUDM)->getRelevantLen();
            auto responseAck = java_cast< ::org::mpisws::p2p::transport::peerreview::message::AckMessage* >(response);
            auto receiverID = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(responseAck)->getNodeId());
            auto ackSenderSeq = npc(responseAck)->getSendEntrySeq();
            auto ackReceiverSeq = npc(responseAck)->getRecvEntrySeq();
            auto receiverHtopMinusOne = npc(responseAck)->getHashTopMinusOne();
            auto receiverSignature = npc(responseAck)->getSignature();
            auto okay = true;
            if(ackSenderSeq != senderSeq) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"RESP.SEND: ACK contains sender seq "_j)->append(ackSenderSeq)
                        ->append(u", but challenge contains "_j)
                        ->append(senderSeq)
                        ->append(u"; flagging invalid"_j)->toString());

                okay = false;
            }
            if(okay) {
                auto innerHash = npc(evidenceUDM)->getInnerHash(transport);
                auto authenticator = npc(peerreview)->extractAuthenticator(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(receiverID), ackReceiverSeq, EVT_RECV, innerHash, receiverHtopMinusOne, receiverSignature);
                if(authenticator != nullptr) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(u"Auth OK"_j);

                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"RESP.SEND: Signature on ACK is invalid"_j);

                    okay = false;
                }
            }
            if(!okay)
                return false;

            break;
        }
    default:
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot check whether response type #"_j)->append(npc(evidence)->getEvidenceType())
                ->append(u" is valid; answering no"_j)->toString());

        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Cannot check whether response type #"_j)->append(npc(evidence)->getEvidenceType())
            ->append(u" is valid; answering no"_j)->toString());
    }

    return true;
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::handleStatement(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* m, ::java::util::Map* options) /* throws(IOException) */
{
    /* assert((npc(m)->getType() == MSG_ACCUSATION || npc(m)->getType() == MSG_RESPONSE)) */ ;
    {
        ::org::mpisws::p2p::transport::peerreview::message::AccusationMessage* message;
        int32_t status;
        switch (npc(m)->getType()) {
        case MSG_RESPONSE: {
                auto message = java_cast< ::org::mpisws::p2p::transport::peerreview::message::ResponseMessage* >(m);
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Statement completed: RESPONSE  (orig="_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator)))
                        ->append(u", subject="_j)
                        ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject)))
                        ->append(u", ts="_j)
                        ->append(npc(message)->evidenceSeq)
                        ->append(u")"_j)->toString());

                handleResponse(message, options);
                if(npc(infoStore)->getStatus(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(source))) == STATUS_SUSPECTED) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"RECHALLENGE "_j)->append(static_cast< ::java::lang::Object* >(source))->toString());

                    challengeSuspectedNode(source);
                }
                return;
            }
        case MSG_ACCUSATION:
            message = java_cast< ::org::mpisws::p2p::transport::peerreview::message::AccusationMessage* >(m);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Statement completed: ACCUSATION  (orig="_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator)))
                    ->append(u", subject="_j)
                    ->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject)))
                    ->append(u", ts="_j)
                    ->append(npc(message)->evidenceSeq)
                    ->append(u")"_j)->toString());

            status = npc(infoStore)->getStatus(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(source)));
            switch (status) {
            case STATUS_EXPOSED:
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Got an accusation from exposed node "_j)->append(static_cast< ::java::lang::Object* >(source))
                        ->append(u"; discarding"_j)->toString());

                break;
            case STATUS_TRUSTED:
                try {
                    auto foo = npc(infoStore)->getEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), npc(message)->evidenceSeq);
                    if(foo == nullptr) {
                        npc(infoStore)->addEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), npc(message)->evidenceSeq, npc(message)->evidence, source);
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(logger)->log(u"We already have a copy of that challenge; discarding"_j);

                    }
                } catch (::java::io::IOException* ioe) {
                    throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
                }
                break;
            case STATUS_SUSPECTED: {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Incoming accusation from SUSPECTED node "_j)->append(static_cast< ::java::lang::Object* >(source))
                            ->append(u"; queueing and challenging the node"_j)->toString());

                    copyAndEnqueueTail(source, npc(message)->evidence, true, java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->subject), java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(message)->originator), npc(message)->evidenceSeq, options);
                    challengeSuspectedNode(source);
                    break;
                }
            default:
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Unknown status: #"_j)->append(status)->toString());
            }

        }
    }

}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* target)
{
    auto tIdentifier = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(target));
    auto record = npc(infoStore)->statFirstUnansweredChallenge(tIdentifier);
    if(record == nullptr) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(target))
            ->append(u" is SUSPECTED, but I cannot retrieve an unanswered challenge?!?"_j)->toString());
    }
    try {
        auto challenge = new ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(record)->getOriginator())), npc(record)->getTimeStamp(), npc(infoStore)->getEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(record)->getOriginator()), tIdentifier, npc(record)->getTimeStamp()));
        npc(peerreview)->transmit(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(target), static_cast< ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* >(challenge), static_cast< ::org::mpisws::p2p::transport::MessageCallback* >(nullptr), static_cast< ::java::util::Map* >(nullptr));
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::handleIncomingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* message, ::java::util::Map* options) /* throws(IOException) */
{
    auto status = npc(infoStore)->getStatus(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(source)));
    switch (status) {
    case STATUS_EXPOSED:
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Got a user message from exposed node "_j)->append(static_cast< ::java::lang::Object* >(source))
                ->append(u"; discarding"_j)->toString());

        return;
    case STATUS_TRUSTED:
        npc(commitmentProtocol)->handleIncomingMessage(source, message, options);
        return;
    }

    /* assert((status == STATUS_SUSPECTED)) */ ;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Incoming message from SUSPECTED node "_j)->append(static_cast< ::java::lang::Object* >(source))
            ->append(u"; queueing and challenging the node"_j)->toString());

    copyAndEnqueueTail(source, message, false, nullptr, nullptr, 0, options);
    challengeSuspectedNode(source);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.challenge.ChallengeResponseProtocolImpl", 75);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl::getClass0()
{
    return class_();
}

