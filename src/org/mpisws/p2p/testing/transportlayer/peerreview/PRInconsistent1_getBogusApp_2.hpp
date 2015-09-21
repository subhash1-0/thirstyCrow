// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getBogusApp_2
    : public PRRegressionTest_BogusApp
{

public:
    typedef PRRegressionTest_BogusApp super;
    void notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus) override;

    // Generated
    PRInconsistent1_getBogusApp_2(PRInconsistent1 *PRInconsistent1_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;
    PRInconsistent1 *PRInconsistent1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRInconsistent1;
    friend class PRInconsistent1_getPeerReview_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1;
    friend class PRInconsistent1_ForkingSecureHistory;
};
