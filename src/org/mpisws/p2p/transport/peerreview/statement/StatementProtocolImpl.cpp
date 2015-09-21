// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/statement/StatementProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/statement/StatementProtocolImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/IdentifierExtractor.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceTool.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/AuditResponse.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ChallengeAudit.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofInconsistent.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/ProofNonconformant.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AckMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/IncompleteStatementInfo.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/Statement.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/MathUtils.hpp>
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

org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::StatementProtocolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::StatementProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocol* challengeProtocol, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport) 
    : StatementProtocolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,challengeProtocol,infoStore,transport);
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::init()
{
    incompleteStatement = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocol* challengeProtocol, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport)
{
    super::ctor();
    init();
    this->peerreview = peerreview;
    this->challengeProtocol = challengeProtocol;
    this->infoStore = infoStore;
    this->transport = transport;
    this->logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(StatementProtocolImpl::class_(), nullptr);
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    ::java::util::Collection* foo = java_cast< ::java::util::LinkedList* >(npc(incompleteStatement)->get(id));
    if(foo != nullptr) {
        for (auto _i = npc(foo)->iterator(); _i->hasNext(); ) {
            IncompleteStatementInfo* is = java_cast< IncompleteStatementInfo* >(_i->next());
            {
                if(!npc(is)->isFinished() && npc(is)->isMissingCertificate()) {
                    makeProgressOnStatement(is);
                }
            }
        }
    }
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::cleanupIncompleteStatements()
{
    auto now = npc(peerreview)->getTime();
    auto fooIter = npc(npc(incompleteStatement)->values())->iterator();
    while (npc(fooIter)->hasNext()) {
        auto foo = java_cast< ::java::util::LinkedList* >(npc(fooIter)->next());
        auto barIter = npc(foo)->iterator();
        while (npc(barIter)->hasNext()) {
            auto bar = java_cast< IncompleteStatementInfo* >(npc(barIter)->next());
            if(npc(bar)->isFinished() || (npc(bar)->getCurrentTimeout() < now)) {
                if(!npc(bar)->isFinished()) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Statement by "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(bar)->sender)))
                            ->append(u" is incomplete after the timeout; discarding "_j)
                            ->append(static_cast< ::java::lang::Object* >(bar))->toString());

                }
                npc(barIter)->remove();
            }
        }
        if(npc(foo)->isEmpty()) {
            npc(fooIter)->remove();
        }
    }
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::timerExpired(int32_t timerID)
{
    throw new ::java::lang::RuntimeException(u"todo: implement"_j);
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::handleIncomingStatement(::rice::p2p::commonapi::rawserialization::RawSerializable* source, Statement* statement, ::java::util::Map* options)
{
    /* assert(((npc(statement)->getType() == MSG_ACCUSATION) || (npc(statement)->getType() == MSG_RESPONSE))) */ ;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Incoming "_j)->append(((npc(statement)->getType() == MSG_ACCUSATION) ? u"accusation"_j : u"response"_j))
            ->append(u" from "_j)
            ->append(static_cast< ::java::lang::Object* >(source))->toString());

    auto idx = new IncompleteStatementInfo(false, source, npc(peerreview)->getTime() + STATEMENT_COMPLETION_TIMEOUT_MILLIS, statement, false, nullptr, options);
    auto foo = java_cast< ::java::util::LinkedList* >(npc(incompleteStatement)->get(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(statement)->subject)));
    if(foo == nullptr) {
        foo = new ::java::util::LinkedList();
        npc(incompleteStatement)->put(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(statement)->subject), foo);
    }
    npc(foo)->add(static_cast< ::java::lang::Object* >(idx));
    makeProgressOnStatement(idx);
    cleanupIncompleteStatements();
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::handleIncomingStatement(::java::lang::Object* source, Statement* statement, ::java::util::Map* options)
{ 
    handleIncomingStatement(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(source), dynamic_cast< Statement* >(statement), options);
}

int32_t org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::checkSnippetAndRequestCertificates(::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet, IncompleteStatementInfo* idx)
{
    auto ret = npc(npc(peerreview)->getEvidenceTool())->checkSnippet(snippet);
    int32_t code = (npc(java_cast< ::java::lang::Integer* >(npc(ret)->a())))->intValue();
    auto const missingCertID = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(ret)->b());
    if(code == CERT_MISSING) {
        /* assert((missingCertID != nullptr)) */ ;
        npc(idx)->isMissingCertificate_ = true;
        npc(idx)->missingCertificateID = missingCertID;
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"AUDIT RESPONSE requires certificate for "_j)->append(static_cast< ::java::lang::Object* >(missingCertID))
                ->append(u"; requesting"_j)->toString());

        npc(peerreview)->requestCertificate(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idx)->sender), missingCertID);
    }
    return code;
}

void org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::makeProgressOnStatement(IncompleteStatementInfo* idx)
{
    /* assert((!npc(idx)->finished)) */ ;
    auto statement = npc(idx)->statement;
    npc(idx)->isMissingCertificate_ = false;
    auto originator = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(statement)->originator);
    auto subject = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(statement)->subject);
    auto timestamp = npc(statement)->evidenceSeq;
    auto payload = npc(statement)->evidence;
    if(!npc(transport)->hasCertificate(subject)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"Need subject's certificate to verify statement; asking source for it"_j);

        npc(idx)->isMissingCertificate_ = true;
        npc(idx)->missingCertificateID = subject;
        npc(peerreview)->requestCertificate(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idx)->sender), subject);
        return;
    }
    if(npc(statement)->getType() == MSG_ACCUSATION) {
        switch (npc(payload)->getEvidenceType()) {
        case CHAL_AUDIT: {
                auto auditEvidence = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit* >(payload);
                if(!npc(peerreview)->verify(subject, npc(auditEvidence)->from)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"AUDIT challenge's first authenticator has an invalid signature"_j);

                    npc(idx)->finished = true;
                    return;
                }
                if(!npc(peerreview)->verify(subject, npc(auditEvidence)->to)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"AUDIT challenge's second authenticator has an invalid signature"_j);

                    npc(idx)->finished = true;
                    return;
                }
                break;
            }
        case CHAL_SEND: {
                auto udm = java_cast< ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* >(payload);
                auto innerHash = npc(udm)->getInnerHash(static_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(subject), static_cast< ::org::mpisws::p2p::transport::peerreview::history::HashProvider* >(transport));
                auto authenticator = npc(peerreview)->extractAuthenticator(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(udm)->getSenderHandle()))), npc(udm)->getTopSeq(), EVT_SEND, innerHash, npc(udm)->getHTopMinusOne(), npc(udm)->getSignature());
                if(authenticator == nullptr) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"Message in SEND challenge is not properly signed; discarding"_j);

                    npc(idx)->finished = true;
                    return;
                }
                break;
            }
        case PROOF_INCONSISTENT: {
                auto pi = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent* >(payload);
                if(!npc(peerreview)->verify(subject, npc(pi)->auth1)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"INCONSISTENT proof's first authenticator has an invalid signature"_j);

                    npc(idx)->finished = true;
                    return;
                }
                if(!npc(peerreview)->verify(subject, npc(pi)->auth2)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"INCONSISTENT proof's second authenticator has an invalid signature"_j);

                    npc(idx)->finished = true;
                    return;
                }
                auto seq1 = npc(npc(pi)->auth1)->getSeq();
                auto seq2 = npc(npc(pi)->auth2)->getSeq();
                auto hash1 = npc(npc(pi)->auth1)->getHash();
                auto hash2 = npc(npc(pi)->auth2)->getHash();
                if(npc(pi)->snippet == nullptr) {
                    if(seq1 != seq2) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"INCONSISTENT-0 proof's authenticators don't have matching sequence numbers (seq1="_j)->append(seq1)
                                ->append(u", seq2="_j)
                                ->append(seq2)
                                ->append(u") -- discarding"_j)->toString());

                        npc(idx)->finished = true;
                        return;
                    }
                    if(::java::util::Arrays::equals(hash1, hash2)) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"INCONSISTENT-0 proof's authenticators have the same hash (seq1="_j)->append(seq1)
                                ->append(u", seq2="_j)
                                ->append(seq2)
                                ->append(u") hash: "_j)
                                ->append(::rice::p2p::util::MathUtils::toBase64(hash1))
                                ->append(u" -- discarding"_j)->toString());

                        npc(idx)->finished = true;
                        return;
                    }
                } else {
                    auto firstSeq = npc(npc(pi)->snippet)->getFirstSeq();
                    if(!((firstSeq < seq2) && (seq2 < seq1))) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"INCONSISTENT-1 proof's sequence numbers do not make sense (first="_j)->append(firstSeq)
                                ->append(u", seq2="_j)
                                ->append(seq2)
                                ->append(u", seq1="_j)
                                ->append(seq1)
                                ->append(u") -- discarding"_j)->toString());

                        npc(idx)->finished = true;
                        return;
                    }
                    if(!npc(npc(pi)->snippet)->checkHashChainContains(hash1, seq1, transport, logger)) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"Snippet in INCONSISTENT-1 proof cannot be authenticated using first authenticator (#"_j)->append(seq1)
                                ->append(u") -- discarding"_j)->toString());

                        npc(idx)->finished = true;
                        return;
                    }
                    if(npc(npc(pi)->snippet)->checkHashChainContains(hash2, seq2, transport, logger)) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"INCONSISTENT-1 proof claims that authenticator 2 (#"_j)->append(seq2)
                                ->append(u") is not in the snippet, but it is -- discarding"_j)->toString());

                        npc(idx)->finished = true;
                        return;
                    }
                }
                break;
            }
        case PROOF_NONCONFORMANT: {
                auto pn = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant* >(payload);
                if(!npc(peerreview)->verify(subject, npc(pn)->to)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"NONCONFORMANT proof's authenticator has an invalid signature"_j);

                    npc(idx)->finished = true;
                    return;
                }
                switch (checkSnippetAndRequestCertificates(npc(pn)->snippet, idx)) {
                case INVALID:
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"PROOF NONCONFORMANT is not well-formed; discarding"_j);

                    npc(idx)->finished = true;
                    return;
                case CERT_MISSING:
                    return;
                default:
                    break;
                }

                if(!npc(npc(peerreview)->getEvidenceTool())->checkSnippetSignatures(npc(pn)->snippet, java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pn)->myHandle), nullptr, FLAG_INCLUDE_CHECKPOINT, nullptr, npc(npc(pn)->to)->getHash(), npc(npc(pn)->to)->getSeq())) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"PROOF NONCONFORMANT cannot be validated (signatures or authenticator)"_j);

                    return;
                }
                try {
                    auto subjectHistory = npc(npc(peerreview)->getHistoryFactory())->createTemp(npc(npc(pn)->snippet)->getFirstSeq() - int32_t(1), npc(npc(pn)->snippet)->getBaseHash());
                    npc(subjectHistory)->appendSnippetToHistory(npc(pn)->snippet);
                    auto verifier = npc(npc(peerreview)->getVerifierFactory())->getVerifier(subjectHistory, java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pn)->myHandle), 1, npc(npc(pn)->snippet)->getFirstSeq() / int32_t(1000000), nullptr);
                    auto replayApp = npc(npc(peerreview)->getApp())->getReplayInstance(verifier);
                    npc(verifier)->setApplication(replayApp);
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                        npc(logger)->log(u"REPLAY ============================================"_j);

                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Node being replayed: "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(pn)->myHandle)))->toString());

                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Range in log       : "_j)->append(npc(npc(pn)->snippet)->getFirstSeq())
                            ->append(u"-?"_j)->toString());

                    while (npc(verifier)->makeProgress()) 
                                                ;

                    auto verifiedOK = npc(verifier)->verifiedOK();
                    if(verifiedOK) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(u"PROOF NONCONFORMANT contains a log snippet that actually is conformant; discarding"_j);

                        return;
                    }
                } catch (::java::io::IOException* ioe) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->logException(::java::lang::StringBuilder().append(u"Couldn't replay!!! "_j)->append(static_cast< ::java::lang::Object* >(pn))->toString(), ioe);

                }
                break;
            }
        default: {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Unknown payload type #"_j)->append(npc(payload)->getEvidenceType())
                        ->append(u" in accusation; discarding"_j)->toString());

                npc(idx)->finished = true;
                return;
            }
        }

    } else {
        switch (npc(payload)->getEvidenceType()) {
        case CHAL_AUDIT: {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(u"Checking AUDIT RESPONSE statement"_j);

                auto auditResponse = java_cast< ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* >(payload);
                switch (checkSnippetAndRequestCertificates(npc(auditResponse)->getLogSnippet(), idx)) {
                case INVALID:
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"AUDIT RESPONSE is not well-formed; discarding"_j);

                    npc(idx)->finished = true;
                    return;
                case CERT_MISSING:
                    return;
                default:
                    break;
                }

                break;
            }
        case CHAL_SEND: {
                auto ackMessage = java_cast< ::org::mpisws::p2p::transport::peerreview::message::AckMessage* >(payload);
                break;
            }
        default: {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Unknown payload type #"_j)->append(npc(payload)->getEvidenceType())
                        ->append(u" in response; discarding"_j)->toString());

                npc(idx)->finished = true;
                return;
            }
        }

    }
    try {
        npc(challengeProtocol)->handleStatement(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idx)->sender), statement, npc(idx)->options);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
    npc(idx)->finished = true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.statement.StatementProtocolImpl", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl::getClass0()
{
    return class_();
}

