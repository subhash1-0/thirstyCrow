// Generated from /pastry-2.1/src/rice/pastry/testing/MemoryTest.java
#include <rice/pastry/testing/MemoryTest.hpp>

#include <java/io/FileOutputStream.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runtime.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/LinkedList.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
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

rice::pastry::testing::MemoryTest::MemoryTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::MemoryTest::MemoryTest()
    : MemoryTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::MemoryTest::testOneEnvironment() /* throws(Exception) */
{
    clinit();
    auto startPort = int32_t(5438);
    auto ringSize = int32_t(10);
    auto numNodes = int32_t(100);
    auto nodes = new ::java::util::LinkedList();
    auto run = ::java::lang::Runtime::getRuntime();
    auto memUsed = npc(run)->totalMemory() - npc(run)->freeMemory();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Memory:"_j)->append(memUsed)->toString());
    auto env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setBoolean(u"pastry_factory_selectorPerNode"_j, false);
    npc(npc(env)->getParameters())->setBoolean(u"pastry_factory_processorPerNode"_j, false);
    npc(npc(env)->getParameters())->setInt(u"pastry_socket_srm_num_source_route_attempts"_j, 0);
    npc(npc(env)->getParameters())->setInt(u"pastry_socket_scm_ping_delay"_j, 500);
    npc(npc(env)->getParameters())->setInt(u"pastry_socket_scm_num_ping_tries"_j, 5);
    npc(npc(env)->getParameters())->setInt(u"pastry_protocol_periodicLeafSet_ping_neighbor_period"_j, 8000);
    npc(npc(env)->getParameters())->setInt(u"pastry_protocol_periodicLeafSet_lease_period"_j, 10000);
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    auto localAddress = ::java::net::InetAddress::getLocalHost();
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, localAddress, startPort, env);
    auto bootaddress = new ::java::net::InetSocketAddress(localAddress, startPort);
    auto curNode = int32_t(0);
    for (; curNode < numNodes; curNode++) {
        auto bootHandle = npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(bootaddress);
        auto node = npc(factory)->newNode(java_cast< ::rice::pastry::NodeHandle* >(bootHandle));
        auto waitTime = npc(npc(env)->getTimeSource())->currentTimeMillis();
        while (!npc(node)->isReady()) {
            ::java::lang::Thread::sleep(1000);
            auto waitedFor = npc(npc(env)->getTimeSource())->currentTimeMillis() - waitTime;
        }
        auto waitedFor = npc(npc(env)->getTimeSource())->currentTimeMillis() - waitTime;
        memUsed = npc(run)->totalMemory() - npc(run)->freeMemory();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(curNode)->append(u"/"_j)
            ->append(numNodes)
            ->append(u" Memory:"_j)
            ->append(memUsed)
            ->append(u" leafset size:"_j)
            ->append(npc(npc(node)->getLeafSet())->size())
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(node))
            ->append(u" after "_j)
            ->append(waitedFor)->toString());
        bootaddress = npc((java_cast< ::rice::pastry::socket::SocketNodeHandle* >(npc(node)->getLocalHandle())))->getInetSocketAddress();
        npc(nodes)->addLast(static_cast< ::java::lang::Object* >(node));
        if(curNode > ringSize) {
            auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(nodes)->removeFirst()));
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Destroying pastry node "_j)->append(static_cast< ::java::lang::Object* >(pn))->toString());
            npc(pn)->destroy();
        }
    }
    npc(env)->destroy();
}

void rice::pastry::testing::MemoryTest::testMultiEnvironment()
{
    clinit();
}

void rice::pastry::testing::MemoryTest::testDirect()
{
    clinit();
}

void rice::pastry::testing::MemoryTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    ::java::lang::System::setOut(new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(u"mem.txt"_j))));
    ::java::lang::System::setErr(::java::lang::System::out());
    testOneEnvironment();
    testMultiEnvironment();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::MemoryTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.MemoryTest", 30);
    return c;
}

java::lang::Class* rice::pastry::testing::MemoryTest::getClass0()
{
    return class_();
}

