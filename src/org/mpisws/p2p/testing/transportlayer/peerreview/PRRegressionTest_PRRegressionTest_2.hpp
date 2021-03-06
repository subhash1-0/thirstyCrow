// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_PRRegressionTest_2
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    PRRegressionTest_PRRegressionTest_2(PRRegressionTest *PRRegressionTest_this);
    static ::java::lang::Class *class_();
    PRRegressionTest *PRRegressionTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRRegressionTest;
    friend class PRRegressionTest_IdExtractor;
    friend class PRRegressionTest_HandleSerializer;
    friend class PRRegressionTest_IdSerializer;
    friend class PRRegressionTest_HandleImpl;
    friend class PRRegressionTest_IdImpl;
    friend class PRRegressionTest_BogusTransport;
    friend class PRRegressionTest_BogusTransport_receiveMessage_1;
    friend class PRRegressionTest_BogusApp;
    friend class PRRegressionTest_BogusApp_scheduleMessageToBeSent_1;
    friend class PRRegressionTest_BogusApp_sendMessage_2;
    friend class PRRegressionTest_Player;
    friend class PRRegressionTest_Player_Player_1;
    friend class PRRegressionTest_Player_getIdTransport_2;
    friend class PRRegressionTest_getIdStrTranslator_1;
    friend class PRRegressionTest_MyIdTL;
    friend class PRRegressionTest_MyIdTL_requestCertificate_1;
    friend class PRRegressionTest_PRRegressionTest_3;
};
