// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRManagerTest.java
#include <org/mpisws/p2p/testing/transportlayer/SRManagerTest.hpp>

#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::SRManagerTest::SRManagerTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::SRManagerTest::SRManagerTest()
    : SRManagerTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int8_tArray*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::GOOD_HDR()
{
    clinit();
    return GOOD_HDR_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::SRManagerTest::GOOD_HDR_;
org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::alice_addr()
{
    clinit();
    return alice_addr_;
}
org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::testing::transportlayer::SRManagerTest::alice_addr_;
org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::bob_addr()
{
    clinit();
    return bob_addr_;
}
org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::testing::transportlayer::SRManagerTest::bob_addr_;
org::mpisws::p2p::transport::proximity::ProximityProvider*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::bob_prox()
{
    clinit();
    return bob_prox_;
}
org::mpisws::p2p::transport::proximity::ProximityProvider* org::mpisws::p2p::testing::transportlayer::SRManagerTest::bob_prox_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::carol()
{
    clinit();
    return carol_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::SRManagerTest::carol_;
org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::carol_tap()
{
    clinit();
    return carol_tap_;
}
org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer* org::mpisws::p2p::testing::transportlayer::SRManagerTest::carol_tap_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::dave()
{
    clinit();
    return dave_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::SRManagerTest::dave_;
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::srFactory()
{
    clinit();
    return srFactory_;
}
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* org::mpisws::p2p::testing::transportlayer::SRManagerTest::srFactory_;
rice::selector::Timer*& org::mpisws::p2p::testing::transportlayer::SRManagerTest::timer()
{
    clinit();
    return timer_;
}
rice::selector::Timer* org::mpisws::p2p::testing::transportlayer::SRManagerTest::timer_;

void ::org::mpisws::p2p::testing::transportlayer::SRManagerTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::SRManagerTest::ctor()");
}

/* private: org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::SRManagerTest::buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env) */
bool org::mpisws::p2p::testing::transportlayer::SRManagerTest::connectionAllowed(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* a, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* b, ::java::lang::String* context)
{ /* stub */
    clinit();
    unimplemented_(u"bool org::mpisws::p2p::testing::transportlayer::SRManagerTest::connectionAllowed(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* a, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* b, ::java::lang::String* context)");
    return 0;
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::testing::transportlayer::SRManagerTest::getBogusIdentifier(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)
{ /* stub */
    unimplemented_(u"org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::testing::transportlayer::SRManagerTest::getBogusIdentifier(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)");
    return 0;
}

java::lang::Object* org::mpisws::p2p::testing::transportlayer::SRManagerTest::getBogusIdentifier(::java::lang::Object* local)
{ 
    return getBogusIdentifier(dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(local));
}

int32_t org::mpisws::p2p::testing::transportlayer::SRManagerTest::getDelay(::org::mpisws::p2p::transport::sourceroute::SourceRoute* a, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* b)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t org::mpisws::p2p::testing::transportlayer::SRManagerTest::getDelay(::org::mpisws::p2p::transport::sourceroute::SourceRoute* a, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* b)");
    return 0;
}

void org::mpisws::p2p::testing::transportlayer::SRManagerTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::SRManagerTest::setUpBeforeClass()");
}

void org::mpisws::p2p::testing::transportlayer::SRManagerTest::testLiveness()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::SRManagerTest::testLiveness()");
}

void org::mpisws::p2p::testing::transportlayer::SRManagerTest::testProximity()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::SRManagerTest::testProximity()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SRManagerTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.SRManagerTest", 51);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SRManagerTest::getClass0()
{
    return class_();
}

