// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/pki/x509/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL
    : public ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl
{

public:
    typedef ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl super;
protected:
    void ctor(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::pki::x509::X509Serializer* serializer2, PRRegressionTest_IdImpl* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env) /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException) */;

public:
    virtual ::rice::p2p::commonapi::Cancellable* requestCertificate(PRRegressionTest_HandleImpl* source, PRRegressionTest_IdImpl* certHolder, ::rice::Continuation* c, ::java::util::Map* options);

    // Generated
    PRRegressionTest_MyIdTL(PRRegressionTest *PRRegressionTest_this, ::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::pki::x509::X509Serializer* serializer2, PRRegressionTest_IdImpl* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env);
protected:
    PRRegressionTest_MyIdTL(PRRegressionTest *PRRegressionTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::rice::p2p::commonapi::Cancellable* requestCertificate(::java::lang::Object* source, ::java::lang::Object* principal, ::rice::Continuation* c, ::java::util::Map* options) override;
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
    friend class PRRegressionTest_MyIdTL_requestCertificate_1;
    friend class PRRegressionTest_PRRegressionTest_2;
    friend class PRRegressionTest_PRRegressionTest_3;
};
