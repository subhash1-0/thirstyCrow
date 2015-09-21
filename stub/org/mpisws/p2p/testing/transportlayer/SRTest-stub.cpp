// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRTest.java
#include <org/mpisws/p2p/testing/transportlayer/SRTest.hpp>

#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::SRTest::SRTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::SRTest::SRTest()
    : SRTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int8_tArray*& org::mpisws::p2p::testing::transportlayer::SRTest::GOOD_HDR()
{
    clinit();
    return GOOD_HDR_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::SRTest::GOOD_HDR_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::SRTest::carol()
{
    clinit();
    return carol_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::SRTest::carol_;
org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer*& org::mpisws::p2p::testing::transportlayer::SRTest::carol_tap()
{
    clinit();
    return carol_tap_;
}
org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer* org::mpisws::p2p::testing::transportlayer::SRTest::carol_tap_;
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory*& org::mpisws::p2p::testing::transportlayer::SRTest::srFactory()
{
    clinit();
    return srFactory_;
}
org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* org::mpisws::p2p::testing::transportlayer::SRTest::srFactory_;

void ::org::mpisws::p2p::testing::transportlayer::SRTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::SRTest::ctor()");
}

/* private: org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::SRTest::buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env) */
org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::SRTest::getBogusIdentifier(::org::mpisws::p2p::transport::sourceroute::SourceRoute* local)
{ /* stub */
    unimplemented_(u"org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::SRTest::getBogusIdentifier(::org::mpisws::p2p::transport::sourceroute::SourceRoute* local)");
    return 0;
}

java::lang::Object* org::mpisws::p2p::testing::transportlayer::SRTest::getBogusIdentifier(::java::lang::Object* local)
{ 
    return getBogusIdentifier(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(local));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::SRTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)
{ /* stub */
    unimplemented_(u"org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::testing::transportlayer::SRTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)");
    return 0;
}

void org::mpisws::p2p::testing::transportlayer::SRTest::openTCP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::SRTest::openTCP()");
}

void org::mpisws::p2p::testing::transportlayer::SRTest::sendUDP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::SRTest::sendUDP()");
}

void org::mpisws::p2p::testing::transportlayer::SRTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::SRTest::setUpBeforeClass()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SRTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.SRTest", 44);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SRTest::getClass0()
{
    return class_();
}

