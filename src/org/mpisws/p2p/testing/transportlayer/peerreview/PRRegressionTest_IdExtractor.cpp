// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdExtractor.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdExtractor::PRRegressionTest_IdExtractor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdExtractor::PRRegressionTest_IdExtractor()
    : PRRegressionTest_IdExtractor(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdExtractor::extractIdentifier(PRRegressionTest_HandleImpl* h)
{
    return npc(h)->id;
}

java::lang::Object* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdExtractor::extractIdentifier(::java::lang::Object* h)
{ 
    return extractIdentifier(dynamic_cast< PRRegressionTest_HandleImpl* >(h));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdExtractor::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.IdExtractor", 77);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdExtractor::getClass0()
{
    return class_();
}

