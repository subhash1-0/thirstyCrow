// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTest2.java
#include <org/mpisws/p2p/testing/transportlayer/SSLTest2.hpp>

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

org::mpisws::p2p::testing::transportlayer::SSLTest2::SSLTest2(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::SSLTest2::SSLTest2()
    : SSLTest2(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::SSLTest2::main(::java::lang::StringArray* argz) /* throws(Exception) */
{
    clinit();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest2::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.SSLTest2", 46);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest2::getClass0()
{
    return class_();
}

