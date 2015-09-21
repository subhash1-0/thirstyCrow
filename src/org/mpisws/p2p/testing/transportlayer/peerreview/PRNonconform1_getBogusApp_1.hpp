// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRNonconform1.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusApp.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRNonconform1_getBogusApp_1
    : public PRRegressionTest_BogusApp
{

public:
    typedef PRRegressionTest_BogusApp super;
    void init_() override;
    void messageReceived(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */ override;
    void notifyStatusChange(PRRegressionTest_IdImpl* id, int32_t newStatus) override;

    // Generated
    PRNonconform1_getBogusApp_1(PRNonconform1 *PRNonconform1_this, PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) override;
    PRNonconform1 *PRNonconform1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRNonconform1;
    friend class PRNonconform1_getBogusApp_1_init_1_1;
};
