// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/TLTest.java
#include <org/mpisws/p2p/testing/transportlayer/TLTest.hpp>

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::TLTest::TLTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::TLTest::TLTest()
    : TLTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t org::mpisws::p2p::testing::transportlayer::TLTest::START_PORT;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::TLTest::alice()
{
    clinit();
    return alice_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::TLTest::alice_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::TLTest::bob()
{
    clinit();
    return bob_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::TLTest::bob_;
rice::environment::Environment*& org::mpisws::p2p::testing::transportlayer::TLTest::env()
{
    clinit();
    return env_;
}
rice::environment::Environment* org::mpisws::p2p::testing::transportlayer::TLTest::env_;
rice::environment::logging::Logger*& org::mpisws::p2p::testing::transportlayer::TLTest::logger()
{
    clinit();
    return logger_;
}
rice::environment::logging::Logger* org::mpisws::p2p::testing::transportlayer::TLTest::logger_;
java::util::Map*& org::mpisws::p2p::testing::transportlayer::TLTest::options()
{
    clinit();
    return options_;
}
java::util::Map* org::mpisws::p2p::testing::transportlayer::TLTest::options_;
int8_tArray*& org::mpisws::p2p::testing::transportlayer::TLTest::sentBytes()
{
    clinit();
    return sentBytes_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::TLTest::sentBytes_;

void ::org::mpisws::p2p::testing::transportlayer::TLTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::TLTest::ctor()");
}

java::lang::Object* org::mpisws::p2p::testing::transportlayer::TLTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)
{ /* stub */
    unimplemented_(u"java::lang::Object* org::mpisws::p2p::testing::transportlayer::TLTest::getIdentifier(::org::mpisws::p2p::transport::TransportLayer* a, ::org::mpisws::p2p::transport::TransportLayer* b)");
    return 0;
}

void org::mpisws::p2p::testing::transportlayer::TLTest::messageTooBigUDP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::TLTest::messageTooBigUDP()");
}

void org::mpisws::p2p::testing::transportlayer::TLTest::noCallbackTest()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::TLTest::noCallbackTest()");
}

void org::mpisws::p2p::testing::transportlayer::TLTest::openTCP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::TLTest::openTCP()");
}

void org::mpisws::p2p::testing::transportlayer::TLTest::sendUDP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::TLTest::sendUDP()");
}

void org::mpisws::p2p::testing::transportlayer::TLTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::TLTest::setUpBeforeClass()");
}

void org::mpisws::p2p::testing::transportlayer::TLTest::tearDownAfterClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::TLTest::tearDownAfterClass()");
}

void org::mpisws::p2p::testing::transportlayer::TLTest::testSocketThreadSafety()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::TLTest::testSocketThreadSafety()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::TLTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.TLTest", 44);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::TLTest::getClass0()
{
    return class_();
}

