// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::PeerReviewImpl_notifyStatusChange_3
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;
    ::java::lang::String* toString() override;

    // Generated
    PeerReviewImpl_notifyStatusChange_3(PeerReviewImpl *PeerReviewImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* id, int32_t newStatus);
    static ::java::lang::Class *class_();
    PeerReviewImpl *PeerReviewImpl_this;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* id;
    int32_t newStatus;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerReviewImpl;
    friend class PeerReviewImpl_sendMessage_1;
    friend class PeerReviewImpl_requestCertificate_2;
    friend class PeerReviewImpl_init_4;
    friend class PeerReviewImpl_init_5;
    friend class PeerReviewImpl_init_6;
};
