// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport_receiveMessage_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    PRRegressionTest_BogusTransport_receiveMessage_1(PRRegressionTest_BogusTransport *PRRegressionTest_BogusTransport_this, PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m);
    static ::java::lang::Class *class_();
    PRRegressionTest_BogusTransport *PRRegressionTest_BogusTransport_this;
    PRRegressionTest_HandleImpl* i;
    ::java::nio::ByteBuffer* m;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRRegressionTest;
    friend class PRRegressionTest_IdExtractor;
    friend class PRRegressionTest_HandleSerializer;
    friend class PRRegressionTest_IdSerializer;
    friend class PRRegressionTest_HandleImpl;
    friend class PRRegressionTest_IdImpl;
    friend class PRRegressionTest_BogusTransport;
    friend class PRRegressionTest_BogusApp;
    friend class PRRegressionTest_BogusApp_scheduleMessageToBeSent_1;
    friend class PRRegressionTest_BogusApp_sendMessage_2;
    friend class PRRegressionTest_Player;
    friend class PRRegressionTest_Player_Player_1;
    friend class PRRegressionTest_Player_getIdTransport_2;
    friend class PRRegressionTest_getIdStrTranslator_1;
    friend class PRRegressionTest_MyIdTL;
    friend class PRRegressionTest_MyIdTL_requestCertificate_1;
    friend class PRRegressionTest_PRRegressionTest_2;
    friend class PRRegressionTest_PRRegressionTest_3;
};
