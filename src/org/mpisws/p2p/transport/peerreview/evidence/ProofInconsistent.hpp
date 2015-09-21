// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/ProofInconsistent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::ProofInconsistent
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence
{

public:
    typedef ::java::lang::Object super;
    static constexpr int8_t NO_SNIPPET { int8_t(0) };
    static constexpr int8_t LOG_SNIPPET { int8_t(1) };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1 {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2 {  };
    ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2);
    void ctor(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet);

public:
    int16_t getEvidenceType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* serializer, int32_t hashSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    ProofInconsistent(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2);
    ProofInconsistent(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth1, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* auth2, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet);
    ProofInconsistent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* serializer, int32_t hashSize);
protected:
    ProofInconsistent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
