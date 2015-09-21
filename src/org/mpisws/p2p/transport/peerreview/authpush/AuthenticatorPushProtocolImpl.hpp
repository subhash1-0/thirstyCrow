// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocol.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl
    : public virtual ::java::lang::Object
    , public virtual AuthenticatorPushProtocol
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t MAX_SUBJECTS_PER_WITNESS { int32_t(110) };
    static constexpr int32_t MAX_WITNESSES_PER_SUBJECT { int32_t(110) };
    static constexpr int32_t MSS { int32_t(1200) };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authInStore {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authPendingStore {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore {  };
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol {  };
    bool probabilistic {  };
    double pXmit {  };
    ::java::util::Random* random {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* inStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* outStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* pendingStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::rice::environment::Environment* env);

public:
    virtual void enableProbabilisticChecking(double pXmit);
    void push() override;
    void continuePush(::java::util::Map* subjectsToWitnesses) override;

public: /* protected */
    virtual void sendAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* h, ::java::util::Map* authenticators) /* throws(IOException) */;

public:
    virtual void addAuthenticatorsIfValid(::java::util::List* authenticators, ::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    virtual void handleIncomingAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage* msg);
    void notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id) override;

    // Generated
    AuthenticatorPushProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* inStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* outStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* pendingStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::rice::environment::Environment* env);
protected:
    AuthenticatorPushProtocolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void handleIncomingAuthenticators(::java::lang::Object* source, ::org::mpisws::p2p::transport::peerreview::message::AuthPushMessage* msg) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AuthenticatorPushProtocolImpl_push_1;
};
