// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
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
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/Basics.hpp>
#include <org/mpisws/p2p/transport/peerreview/IdentifierExtractor.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/ActiveAuditInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/ActiveInvestigationInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl_scheduleProgressTimer_2.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl_startAuditTimer_3.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl_makeProgressTimerExpired_4.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl_AuditProtocolImpl_1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/AuditResponse.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ChallengeAudit.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofInconsistent.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofNonconformant.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashSeq.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AuthRequest.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AuthResponse.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/ChallengeMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/MathUtils.hpp>
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

org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::AuditProtocolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::AuditProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authInStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authCacheStore) 
    : AuditProtocolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,history,infoStore,authInStore,transport,authOutStore,evidenceTransferProtocol,authCacheStore);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::init()
{
    activeInvestigation = new ::java::util::HashMap();
    activeAudit = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authInStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authCacheStore)
{
    super::ctor();
    init();
    this->logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(AuditProtocolImpl::class_(), nullptr);
    this->peerreview = peerreview;
    this->history = history;
    this->infoStore = infoStore;
    this->authInStore = authInStore;
    this->transport = transport;
    this->authOutStore = authOutStore;
    this->evidenceTransferProtocol = evidenceTransferProtocol;
    this->authCacheStore = authCacheStore;
    this->progressTimer = nullptr;
    this->logDownloadTimeout = DEFAULT_LOG_DOWNLOAD_TIMEOUT;
    this->replayEnabled = true;
    this->lastAuditStarted = npc(peerreview)->getTime();
    this->auditIntervalMillis = DEFAULT_AUDIT_INTERVAL_MILLIS;
    auditTimer = npc(npc(npc(peerreview)->getEnvironment())->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new AuditProtocolImpl_AuditProtocolImpl_1(this)), auditIntervalMillis);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::setLogDownloadTimeout(int32_t timeoutMicros)
{
    this->logDownloadTimeout = timeoutMicros;
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::disableReplay()
{
    this->replayEnabled = false;
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::beginAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo, int8_t needPrevCheckpoint, bool replayAnswer)
{
    auto evidenceSeq = npc(peerreview)->getEvidenceSeq();
    auto audit = new ::org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit(needPrevCheckpoint, authFrom, authTo);
    auto auditRequest = new ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId())), evidenceSeq, static_cast< ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* >(audit));
    auto aai = new ActiveAuditInfo(target, replayAnswer, false, npc(peerreview)->getTime() + logDownloadTimeout, auditRequest, evidenceSeq, nullptr);
    npc(activeAudit)->put(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(target)), aai);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Sending AUDIT request to "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aai)->target)))
            ->append(u" (range="_j)
            ->append(npc(authFrom)->getSeq())
            ->append(u"-"_j)
            ->append(npc(authTo)->getSeq())
            ->append(u",eseq="_j)
            ->append(evidenceSeq)
            ->append(u")"_j)->toString());

    npc(peerreview)->transmit(target, auditRequest, nullptr, nullptr);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::startAudits()
{
    auto buffer = npc(npc(peerreview)->getApp())->getMyWitnessedNodes();
    for (auto _i = npc(buffer)->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::rawserialization::RawSerializable* h = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(_i->next());
        {
            auto i = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(h));
            auto status = npc(infoStore)->getStatus(i);
            if(status != STATUS_TRUSTED) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(h))
                        ->append(u" is "_j)
                        ->append(::org::mpisws::p2p::transport::peerreview::Basics::renderStatus(status))
                        ->append(u"; skipping audit"_j)->toString());

                continue;
            }
            if(!npc(activeAudit)->containsKey(h)) {
                ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom;
                ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo;
                auto haveEnoughAuthenticators = true;
                int8_t needPrevCheckpoint = int32_t(0);
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Starting to audit "_j)->append(static_cast< ::java::lang::Object* >(h))->toString());

                if((authFrom = npc(infoStore)->getLastCheckedAuth(i)) == nullptr) {
                    if((authFrom = npc(authInStore)->getOldestAuthenticator(i)) != nullptr) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(logger)->log(u"We haven't audited this node before; using oldest authenticator"_j);

                        needPrevCheckpoint = 1;
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(logger)->log(u"We don't have any authenticators for this node; skipping this audit"_j);

                        haveEnoughAuthenticators = false;
                    }
                }
                if((authTo = npc(authInStore)->getMostRecentAuthenticator(i)) == nullptr) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(u"No recent authenticator; skipping this audit"_j);

                    haveEnoughAuthenticators = false;
                }
                if(haveEnoughAuthenticators && npc(authFrom)->getSeq() > npc(authTo)->getSeq()) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(u"authFrom>authTo; skipping this audit"_j);

                    haveEnoughAuthenticators = false;
                }
                if(haveEnoughAuthenticators) {
                    beginAudit(h, authFrom, authTo, needPrevCheckpoint, true);
                }
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(h))
                        ->append(u" is already being audited; skipping"_j)->toString());

            }
        }
    }
    scheduleProgressTimer();
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::scheduleProgressTimer()
{
    if(progressTimer == nullptr) {
        progressTimer = npc(npc(npc(peerreview)->getEnvironment())->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new AuditProtocolImpl_scheduleProgressTimer_2(this)), static_cast< int64_t >(PROGRESS_INTERVAL_MILLIS));
    }
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::cleanupAudits()
{
    auto now = npc(peerreview)->getTime();
    for (auto _i = npc(npc(activeAudit)->values())->iterator(); _i->hasNext(); ) {
        ActiveAuditInfo* foo = java_cast< ActiveAuditInfo* >(_i->next());
        {
            if((now >= npc(foo)->currentTimeout) && !npc(foo)->isReplaying) {
                auto i = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(foo)->target)));
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"No response to AUDIT request; filing as evidence "_j)->append(npc(foo)->evidenceSeq)->toString());

                try {
                    npc(infoStore)->addEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()), i, npc(foo)->evidenceSeq, npc(npc(foo)->request)->challenge);
                } catch (::java::io::IOException* ioe) {
                    throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
                }
                npc(peerreview)->sendEvidenceToWitnesses(i, npc(foo)->evidenceSeq, npc(npc(foo)->request)->challenge);
                terminateAudit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(foo)->target));
            }
        }
    }
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::terminateAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* h)
{
    npc(activeAudit)->remove(h);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::terminateInvestigation(::rice::p2p::commonapi::rawserialization::RawSerializable* h)
{
    npc(activeInvestigation)->remove(h);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::makeProgressOnInvestigations()
{
    auto now = npc(peerreview)->getTime();
    for (auto _i = npc(npc(activeInvestigation)->values())->iterator(); _i->hasNext(); ) {
        ActiveInvestigationInfo* aii = java_cast< ActiveInvestigationInfo* >(_i->next());
        {
            if(npc(aii)->currentTimeout < now) {
                auto authFromSeq = npc(aii)->authFrom != nullptr ? npc(npc(aii)->authFrom)->getSeq() : static_cast< int64_t >(-int32_t(1));
                auto authToSeq = npc(aii)->authTo != nullptr ? npc(npc(aii)->authTo)->getSeq() : static_cast< int64_t >(-int32_t(1));
                if((0 <= authFromSeq) && (authFromSeq <= npc(aii)->since) && (npc(aii)->since < authToSeq)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Investigation of "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aii)->target)))
                            ->append(u" (since "_j)
                            ->append(npc(aii)->since)
                            ->append(u") is proceeding with an audit"_j)->toString());

                    if(authToSeq > authFromSeq) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Authenticators: "_j)->append(authFromSeq)
                                ->append(u"-"_j)
                                ->append(authToSeq)->toString());

                        beginAudit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aii)->target), npc(aii)->authFrom, npc(aii)->authTo, FLAG_FULL_MESSAGES_SENDER, false);
                        terminateInvestigation(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aii)->target));
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot start investigation; authTo<authFrom ?!? (since="_j)->append(npc(aii)->since)
                                ->append(u", authFrom="_j)
                                ->append(authFromSeq)
                                ->append(u", authTo="_j)
                                ->append(authToSeq)
                                ->append(u")"_j)->toString());

                        terminateInvestigation(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aii)->target));
                    }
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Retransmitting investigation requests for "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aii)->target)))
                            ->append(u" at "_j)
                            ->append(npc(aii)->since)->toString());

                    sendInvestigation(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aii)->target));
                    npc(aii)->currentTimeout += INVESTIGATION_INTERVAL_MILLIS;
                }
            }
        }
    }
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::sendInvestigation(::rice::p2p::commonapi::rawserialization::RawSerializable* target)
{
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::setAuditInterval(int64_t newIntervalMillis)
{
    auditIntervalMillis = newIntervalMillis;
    npc(auditTimer)->cancel();
    startAuditTimer();
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::auditsTimerExpired()
{
    startAudits();
    lastAuditStarted = npc(peerreview)->getTime();
    startAuditTimer();
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::startAuditTimer()
{
    auto now = npc(peerreview)->getTime();
    auto nextTimeout = lastAuditStarted + static_cast< int64_t >(((int32_t(500) + (npc(npc(peerreview)->getRandomSource())->nextInt(1000))) * 0.001 * auditIntervalMillis));
    if(nextTimeout <= now) {
        nextTimeout = now + int32_t(1);
    }
    auditTimer = npc(npc(npc(peerreview)->getEnvironment())->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new AuditProtocolImpl_startAuditTimer_3(this)), nextTimeout - now);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::makeProgressTimerExpired()
{
    npc(progressTimer)->cancel();
    cleanupAudits();
    makeProgressOnInvestigations();
    if(progressTimer == nullptr && ((npc(activeAudit)->size() > 0) || (npc(activeInvestigation)->size() > 0))) {
        progressTimer = npc(npc(npc(peerreview)->getEnvironment())->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new AuditProtocolImpl_makeProgressTimerExpired_4(this)), static_cast< int64_t >(PROGRESS_INTERVAL_MILLIS));
    }
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::processAuditResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* response) /* throws(IOException) */
{
    auto snippet = npc(response)->getLogSnippet();
    auto aai = findOngoingAudit(subject, timestamp);
    auto challengeAudit = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit* >(npc(npc(aai)->request)->challenge);
    auto fromSeq = npc(npc(challengeAudit)->from)->getSeq();
    auto toAuthenticator = npc(challengeAudit)->to;
    auto toSeq = npc(toAuthenticator)->getSeq();
    auto currentNodeHash = npc(snippet)->baseHash;
    auto initialNodeHash = npc(snippet)->baseHash;
    auto subjectHandle = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(response)->getLogOwner());
    auto currentSeq = npc(snippet)->getFirstSeq();
    auto initialCurrentSeq = currentSeq;
    auto auths = npc(authInStore)->getAuthenticators(subject, fromSeq, toSeq);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Checking of AUDIT response against "_j)->append(npc(auths)->size())
            ->append(u" authenticators ["_j)
            ->append(fromSeq)
            ->append(u"-"_j)
            ->append(toSeq)
            ->append(u"]"_j)->toString());

    int64_t mostRecentAuthInCache = -int32_t(1);
    auto mrauth = npc(authCacheStore)->getMostRecentAuthenticator(subject);
    if(mrauth != nullptr) {
        mostRecentAuthInCache = npc(mrauth)->getSeq();
    }
    for (auto i = npc(auths)->size() - int32_t(1); i >= 0; i--) {
        auto thisAuth = java_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(npc(auths)->get(i));
        auto thisSeq = npc(thisAuth)->getSeq();
        if(thisSeq > (mostRecentAuthInCache + (AUTH_CACHE_INTERVAL * int64_t(1000LL)))) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Caching auth "_j)->append(thisSeq)
                    ->append(u" for "_j)
                    ->append(static_cast< ::java::lang::Object* >(subject))->toString());

            npc(authCacheStore)->addAuthenticator(subject, thisAuth);
            mostRecentAuthInCache = thisSeq;
        }
    }
    auto authPtr = npc(auths)->size() - int32_t(1);
    auto nextAuth = (authPtr < 0) ? static_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(nullptr) : java_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(npc(auths)->get(authPtr));
    auto nextAuthSeq = (authPtr < 0) ? static_cast< int64_t >(-int32_t(1)) : npc(nextAuth)->getSeq();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"  NA #"_j)->append(authPtr)
            ->append(u" "_j)
            ->append(nextAuthSeq)->toString());

    for (auto _i = npc(npc(snippet)->entries)->iterator(); _i->hasNext(); ) {
        SnippetEntry* sEntry = java_cast< SnippetEntry* >(_i->next());
        {
            currentSeq = npc(sEntry)->seq;
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"[2] Entry type "_j)->append(npc(sEntry)->type)
                    ->append(u", size="_j)
                    ->append(npc(npc(sEntry)->content)->length)
                    ->append(u", seq="_j)
                    ->append(currentSeq)
                    ->append((npc(sEntry)->isHash ? u" (hashed)"_j : u""_j))->toString());

            auto entry = npc(sEntry)->content;
            ::int8_tArray* contentHash;
            if(npc(sEntry)->isHash) {
                contentHash = npc(sEntry)->content;
                /* assert((npc(contentHash)->length == npc(peerreview)->getHashSizeInBytes())) */ ;
            } else {
                contentHash = npc(transport)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(entry)}));
            }
            currentNodeHash = npc(transport)->hash(currentSeq, npc(sEntry)->type, currentNodeHash, contentHash);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"NH ["_j)->append(::rice::p2p::util::MathUtils::toBase64(currentNodeHash))
                    ->append(u"]"_j)->toString());

            if(authPtr >= 0) {
                auto foundMisbehavior = false;
                if(currentSeq == nextAuthSeq) {
                    if(!::java::util::Arrays::equals(currentNodeHash, npc(nextAuth)->getHash())) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Found a divergence for node <"_j)->append(static_cast< ::java::lang::Object* >(subject))
                                ->append(u">'s authenticator #"_j)
                                ->append(currentSeq)->toString());

                        foundMisbehavior = true;
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                            npc(logger)->log(u"Authenticator verified OK"_j);

                        authPtr--;
                        nextAuth = (authPtr < 0) ? static_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(nullptr) : java_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(npc(auths)->get(authPtr));
                        nextAuthSeq = (authPtr < 0) ? static_cast< int64_t >(-int32_t(1)) : npc(nextAuth)->getSeq();
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"NA #"_j)->append(authPtr)
                                ->append(u" "_j)
                                ->append(nextAuthSeq)->toString());

                    }
                } else if(currentSeq > nextAuthSeq) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(subject))
                            ->append(u" is trying to hide authenticator #"_j)
                            ->append(nextAuthSeq)->toString());

                    foundMisbehavior = true;
                }
                if(foundMisbehavior) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(u"Extracting proof of misbehavior from audit response"_j);

                    auto proof = new ::org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent(toAuthenticator, nextAuth, snippet);
                    auto evidenceSeq = npc(peerreview)->getEvidenceSeq();
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Filing proof against "_j)->append(static_cast< ::java::lang::Object* >(subject))
                            ->append(u" under evidence sequence number #"_j)
                            ->append(evidenceSeq)->toString());

                    npc(infoStore)->addEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()), subject, evidenceSeq, proof);
                    npc(peerreview)->sendEvidenceToWitnesses(subject, evidenceSeq, proof);
                    terminateAudit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aai)->target));
                    return;
                }
            }
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"All authenticators in range ["_j)->append(fromSeq)
            ->append(u","_j)
            ->append(toSeq)
            ->append(u"] check out OK; flushing"_j)->toString());

    npc(authInStore)->flushAuthenticatorsFor(subject, ::java::lang::Long::MIN_VALUE, toSeq);
    auto namebuf = npc(infoStore)->getHistoryName(subject);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"opening history for "_j)->append(namebuf)->toString());

    auto subjectHistory = npc(npc(peerreview)->getHistoryFactory())->open(namebuf, u"w"_j);
    auto logCanBeAppended = false;
    int64_t topSeq = int32_t(0);
    if(subjectHistory != nullptr) {
        topSeq = npc(npc(subjectHistory)->getTopLevelEntry())->getSeq();
        if(topSeq >= fromSeq)
            logCanBeAppended = true;

    } else {
        logCanBeAppended = true;
    }
    if(!npc(aai)->shouldBeReplayed) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"This audit response does not need to be replayed; discarding"_j);

        terminateAudit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aai)->target));
        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Adding entries in snippet to log '"_j)->append(namebuf)
            ->append(u"'"_j)->toString());

    if(!logCanBeAppended)
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Cannot append snippet to local copy of node's history; there appears to be a gap ("_j)->append(topSeq)
            ->append(u"-"_j)
            ->append(fromSeq)
            ->append(u")!"_j)->toString());

    if(subjectHistory == nullptr) {
        subjectHistory = npc(npc(peerreview)->getHistoryFactory())->create(namebuf, initialCurrentSeq - int32_t(1), initialNodeHash);
        if(subjectHistory == nullptr)
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Cannot create subject history: '"_j)->append(namebuf)
                ->append(u"'"_j)->toString());

    }
    auto firstNewSeq = currentSeq - (currentSeq % int32_t(1000000)) + int32_t(1000000);
    npc(subjectHistory)->appendSnippetToHistory(snippet);
    if(replayEnabled) {
        auto markerTypes = new ::int16_tArray({EVT_CHECKPOINT});
        auto lastCheckpointIdx = npc(subjectHistory)->findLastEntry(markerTypes, fromSeq);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(::java::lang::StringBuilder().append(u"LastCheckpointIdx="_j)->append(lastCheckpointIdx)
                ->append(u" (up to "_j)
                ->append(fromSeq)
                ->append(u")"_j)->toString());

        if(lastCheckpointIdx < 0) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot find last checkpoint in subject history "_j)->append(namebuf)->toString());

            terminateAudit(subjectHandle);
            return;
        }
        auto verifier = npc(npc(peerreview)->getVerifierFactory())->getVerifier(subjectHistory, subjectHandle, lastCheckpointIdx, fromSeq / int32_t(1000000), npc(snippet)->getExtInfo());
        auto replayApp = npc(npc(peerreview)->getApp())->getReplayInstance(verifier);
        if(replayApp == nullptr)
            throw new ::java::lang::RuntimeException(u"Application returned NULL when getReplayInstance() was called"_j);

        npc(verifier)->setApplication(replayApp);
        npc(aai)->verifier = verifier;
        npc(aai)->isReplaying = true;
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"REPLAY ============================================"_j);

        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Node being replayed: "_j)->append(static_cast< ::java::lang::Object* >(subjectHandle))->toString());

        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Range in log       : "_j)->append(fromSeq)
                ->append(u"-"_j)
                ->append(toSeq)->toString());

        auto sm = (java_cast< ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM* >(npc(npc(verifier)->getEnvironment())->getSelectorManager()));
        while (npc(sm)->makeProgress()) 
                        ;

        auto verifiedOK = npc(verifier)->verifiedOK();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"END OF REPLAY: "_j)->append((verifiedOK ? u"VERIFIED OK"_j : u"VERIFICATION FAILED"_j))
                ->append(u" ================="_j)->toString());

        if(!verifiedOK) {
            snippet = npc(subjectHistory)->serializeRange(lastCheckpointIdx, npc(subjectHistory)->getNumEntries() - int32_t(1), nullptr);
            if(snippet == nullptr)
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Cannot serialize range for PROOF "_j)->append(static_cast< ::java::lang::Object* >(subject))->toString());

            int64_t lastCheckpointSeq;
            auto foo = npc(subjectHistory)->statEntry(lastCheckpointIdx);
            if(foo == nullptr)
                throw new ::java::lang::RuntimeException(u"Cannot stat checkpoint entry"_j);

            lastCheckpointSeq = npc(foo)->getSeq();
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Audit revealed a protocol violation; filing evidence (snippet from "_j)->append(lastCheckpointSeq)
                    ->append(u")"_j)->toString());

            auto proof = new ::org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant(toAuthenticator, subjectHandle, snippet);
            auto evidenceSeq = npc(peerreview)->getEvidenceSeq();
            npc(infoStore)->addEvidence(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(peerreview)->getLocalId()), subject, evidenceSeq, proof);
            npc(peerreview)->sendEvidenceToWitnesses(subject, evidenceSeq, proof);
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"Audit completed; terminating"_j);

    npc(infoStore)->setLastCheckedAuth(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aai)->target))), npc((java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit* >(npc(npc(aai)->request)->challenge)))->to);
    terminateAudit(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(aai)->target));
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::processAuditResponse(::java::lang::Object* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* auditResponse)
{ 
    processAuditResponse(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject), timestamp, dynamic_cast< ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* >(auditResponse));
}

org::mpisws::p2p::transport::peerreview::audit::ActiveAuditInfo* org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::findOngoingAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq)
{
    auto ret = java_cast< ActiveAuditInfo* >(npc(activeAudit)->get(subject));
    if(ret == nullptr)
        return nullptr;

    if(!npc(ret)->isReplaying && npc(ret)->evidenceSeq == evidenceSeq) {
        return ret;
    }
    return nullptr;
}

org::mpisws::p2p::transport::peerreview::infostore::Evidence* org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::statOngoingAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq)
{
    auto aii = findOngoingAudit(subject, evidenceSeq);
    if(aii == nullptr)
        return nullptr;

    return npc(npc(aii)->request)->challenge;
}

org::mpisws::p2p::transport::peerreview::infostore::Evidence* org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::statOngoingAudit(::java::lang::Object* subject, int64_t evidenceSeq)
{ 
    return statOngoingAudit(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject), evidenceSeq);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::handleIncomingDatagram(::rice::p2p::commonapi::rawserialization::RawSerializable* handle, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message)
{
    switch (npc(message)->getType()) {
    case MSG_AUTHREQ: {
            auto request = java_cast< ::org::mpisws::p2p::transport::peerreview::message::AuthRequest* >(message);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received authenticator request for "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject)))
                    ->append(u" (since "_j)
                    ->append(npc(request)->timestamp)
                    ->append(u")"_j)->toString());

            auto a1 = npc(authInStore)->getLastAuthenticatorBefore(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject), npc(request)->timestamp);
            auto a2 = npc(authCacheStore)->getLastAuthenticatorBefore(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject), npc(request)->timestamp);
            auto a3 = npc(authInStore)->getOldestAuthenticator(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject));
            ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* best = nullptr;
            if(a1 != nullptr && (best == nullptr || (!(npc(best)->getSeq() < npc(request)->timestamp) && (npc(a1)->getSeq() < npc(request)->timestamp)) || ((npc(best)->getSeq() < npc(request)->timestamp) && (npc(a1)->getSeq() < npc(request)->timestamp) && (npc(best)->getSeq() < npc(a1)->getSeq())))) {
                best = a1;
            }
            if(a2 != nullptr && (best == nullptr || (!(npc(best)->getSeq() < npc(request)->timestamp) && (npc(a2)->getSeq() < npc(request)->timestamp)) || ((npc(best)->getSeq() < npc(request)->timestamp) && (npc(a2)->getSeq() < npc(request)->timestamp) && (npc(best)->getSeq() < npc(a2)->getSeq())))) {
                best = a2;
            }
            if(a3 != nullptr && (best == nullptr || (!(npc(best)->getSeq() < npc(request)->timestamp) && (npc(a3)->getSeq() < npc(request)->timestamp)) || ((npc(best)->getSeq() < npc(request)->timestamp) && (npc(a3)->getSeq() < npc(request)->timestamp) && (npc(best)->getSeq() < npc(a3)->getSeq())))) {
                best = a3;
            }
            auto foo = npc(authInStore)->getMostRecentAuthenticator(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject));
            if(foo == nullptr) {
                foo = npc(authCacheStore)->getMostRecentAuthenticator(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject));
            }
            if(best != nullptr && foo != nullptr) {
                auto response = new ::org::mpisws::p2p::transport::peerreview::message::AuthResponse(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject), best, foo);
                npc(peerreview)->transmit(handle, response, nullptr, nullptr);
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Cannot respond to this request; we don't have any authenticators for "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(request)->subject)))->toString());

            }
        }
        break;
    case MSG_AUTHRESP: {
            auto response = java_cast< ::org::mpisws::p2p::transport::peerreview::message::AuthResponse* >(message);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received AUTHRESP(<"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(response)->subject)))
                    ->append(u">, "_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(response)->authFrom))
                    ->append(u".."_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(response)->authTo))
                    ->append(u") from "_j)
                    ->append(static_cast< ::java::lang::Object* >(handle))->toString());

            auto idx = -int32_t(1);
            auto investigation = java_cast< ActiveInvestigationInfo* >(npc(activeInvestigation)->get(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(response)->subject)));
            if(idx >= 0) {
                if(npc(investigation)->authFrom == nullptr || (npc(npc(response)->authFrom)->getSeq() < npc(npc(investigation)->authFrom)->getSeq())) {
                    npc(investigation)->authFrom = npc(response)->authFrom;
                }
                if(npc(investigation)->authTo == nullptr || (npc(npc(response)->authTo)->getSeq() > npc(npc(investigation)->authTo)->getSeq())) {
                    npc(investigation)->authTo = npc(response)->authTo;
                }
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"AUTH response does not match any ongoing investigations; ignoring"_j);

            }
        }
        break;
    default:
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"AuditProtocol cannot handle incoming datagram type #"_j)->append(npc(message)->getType())->toString());
    }

}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::sendInvestigation(ActiveInvestigationInfo* investigation)
{
    auto id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(investigation)->target)));
    auto request = new ::org::mpisws::p2p::transport::peerreview::message::AuthRequest(npc(investigation)->since, static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
    npc(evidenceTransferProtocol)->sendMessageToWitnesses(id, request, nullptr, nullptr);
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::investigate(::rice::p2p::commonapi::rawserialization::RawSerializable* target, int64_t since)
{
    auto id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(target));
    auto investigation = java_cast< ActiveInvestigationInfo* >(npc(activeInvestigation)->get(id));
    if(investigation != nullptr) {
        if(since * int32_t(1000000) > npc(investigation)->since) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Skipping investigation request for "_j)->append(static_cast< ::java::lang::Object* >(target))
                    ->append(u" at "_j)
                    ->append(since)
                    ->append(u", since an investigation at "_j)
                    ->append(npc(investigation)->since)
                    ->append(u" is already ongoing"_j)->toString());

            return;
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Extending existing investigation from "_j)->append(npc(investigation)->since)
                ->append(u" to "_j)
                ->append(since * int32_t(1000000))->toString());

        npc(investigation)->since = since * int32_t(1000000);
    } else {
        investigation = new ActiveInvestigationInfo(target, since * int32_t(1000000), npc(peerreview)->getTime() + INVESTIGATION_INTERVAL_MILLIS, nullptr, nullptr);
        npc(activeInvestigation)->put(id, investigation);
    }
    sendInvestigation(investigation);
    scheduleProgressTimer();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.audit.AuditProtocolImpl", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl::getClass0()
{
    return class_();
}

