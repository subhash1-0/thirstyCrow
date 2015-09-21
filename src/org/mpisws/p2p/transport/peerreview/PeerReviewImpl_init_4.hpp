// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::PeerReviewImpl_init_4
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;
    ::java::lang::String* toString() override;

    // Generated
    PeerReviewImpl_init_4(PeerReviewImpl *PeerReviewImpl_this);
    static ::java::lang::Class *class_();
    PeerReviewImpl *PeerReviewImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerReviewImpl;
    friend class PeerReviewImpl_sendMessage_1;
    friend class PeerReviewImpl_requestCertificate_2;
    friend class PeerReviewImpl_notifyStatusChange_3;
    friend class PeerReviewImpl_init_5;
    friend class PeerReviewImpl_init_6;
};
