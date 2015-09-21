// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/EpochTest.java
#include <org/mpisws/p2p/testing/transportlayer/EpochTest.hpp>

#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::EpochTest::EpochTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::EpochTest::EpochTest()
    : EpochTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int8_tArray*& org::mpisws::p2p::testing::transportlayer::EpochTest::GOOD_HDR()
{
    clinit();
    return GOOD_HDR_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::EpochTest::GOOD_HDR_;

void ::org::mpisws::p2p::testing::transportlayer::EpochTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::EpochTest::ctor()");
}

void org::mpisws::p2p::testing::transportlayer::EpochTest::bogus()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::EpochTest::bogus()");
}

/* private: org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::EpochTest::buildTL(::java::lang::String* name, ::java::net::InetAddress* addr, int32_t port, ::rice::environment::Environment* env) */
org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::testing::transportlayer::EpochTest::getBogusIdentifier(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)
{ /* stub */
    unimplemented_(u"org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::testing::transportlayer::EpochTest::getBogusIdentifier(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)");
    return 0;
}

java::lang::Object* org::mpisws::p2p::testing::transportlayer::EpochTest::getBogusIdentifier(::java::lang::Object* local)
{ 
    return getBogusIdentifier(dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(local));
}

void org::mpisws::p2p::testing::transportlayer::EpochTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::EpochTest::setUpBeforeClass()");
}

void org::mpisws::p2p::testing::transportlayer::EpochTest::testFalseAddress()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::EpochTest::testFalseAddress()");
}

void org::mpisws::p2p::testing::transportlayer::EpochTest::testFalseAddressBypass()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::EpochTest::testFalseAddressBypass()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::EpochTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.EpochTest", 47);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::EpochTest::getClass0()
{
    return class_();
}

