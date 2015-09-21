// Generated from /pastry-2.1/src/rice/p2p/splitstream/Stripe.java

#pragma once

#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::p2p::splitstream::Stripe_subscribeFailed_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    Stripe_subscribeFailed_1(Stripe *Stripe_this, ::rice::p2p::scribe::Topic* topic);
    static ::java::lang::Class *class_();
    Stripe *Stripe_this;
    ::rice::p2p::scribe::Topic* topic;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Stripe;
};
