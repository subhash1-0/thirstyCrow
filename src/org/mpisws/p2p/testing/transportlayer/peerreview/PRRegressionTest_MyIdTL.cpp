// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_MyIdTL.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_MyIdTL_requestCertificate_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL::PRRegressionTest_MyIdTL(PRRegressionTest *PRRegressionTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_this(PRRegressionTest_this)
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL::PRRegressionTest_MyIdTL(PRRegressionTest *PRRegressionTest_this, ::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::pki::x509::X509Serializer* serializer2, PRRegressionTest_IdImpl* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env)  /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException) */
    : PRRegressionTest_MyIdTL(PRRegressionTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(serializer,serializer2,localId,localCert,localPrivate,tl,hasher,env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL::ctor(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::pki::x509::X509Serializer* serializer2, PRRegressionTest_IdImpl* localId, ::java::security::cert::X509Certificate* localCert, ::java::security::PrivateKey* localPrivate, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher, ::rice::environment::Environment* env) /* throws(InvalidKeyException, NoSuchAlgorithmException, NoSuchProviderException) */
{
    super::ctor(serializer, serializer2, localId, localCert, localPrivate, tl, hasher, env);
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL::requestCertificate(PRRegressionTest_HandleImpl* source, PRRegressionTest_IdImpl* certHolder, ::rice::Continuation* c, ::java::util::Map* options)
{
    return npc(java_cast< ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl* >(npc(PRRegressionTest::idTLTable())->get(source)))->requestValue(static_cast< ::java::lang::Object* >(source), static_cast< ::java::lang::Object* >(certHolder), static_cast< ::rice::Continuation* >(new PRRegressionTest_MyIdTL_requestCertificate_1(this, certHolder, c)), options);
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL::requestCertificate(::java::lang::Object* source, ::java::lang::Object* principal, ::rice::Continuation* c, ::java::util::Map* options)
{ 
    return requestCertificate(dynamic_cast< PRRegressionTest_HandleImpl* >(source), dynamic_cast< PRRegressionTest_IdImpl* >(principal), c, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.MyIdTL", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL::getClass0()
{
    return class_();
}

