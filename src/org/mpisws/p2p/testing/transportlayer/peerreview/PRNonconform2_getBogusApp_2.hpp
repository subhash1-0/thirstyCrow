// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform2.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform2_getBogusApp_2
    : public PRRegressionTest_BogusApp
{

public:
    typedef PRRegressionTest_BogusApp super;
    void notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus) override;

    // Generated
    PRNonconform2_getBogusApp_2(PRNonconform2 *PRNonconform2_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;
    PRNonconform2 *PRNonconform2_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRNonconform2;
    friend class PRNonconform2_getBogusApp_1;
};
