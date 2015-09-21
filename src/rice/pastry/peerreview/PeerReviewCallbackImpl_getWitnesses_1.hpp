// Generated from /pastry-2.1/src/rice/pastry/peerreview/PeerReviewCallbackImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::peerreview::PeerReviewCallbackImpl_getWitnesses_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::util::Collection* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    PeerReviewCallbackImpl_getWitnesses_1(PeerReviewCallbackImpl *PeerReviewCallbackImpl_this, ::rice::pastry::Id* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    PeerReviewCallbackImpl *PeerReviewCallbackImpl_this;
    ::rice::pastry::Id* subject;
    ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PeerReviewCallbackImpl;
};
