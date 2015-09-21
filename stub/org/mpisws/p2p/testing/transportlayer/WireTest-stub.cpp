// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/WireTest.java
#include <org/mpisws/p2p/testing/transportlayer/WireTest.hpp>

#include <java/net/InetSocketAddress.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::WireTest::WireTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::WireTest::WireTest()
    : WireTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::org::mpisws::p2p::testing::transportlayer::WireTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::WireTest::ctor()");
}

void org::mpisws::p2p::testing::transportlayer::WireTest::bogus()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::WireTest::bogus()");
}

/* private: org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::WireTest::buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env) */
java::net::InetSocketAddress* org::mpisws::p2p::testing::transportlayer::WireTest::getBogusIdentifier(::java::net::InetSocketAddress* local)
{ /* stub */
    unimplemented_(u"java::net::InetSocketAddress* org::mpisws::p2p::testing::transportlayer::WireTest::getBogusIdentifier(::java::net::InetSocketAddress* local)");
    return 0;
}

java::lang::Object* org::mpisws::p2p::testing::transportlayer::WireTest::getBogusIdentifier(::java::lang::Object* local)
{ 
    return getBogusIdentifier(dynamic_cast< ::java::net::InetSocketAddress* >(local));
}

void org::mpisws::p2p::testing::transportlayer::WireTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::WireTest::setUpBeforeClass()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::WireTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.WireTest", 46);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::WireTest::getClass0()
{
    return class_();
}

