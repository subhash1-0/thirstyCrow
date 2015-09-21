// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::PeerReviewImpl_sendMessage_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason) override;

    // Generated
    PeerReviewImpl_sendMessage_1(PeerReviewImpl *PeerReviewImpl_this, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret);
    static ::java::lang::Class *class_();
    PeerReviewImpl *PeerReviewImpl_this;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerReviewImpl;
    friend class PeerReviewImpl_requestCertificate_2;
    friend class PeerReviewImpl_notifyStatusChange_3;
    friend class PeerReviewImpl_init_4;
    friend class PeerReviewImpl_init_5;
    friend class PeerReviewImpl_init_6;
};
