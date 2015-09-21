// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/WireSRTest.java
#include <org/mpisws/p2p/testing/transportlayer/WireSRTest.hpp>

#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::WireSRTest::WireSRTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::WireSRTest::WireSRTest()
    : WireSRTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int8_tArray*& org::mpisws::p2p::testing::transportlayer::WireSRTest::GOOD_HDR()
{
    clinit();
    return GOOD_HDR_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::WireSRTest::GOOD_HDR_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::WireSRTest::carol()
{
    clinit();
    return carol_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::WireSRTest::carol_;
org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer*& org::mpisws::p2p::testing::transportlayer::WireSRTest::carol_tap()
{
    clinit();
    return carol_tap_;
}
org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer* org::mpisws::p2p::testing::transportlayer::WireSRTest::carol_tap_;
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory*& org::mpisws::p2p::testing::transportlayer::WireSRTest::srFactory()
{
    clinit();
    return srFactory_;
}
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* org::mpisws::p2p::testing::transportlayer::WireSRTest::srFactory_;

void ::org::mpisws::p2p::testing::transportlayer::WireSRTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::WireSRTest::ctor()");
}

/* private: org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::WireSRTest::buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env) */
org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::WireSRTest::getBogusIdentifier(::org::mpisws::p2p::transport::sourceroute::SourceRoute* local)
{ /* stub */
    unimplemented_(u"org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::WireSRTest::getBogusIdentifier(::org::mpisws::p2p::transport::sourceroute::SourceRoute* local)");
    return 0;
}

java::lang::Object* org::mpisws::p2p::testing::transportlayer::WireSRTest::getBogusIdentifier(::java::lang::Object* local)
{ 
    return getBogusIdentifier(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(local));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::WireSRTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)
{ /* stub */
    unimplemented_(u"org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::WireSRTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)");
    return 0;
}

void org::mpisws::p2p::testing::transportlayer::WireSRTest::openTCP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::WireSRTest::openTCP()");
}

void org::mpisws::p2p::testing::transportlayer::WireSRTest::sendUDP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::WireSRTest::sendUDP()");
}

void org::mpisws::p2p::testing::transportlayer::WireSRTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::WireSRTest::setUpBeforeClass()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::WireSRTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.WireSRTest", 48);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::WireSRTest::getClass0()
{
    return class_();
}

