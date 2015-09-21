// Generated from /pastry-2.1/src/rice/p2p/past/PastPolicy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/Continuation_StandardContinuation.hpp>

struct default_init_tag;

class rice::p2p::past::PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1
    : public ::rice::Continuation_StandardContinuation
{

public:
    typedef ::rice::Continuation_StandardContinuation super;
    void receiveResult(::java::lang::Object* o) override;

    // Generated
    PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1(PastPolicy_DefaultPastPolicy_fetch_1 *PastPolicy_DefaultPastPolicy_fetch_1_this, Past* past, ::rice::Continuation* continuation);
    static ::java::lang::Class *class_();
    PastPolicy_DefaultPastPolicy_fetch_1 *PastPolicy_DefaultPastPolicy_fetch_1_this;
    Past* past;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastPolicy;
    friend class PastPolicy_DefaultPastPolicy;
    friend class PastPolicy_DefaultPastPolicy_fetch_1;
};
