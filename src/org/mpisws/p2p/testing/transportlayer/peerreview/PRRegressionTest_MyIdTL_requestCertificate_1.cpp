// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_MyIdTL_requestCertificate_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_MyIdTL.hpp>
#include <org/mpisws/p2p/transport/table/TableStore.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL_requestCertificate_1::PRRegressionTest_MyIdTL_requestCertificate_1(PRRegressionTest_MyIdTL *PRRegressionTest_MyIdTL_this, PRRegressionTest_IdImpl* certHolder, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_MyIdTL_this(PRRegressionTest_MyIdTL_this)
    , certHolder(certHolder)
    , c(c)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL_requestCertificate_1::receiveResult(::java::security::cert::X509Certificate* result)
{
    npc(PRRegressionTest_MyIdTL_this->knownValues)->put(certHolder, result);
    if(c != nullptr)
        npc(c)->receiveResult(result);

}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL_requestCertificate_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::security::cert::X509Certificate* >(result));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL_requestCertificate_1::receiveException(::java::lang::Exception* exception)
{
    if(c != nullptr)
        npc(c)->receiveException(exception);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL_requestCertificate_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_MyIdTL_requestCertificate_1::getClass0()
{
    return class_();
}

