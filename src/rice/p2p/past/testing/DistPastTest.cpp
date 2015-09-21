// Generated from /pastry-2.1/src/rice/p2p/past/testing/DistPastTest.java
#include <rice/p2p/past/testing/DistPastTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/DistPastTest_DistPastTest_1.hpp>
#include <rice/p2p/past/testing/DistPastTest_DistPastTest_2.hpp>
#include <rice/p2p/past/testing/DistPastTestContent.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/persistence/LRUCache.hpp>
#include <rice/persistence/MemoryStorage.hpp>
#include <rice/persistence/PersistentStorage.hpp>
#include <rice/persistence/StorageManagerImpl.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

rice::p2p::past::testing::DistPastTest::DistPastTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::DistPastTest::DistPastTest(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env, int32_t numNodes)  /* throws(Exception) */
    : DistPastTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,env,numNodes);
}

void rice::p2p::past::testing::DistPastTest::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env, int32_t numNodes) /* throws(Exception) */
{
    super::ctor();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::p2p::past::Past* p = nullptr;
    ::rice::persistence::Storage* stor = nullptr;
    auto idf = new ::rice::pastry::commonapi::PastryIdFactory(env);
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindport, env);
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        ::rice::p2p::commonapi::NodeHandle* bootHandle = npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(bootaddress);
        auto node = npc(factory)->newNode(java_cast< ::rice::pastry::NodeHandle* >(bootHandle));
        while (!npc(node)->isReady()) {
            ::java::lang::Thread::sleep(100);
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Finished creating new node "_j)->append(static_cast< ::java::lang::Object* >(node))->toString());
        stor = new ::rice::persistence::PersistentStorage(idf, u"."_j, int32_t(4) * int32_t(1024) * int32_t(1024), npc(node)->getEnvironment());
        p = new ::rice::p2p::past::PastImpl(node, new ::rice::persistence::StorageManagerImpl(idf, stor, new ::rice::persistence::LRUCache(new ::rice::persistence::MemoryStorage(idf), int32_t(512) * int32_t(1024), npc(node)->getEnvironment())), int32_t(3), u""_j);
    }
    ::java::lang::Thread::sleep(5000);
    auto s = ::java::lang::StringBuilder().append(u"test"_j)->append(npc(npc(env)->getRandomSource())->nextInt())->toString();
    ::rice::p2p::past::PastContent* dptc = new DistPastTestContent(env, idf, s);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Inserting "_j)->append(static_cast< ::java::lang::Object* >(dptc))->toString());
    npc(p)->insert(dptc, new DistPastTest_DistPastTest_1(this));
    ::java::lang::Thread::sleep(5000);
    npc(p)->lookup(npc(dptc)->getId(), new DistPastTest_DistPastTest_2(this));
}

void rice::p2p::past::testing::DistPastTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    try {
        auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
        auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
        auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        auto numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
        auto dt = new DistPastTest(bindport, bootaddress, env, numNodes);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.lesson4.DistTutorial localbindport bootIP bootPort numNodes"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.DistTutorial 9001 pokey.cs.almamater.edu 9001 10"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::DistPastTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.DistPastTest", 34);
    return c;
}

java::lang::Class* rice::p2p::past::testing::DistPastTest::getClass0()
{
    return class_();
}

