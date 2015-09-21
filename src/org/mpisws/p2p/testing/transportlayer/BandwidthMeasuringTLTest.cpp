// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest_main_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest_MyMsg.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/commonapi/PastryEndpoint.hpp>
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

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::BandwidthMeasuringTLTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::BandwidthMeasuringTLTest()
    : BandwidthMeasuringTLTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
}

bool org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return true;
}

void org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

void org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto bindPort = int32_t(9001);
    auto env = new ::rice::environment::Environment();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::socket::SocketPastryNodeFactory* factory = new BandwidthMeasuringTLTest_main_1(nidFactory, bindPort, env);
    auto node1 = npc(factory)->newNode();
    auto app1 = new BandwidthMeasuringTLTest();
    auto ep1 = java_cast< ::rice::pastry::commonapi::PastryEndpoint* >(npc(node1)->buildEndpoint(static_cast< ::rice::p2p::commonapi::Application* >(app1), static_cast< ::java::lang::String* >(nullptr)));
    npc(ep1)->register_();
    npc(node1)->boot(static_cast< ::java::lang::Object* >(nullptr));
    auto node2 = npc(factory)->newNode();
    auto app2 = new BandwidthMeasuringTLTest();
    auto ep2 = java_cast< ::rice::pastry::commonapi::PastryEndpoint* >(npc(node2)->buildEndpoint(static_cast< ::rice::p2p::commonapi::Application* >(app2), static_cast< ::java::lang::String* >(nullptr)));
    npc(ep2)->register_();
    npc(node2)->boot(static_cast< ::java::lang::Object* >(new ::java::net::InetSocketAddress(npc(factory)->getBindAddress(), bindPort)));
    ::java::lang::Thread::sleep(5000);
    npc(::java::lang::System::out())->println(u"Spamming messages."_j);
    auto startTime = ::java::lang::System::currentTimeMillis();
    while (::java::lang::System::currentTimeMillis() < startTime + int32_t(5000)) {
        for (auto ctr = int32_t(0); ctr < 100; ctr++) {
            npc(ep1)->route(static_cast< ::rice::p2p::commonapi::Id* >(npc(node2)->getNodeId()), static_cast< ::rice::p2p::commonapi::Message* >(new BandwidthMeasuringTLTest_MyMsg()), static_cast< ::rice::p2p::commonapi::NodeHandle* >(nullptr));
        }
        ::java::lang::Thread::sleep(10);
    }
    npc(::java::lang::System::out())->println(u"Done spamming messages."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.BandwidthMeasuringTLTest", 62);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest::getClass0()
{
    return class_();
}

