// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player_getIdTransport_2.hpp>

#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player_getIdTransport_2::PRRegressionTest_Player_getIdTransport_2(PRRegressionTest_Player *PRRegressionTest_Player_this, ::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::pki::x509::X509Serializer* serializer2, PRRegressionTest_IdImpl* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env)
    : super(PRRegressionTest_Player_this->PRRegressionTest_this, *static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_Player_this(PRRegressionTest_Player_this)
{
    clinit();
    ctor(serializer, serializer2, localId, localCert, localPrivate, tl, hasher, env);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player_getIdTransport_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_Player_getIdTransport_2::getClass0()
{
    return class_();
}

