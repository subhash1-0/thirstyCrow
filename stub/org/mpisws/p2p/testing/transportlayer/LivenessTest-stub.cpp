// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/LivenessTest.java
#include <org/mpisws/p2p/testing/transportlayer/LivenessTest.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::LivenessTest::LivenessTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::LivenessTest::LivenessTest()
    : LivenessTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

org::mpisws::p2p::transport::proximity::ProximityProvider*& org::mpisws::p2p::testing::transportlayer::LivenessTest::bob_prox()
{
    clinit();
    return bob_prox_;
}
org::mpisws::p2p::transport::proximity::ProximityProvider* org::mpisws::p2p::testing::transportlayer::LivenessTest::bob_prox_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::LivenessTest::dave()
{
    clinit();
    return dave_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::LivenessTest::dave_;
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory*& org::mpisws::p2p::testing::transportlayer::LivenessTest::srFactory()
{
    clinit();
    return srFactory_;
}
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* org::mpisws::p2p::testing::transportlayer::LivenessTest::srFactory_;
rice::selector::Timer*& org::mpisws::p2p::testing::transportlayer::LivenessTest::timer()
{
    clinit();
    return timer_;
}
rice::selector::Timer* org::mpisws::p2p::testing::transportlayer::LivenessTest::timer_;

void ::org::mpisws::p2p::testing::transportlayer::LivenessTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::LivenessTest::ctor()");
}

/* private: org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::LivenessTest::buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env) */
int32_t org::mpisws::p2p::testing::transportlayer::LivenessTest::getDelay(::org::mpisws::p2p::transport::sourceroute::SourceRoute* a, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* b)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t org::mpisws::p2p::testing::transportlayer::LivenessTest::getDelay(::org::mpisws::p2p::transport::sourceroute::SourceRoute* a, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* b)");
    return 0;
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::LivenessTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)
{ /* stub */
    unimplemented_(u"org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::LivenessTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)");
    return 0;
}

void org::mpisws::p2p::testing::transportlayer::LivenessTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::LivenessTest::setUpBeforeClass()");
}

void org::mpisws::p2p::testing::transportlayer::LivenessTest::testLiveness()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::LivenessTest::testLiveness()");
}

void org::mpisws::p2p::testing::transportlayer::LivenessTest::testProximity()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::LivenessTest::testProximity()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::LivenessTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.LivenessTest", 50);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::LivenessTest::getClass0()
{
    return class_();
}

