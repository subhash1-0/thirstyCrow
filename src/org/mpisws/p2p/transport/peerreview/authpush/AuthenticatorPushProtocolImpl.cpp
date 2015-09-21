// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map_Entry.hpp>
#include <java/util/Map.hpp>
#include <java/util/Random.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl_push_1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocol.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/PeerInfoStore.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/AuthPushMessage.hpp>
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

org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::AuthenticatorPushProtocolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::AuthenticatorPushProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* inStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* outStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* pendingStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::rice::environment::Environment* env) 
    : AuthenticatorPushProtocolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,inStore,outStore,pendingStore,transport,infoStore,evidenceTransferProtocol,env);
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::init()
{
    random = new ::java::util::Random();
}

constexpr int32_t org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::MAX_SUBJECTS_PER_WITNESS;

constexpr int32_t org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::MAX_WITNESSES_PER_SUBJECT;

constexpr int32_t org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::MSS;

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* inStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* outStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* pendingStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->authInStore = inStore;
    this->authOutStore = outStore;
    this->authPendingStore = pendingStore;
    this->transport = transport;
    this->infoStore = infoStore;
    this->peerreview = peerreview;
    this->evidenceTransferProtocol = evidenceTransferProtocol;
    this->probabilistic = false;
    this->pXmit = 1.0;
    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(AuthenticatorPushProtocolImpl::class_(), nullptr);
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::enableProbabilisticChecking(double pXmit)
{
    this->probabilistic = true;
    this->pXmit = pXmit;
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::push()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Authenticator push initiated with "_j)->append(npc(authOutStore)->getNumSubjects())
            ->append(u" subjects"_j)->toString());

    npc(evidenceTransferProtocol)->requestWitnesses(npc(authOutStore)->getSubjects(), new AuthenticatorPushProtocolImpl_push_1(this));
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::continuePush(::java::util::Map* subjectsToWitnesses)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Continuing authenticator push with "_j)->append(npc(subjectsToWitnesses)->size())
            ->append(u" subjects"_j)->toString());

    ::java::util::Map* witnesses = new ::java::util::HashMap();
    for (auto _i = npc(npc(subjectsToWitnesses)->entrySet())->iterator(); _i->hasNext(); ) {
        ::java::util::Map_Entry* entry = java_cast< ::java::util::Map_Entry* >(_i->next());
        {
            for (auto _i = npc(java_cast< ::java::util::Collection* >(npc(entry)->getValue()))->iterator(); _i->hasNext(); ) {
                ::rice::p2p::commonapi::rawserialization::RawSerializable* witness = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(_i->next());
                {
                    auto m = java_cast< ::java::util::Map* >(npc(witnesses)->get(witness));
                    if(m == nullptr) {
                        m = new ::java::util::HashMap();
                        npc(witnesses)->put(witness, m);
                    }
                    npc(m)->put(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(entry)->getKey()), npc(authOutStore)->getAuthenticators(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(entry)->getKey())));
                }
            }
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Found "_j)->append(npc(witnesses)->size())
            ->append(u" unique witnesses"_j)->toString());

    try {
        for (auto _i = npc(npc(witnesses)->entrySet())->iterator(); _i->hasNext(); ) {
            ::java::util::Map_Entry* e = java_cast< ::java::util::Map_Entry* >(_i->next());
            {
                sendAuthenticators(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(e)->getKey()), java_cast< ::java::util::Map* >(npc(e)->getValue()));
            }
        }
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(u"Error sending authenticators."_j, ioe);
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(u"Push completed; releasing authenticators"_j);

    for (auto _i = npc(npc(subjectsToWitnesses)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::rawserialization::RawSerializable* i = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(_i->next());
        {
            npc(authOutStore)->flush(i);
        }
    }
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::sendAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* h, ::java::util::Map* authenticators) /* throws(IOException) */
{
    if(probabilistic) {
        for (auto _i = npc(npc(authenticators)->entrySet())->iterator(); _i->hasNext(); ) {
            ::java::util::Map_Entry* e = java_cast< ::java::util::Map_Entry* >(_i->next());
            {
                auto i = npc(java_cast< ::java::util::List* >(npc(e)->getValue()))->iterator();
                while (npc(i)->hasNext()) {
                    if(npc(random)->nextFloat() < 1.0 - pXmit) {
                        npc(i)->remove();
                    }
                }
            }
        }
    }
    npc(peerreview)->transmit(h, new ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage(authenticators), nullptr, nullptr);
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::addAuthenticatorsIfValid(::java::util::List* authenticators, ::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    for (auto _i = npc(authenticators)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* thisAuth = java_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(_i->next());
        {
            if(!npc(peerreview)->addAuthenticatorIfValid(authInStore, id, thisAuth))
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Authenticator "_j)->append(static_cast< ::java::lang::Object* >(thisAuth))
                        ->append(u" has invalid signature; discarding"_j)->toString());


        }
    }
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::handleIncomingAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Received authenticators from "_j)->append(static_cast< ::java::lang::Object* >(source))->toString());

    for (auto _i = npc(npc(npc(msg)->authenticators)->entrySet())->iterator(); _i->hasNext(); ) {
        ::java::util::Map_Entry* e = java_cast< ::java::util::Map_Entry* >(_i->next());
        {
            auto id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(e)->getKey());
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"  Subject <"_j)->append(static_cast< ::java::lang::Object* >(id))
                    ->append(u">, "_j)
                    ->append(npc(java_cast< ::java::util::List* >(npc(e)->getValue()))->size())
                    ->append(u" authenticators"_j)->toString());

            if(npc(transport)->hasCertificate(id)) {
                addAuthenticatorsIfValid(java_cast< ::java::util::List* >(npc(e)->getValue()), id);
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"  Missing certificate for this subject; requesting from "_j)->append(static_cast< ::java::lang::Object* >(source))
                        ->append(u" and recording auths as pending"_j)->toString());

                for (auto _i = npc(java_cast< ::java::util::List* >(npc(e)->getValue()))->iterator(); _i->hasNext(); ) {
                    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* a = java_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(_i->next());
                    {
                        npc(authPendingStore)->addAuthenticator(id, a);
                    }
                }
                npc(peerreview)->requestCertificate(source, id);
            }
            if(npc(infoStore)->getStatus(id) != STATUS_TRUSTED) {
                npc(evidenceTransferProtocol)->sendEvidence(source, id);
            }
        }
    }
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::handleIncomingAuthenticators(::java::lang::Object* source, ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage* msg)
{ 
    handleIncomingAuthenticators(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(source), dynamic_cast< ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage* >(msg));
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    auto numAuths = npc(authPendingStore)->numAuthenticatorsFor(id);
    if(numAuths > 0) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Found "_j)->append(numAuths)
                ->append(u" pending authenticators for <"_j)
                ->append(static_cast< ::java::lang::Object* >(id))
                ->append(u">; processing..."_j)->toString());

        auto buffer = npc(authPendingStore)->getAuthenticators(id);
        addAuthenticatorsIfValid(buffer, id);
        npc(authPendingStore)->flushAuthenticatorsFor(id);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.authpush.AuthenticatorPushProtocolImpl", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl::getClass0()
{
    return class_();
}

