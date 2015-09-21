// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/ProofNonconformant.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::ProofNonconformant
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence
{

public:
    typedef ::java::lang::Object super;
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to {  };
    ::rice::p2p::commonapi::rawserialization::RawSerializable* myHandle {  };
    ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to, ::rice::p2p::commonapi::rawserialization::RawSerializable* myHandle, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet);

public:
    int16_t getEvidenceType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    ProofNonconformant(::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to, ::rice::p2p::commonapi::rawserialization::RawSerializable* myHandle, ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet);
    ProofNonconformant(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t signatureSize);
protected:
    ProofNonconformant(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
