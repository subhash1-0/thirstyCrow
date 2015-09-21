// Generated from /pastry-2.1/src/rice/pastry/testing/PartitionHandlerTest.java
#include <rice/pastry/testing/PartitionHandlerTest.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/PartitionHandler.hpp>
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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::testing::PartitionHandlerTest::PartitionHandlerTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PartitionHandlerTest::PartitionHandlerTest()
    : PartitionHandlerTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::pastry::testing::PartitionHandlerTest::PORT_A;

constexpr int32_t rice::pastry::testing::PartitionHandlerTest::PORT_B;

void rice::pastry::testing::PartitionHandlerTest::main(::java::lang::StringArray* args) /* throws(IOException, InterruptedException) */
{
    clinit();
    ::rice::environment::Environment* env;
    env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setString(u"loglevel"_j, u"ALL"_j);
    auto factoryA = new ::rice::pastry::socket::SocketPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(env), PORT_A, env);
    auto factoryB = new ::rice::pastry::socket::SocketPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(env), PORT_B, env);
    auto bootstrapA = npc(factoryA)->getNodeHandle(new ::java::net::InetSocketAddress(u"localhost"_j, PORT_A));
    auto a = npc(factoryA)->newNode(bootstrapA);
    auto bootstrapB = npc(factoryB)->getNodeHandle(new ::java::net::InetSocketAddress(u"localhost"_j, PORT_B));
    auto b = npc(factoryB)->newNode(bootstrapB);
    auto handlerA = new ::rice::pastry::standard::PartitionHandler(a, factoryA, nullptr);
    auto handlerB = new ::rice::pastry::standard::PartitionHandler(b, factoryB, nullptr);
    {
        synchronized synchronized_0(a);
        {
            npc(a)->wait(30000);
        }
    }
    npc(handlerA)->rejoin(npc(factoryA)->getNodeHandle(new ::java::net::InetSocketAddress(u"localhost"_j, PORT_B)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PartitionHandlerTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PartitionHandlerTest", 40);
    return c;
}

java::lang::Class* rice::pastry::testing::PartitionHandlerTest::getClass0()
{
    return class_();
}

