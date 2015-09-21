// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/TestNodeHandleFetcher.java
#include <org/mpisws/p2p/testing/transportlayer/TestNodeHandleFetcher.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/testing/transportlayer/TestNodeHandleFetcher_main_1.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>

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

org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher::TestNodeHandleFetcher(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher::TestNodeHandleFetcher()
    : TestNodeHandleFetcher(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto bindPort = int32_t(9001);
    auto env = new ::rice::environment::Environment();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    auto factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindPort, env);
    auto node1 = npc(factory)->newNode();
    npc(node1)->boot(static_cast< ::java::lang::Object* >(nullptr));
    auto node2 = npc(factory)->newNode();
    npc(node2)->getNodeHandle(new ::java::net::InetSocketAddress(npc(factory)->getBindAddress(), bindPort), new TestNodeHandleFetcher_main_1());
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(npc(node1)->getLocalHandle()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.TestNodeHandleFetcher", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::TestNodeHandleFetcher::getClass0()
{
    return class_();
}

