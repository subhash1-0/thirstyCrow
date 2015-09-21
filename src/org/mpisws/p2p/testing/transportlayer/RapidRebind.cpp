// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/RapidRebind.java
#include <org/mpisws/p2p/testing/transportlayer/RapidRebind.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/net/BindException.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/environment/Environment.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::RapidRebind::RapidRebind(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::RapidRebind::RapidRebind()
    : RapidRebind(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::RapidRebind::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    auto isa = new ::java::net::InetSocketAddress(::java::net::InetAddress::getLocalHost(), int32_t(9001));
    ::org::mpisws::p2p::transport::wire::WireTransportLayer* wtl = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(isa, env, nullptr);
    auto bindException = false;
    try {
        ::org::mpisws::p2p::transport::wire::WireTransportLayer* wtl2 = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(isa, env, nullptr);
    } catch (::java::net::BindException* be) {
        bindException = true;
    }
    if(!bindException) {
        npc(::java::lang::System::out())->println(u"Test Failed, the second layer should throw a bind exception."_j);
        return;
    }
    npc(wtl)->destroy();
    wtl = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(isa, env, nullptr);
    npc(::java::lang::System::out())->println(u"Test Succeded."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::RapidRebind::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.RapidRebind", 49);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::RapidRebind::getClass0()
{
    return class_();
}

