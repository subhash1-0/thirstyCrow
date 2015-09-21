// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/ChallengeResponseProtocol.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocolImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
    , public virtual ChallengeResponseProtocol
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* peerreview {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore {  };
    ::org::mpisws::p2p::transport::peerreview::audit::AuditProtocol* auditProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };

public: /* package */
    ::java::util::Map* queue {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* peerReviewImpl, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::audit::AuditProtocol* auditProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol);

public: /* protected */
    virtual void copyAndEnqueueTail(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence, bool isAccusation, ::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::rice::p2p::commonapi::rawserialization::RawSerializable* originator, int64_t evidenceSeq, ::java::util::Map* options);
    virtual void deliver(PacketInfo* pi);

public:
    virtual void notifyStatusChange(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus);
    void handleChallenge(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* challenge, ::java::util::Map* options) /* throws(IOException) */ override;

public: /* protected */
    virtual void handleResponse(::org::mpisws::p2p::transport::peerreview::message::ResponseMessage* message, ::java::util::Map* options) /* throws(IOException) */;

public: /* package */
    virtual bool isValidResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* response) /* throws(IOException) */;
    virtual bool isValidResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* evidence, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* response, bool extractAuthsFromResponse);

public:
    void handleStatement(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* m, ::java::util::Map* options) /* throws(IOException) */ override;
    void challengeSuspectedNode(::rice::p2p::commonapi::rawserialization::RawSerializable* target) override;
    void handleIncomingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* message, ::java::util::Map* options) /* throws(IOException) */ override;

    // Generated
    ChallengeResponseProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* peerReviewImpl, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::audit::AuditProtocol* auditProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol);
protected:
    ChallengeResponseProtocolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;

private:
    virtual ::java::lang::Class* getClass0();
};
