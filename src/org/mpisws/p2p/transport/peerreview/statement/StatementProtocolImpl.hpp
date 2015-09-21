// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/statement/StatementProtocolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/statement/StatementProtocol.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::statement::StatementProtocolImpl
    : public virtual ::java::lang::Object
    , public virtual StatementProtocol
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::java::util::Map* incompleteStatement {  };
    ::org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocol* challengeProtocol {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore {  };
    bool progressTimerActive {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocol* challengeProtocol, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport);

public:
    virtual void notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id);
    virtual void cleanupIncompleteStatements();

public: /* package */
    virtual void timerExpired(int32_t timerID);

public:
    virtual void handleIncomingStatement(::rice::p2p::commonapi::rawserialization::RawSerializable* source, Statement* statement, ::java::util::Map* options);

public: /* package */
    virtual int32_t checkSnippetAndRequestCertificates(::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet, IncompleteStatementInfo* idx);

public:
    virtual void makeProgressOnStatement(IncompleteStatementInfo* idx);

    // Generated
    StatementProtocolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::peerreview::challenge::ChallengeResponseProtocol* challengeProtocol, ::org::mpisws::p2p::transport::peerreview::infostore::PeerInfoStore* infoStore, ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport);
protected:
    StatementProtocolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void handleIncomingStatement(::java::lang::Object* source, Statement* statement, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
};
