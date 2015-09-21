// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1_init_1_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    PRNonconform1_getBogusApp_1_init_1_1(PRNonconform1_getBogusApp_1 *PRNonconform1_getBogusApp_1_this);
    static ::java::lang::Class *class_();
    PRNonconform1_getBogusApp_1 *PRNonconform1_getBogusApp_1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRNonconform1;
    friend class PRNonconform1_getBogusApp_1;
};
