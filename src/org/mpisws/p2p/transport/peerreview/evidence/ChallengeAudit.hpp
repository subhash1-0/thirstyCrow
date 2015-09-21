// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/ChallengeAudit.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::evidence::ChallengeAudit
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(1) };
    int8_t flags {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* from {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to {  };
protected:
    void ctor(int8_t flags, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* from, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to);

public:
    int16_t getEvidenceType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual bool isIncludePrevCheckpoint();

    // Generated
    ChallengeAudit(int8_t flags, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* from, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* to);
    ChallengeAudit(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize);
protected:
    ChallengeAudit(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
