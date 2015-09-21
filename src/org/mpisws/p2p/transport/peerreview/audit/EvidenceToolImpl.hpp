// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/EvidenceToolImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/EvidenceTool.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::EvidenceToolImpl
    : public virtual ::java::lang::Object
    , public virtual EvidenceTool
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::util::Serializer* idSerializer {  };
    ::org::mpisws::p2p::transport::util::Serializer* handleSerializer {  };
    int32_t hashSize {  };
    int32_t signatureSize {  };

private:
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize);

public:
    ::rice::p2p::util::tuples::Tuple* checkSnippet(LogSnippet* snippet) override;
    bool checkSnippetSignatures(LogSnippet* snippet, ::rice::p2p::commonapi::rawserialization::RawSerializable* subjectHandle, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore* authStoreOrNull, int8_t flags, ::org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol* commitmentProtocol, ::int8_tArray* keyNodeHash, int64_t keyNodeMaxSeq) override;

    // Generated
    EvidenceToolImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize);
protected:
    EvidenceToolImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class EvidenceToolImpl_SendEntryRecord;
};
