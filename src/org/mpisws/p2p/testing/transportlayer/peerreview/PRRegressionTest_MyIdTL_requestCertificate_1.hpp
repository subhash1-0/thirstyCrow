// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL_requestCertificate_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::security::cert::X509Certificate* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    PRRegressionTest_MyIdTL_requestCertificate_1(PRRegressionTest_MyIdTL *PRRegressionTest_MyIdTL_this, PRRegressionTest_IdImpl* certHolder, ::rice::Continuation* c);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    PRRegressionTest_MyIdTL *PRRegressionTest_MyIdTL_this;
    PRRegressionTest_IdImpl* certHolder;
    ::rice::Continuation* c;

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
    friend class PRRegressionTest_PRRegressionTest_2;
    friend class PRRegressionTest_PRRegressionTest_3;
};
