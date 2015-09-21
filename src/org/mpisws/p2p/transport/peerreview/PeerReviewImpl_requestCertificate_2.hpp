// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::PeerReviewImpl_requestCertificate_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::java::security::cert::X509Certificate* result);

    // Generated
    PeerReviewImpl_requestCertificate_2(PeerReviewImpl *PeerReviewImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder, ::rice::p2p::commonapi::rawserialization::RawSerializable* source);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    PeerReviewImpl *PeerReviewImpl_this;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* source;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerReviewImpl;
    friend class PeerReviewImpl_sendMessage_1;
    friend class PeerReviewImpl_notifyStatusChange_3;
    friend class PeerReviewImpl_init_4;
    friend class PeerReviewImpl_init_5;
    friend class PeerReviewImpl_init_6;
};
