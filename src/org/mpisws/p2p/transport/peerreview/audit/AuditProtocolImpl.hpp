// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocol.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl
    : public virtual ::java::lang::Object
    , public virtual AuditProtocol
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authInStore {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore {  };
    ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authCacheStore {  };
    ::java::util::Map* activeInvestigation {  };
    ::java::util::Map* activeAudit {  };
    int32_t logDownloadTimeout {  };
    bool replayEnabled {  };
    int64_t lastAuditStarted {  };
    int64_t auditIntervalMillis {  };

public: /* protected */
    ::rice::selector::TimerTask* auditTimer {  };
    ::rice::selector::TimerTask* progressTimer {  };

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authInStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authCacheStore);

public:
    virtual void setLogDownloadTimeout(int32_t timeoutMicros);
    virtual void disableReplay();

public: /* package */
    virtual void beginAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo, int8_t needPrevCheckpoint, bool replayAnswer);

public:
    virtual void startAudits();

public: /* protected */
    virtual void scheduleProgressTimer();

public: /* package */
    virtual void cleanupAudits();
    virtual void terminateAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* h);
    virtual void terminateInvestigation(::rice::p2p::commonapi::rawserialization::RawSerializable* h);
    virtual void makeProgressOnInvestigations();

private:
    void sendInvestigation(::rice::p2p::commonapi::rawserialization::RawSerializable* target);

public: /* package */
    virtual void setAuditInterval(int64_t newIntervalMillis);

public: /* protected */
    virtual void auditsTimerExpired();
    virtual void startAuditTimer();
    virtual void makeProgressTimerExpired();

public:
    virtual void processAuditResponse(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* response) /* throws(IOException) */;
    virtual ActiveAuditInfo* findOngoingAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq);
    virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* statOngoingAudit(::rice::p2p::commonapi::rawserialization::RawSerializable* subject, int64_t evidenceSeq);
    void handleIncomingDatagram(::rice::p2p::commonapi::rawserialization::RawSerializable* handle, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message) override;

public: /* protected */
    virtual void sendInvestigation(ActiveInvestigationInfo* investigation);

public:
    virtual void investigate(::rice::p2p::commonapi::rawserialization::RawSerializable* target, int64_t since);

    // Generated
    AuditProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authInStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authOutStore, ::org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol* evidenceTransferProtocol, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authCacheStore);
protected:
    AuditProtocolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void processAuditResponse(::java::lang::Object* subject, int64_t timestamp, ::org::mpisws::p2p::transport::peerreview::evidence::AuditResponse* auditResponse) override;
    virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* statOngoingAudit(::java::lang::Object* subject, int64_t evidenceSeq) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AuditProtocolImpl_AuditProtocolImpl_1;
    friend class AuditProtocolImpl_scheduleProgressTimer_2;
    friend class AuditProtocolImpl_startAuditTimer_3;
    friend class AuditProtocolImpl_makeProgressTimerExpired_4;
};
