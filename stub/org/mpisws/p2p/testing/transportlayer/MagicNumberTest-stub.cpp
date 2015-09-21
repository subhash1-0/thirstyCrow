// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/MagicNumberTest.java
#include <org/mpisws/p2p/testing/transportlayer/MagicNumberTest.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
org::mpisws::p2p::testing::transportlayer::MagicNumberTest::MagicNumberTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::MagicNumberTest::MagicNumberTest()
    : MagicNumberTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int8_tArray*& org::mpisws::p2p::testing::transportlayer::MagicNumberTest::BAD_HDR()
{
    clinit();
    return BAD_HDR_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::MagicNumberTest::BAD_HDR_;
int8_tArray*& org::mpisws::p2p::testing::transportlayer::MagicNumberTest::GOOD_HDR()
{
    clinit();
    return GOOD_HDR_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::MagicNumberTest::GOOD_HDR_;
int8_tArray*& org::mpisws::p2p::testing::transportlayer::MagicNumberTest::NO_HDR()
{
    clinit();
    return NO_HDR_;
}
int8_tArray* org::mpisws::p2p::testing::transportlayer::MagicNumberTest::NO_HDR_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::MagicNumberTest::carol()
{
    clinit();
    return carol_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::MagicNumberTest::carol_;
org::mpisws::p2p::transport::TransportLayer*& org::mpisws::p2p::testing::transportlayer::MagicNumberTest::dave()
{
    clinit();
    return dave_;
}
org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::MagicNumberTest::dave_;

void ::org::mpisws::p2p::testing::transportlayer::MagicNumberTest::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::mpisws::p2p::testing::transportlayer::MagicNumberTest::ctor()");
}

void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::main(::java::lang::StringArray* args)
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::main(::java::lang::StringArray* args)");
}

void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::setUpBeforeClass()
{ /* stub */
    clinit();
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::setUpBeforeClass()");
}

void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::stallTCP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::stallTCP()");
}

void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::wrongHeaderTCP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::wrongHeaderTCP()");
}

void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::wrongHeaderUDP()
{ /* stub */
    unimplemented_(u"void org::mpisws::p2p::testing::transportlayer::MagicNumberTest::wrongHeaderUDP()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::MagicNumberTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.MagicNumberTest", 53);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::MagicNumberTest::getClass0()
{
    return class_();
}

