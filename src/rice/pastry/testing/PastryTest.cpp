// Generated from /pastry-2.1/src/rice/pastry/testing/PastryTest.java
#include <rice/pastry/testing/PastryTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/util/Date.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/testing/PingClient.hpp>

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
rice::pastry::testing::PastryTest::PastryTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PastryTest::PastryTest(::rice::environment::Environment* env) 
    : PastryTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::testing::PastryTest::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    environment = env;
    simulator = new ::rice::pastry::direct::EuclideanNetwork(env);
    factory = new ::rice::pastry::direct::DirectPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(env), simulator, env);
    pastryNodes = new ::java::util::Vector();
    pingClients = new ::java::util::Vector();
}

rice::pastry::NodeHandle* rice::pastry::testing::PastryTest::getBootstrap()
{
    ::rice::pastry::NodeHandle* bootstrap = nullptr;
    try {
        auto lastnode = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->lastElement()));
        bootstrap = npc(lastnode)->getLocalHandle();
    } catch (::java::util::NoSuchElementException* e) {
    }
    return bootstrap;
}

void rice::pastry::testing::PastryTest::makePastryNode()
{
    auto pn = npc(factory)->newNode(getBootstrap());
    npc(pastryNodes)->addElement(pn);
    auto pc = new PingClient(pn);
    npc(pingClients)->addElement(pc);
    {
        synchronized synchronized_0(pn);
        {
            while (!npc(pn)->isReady()) {
                try {
                    npc(pn)->wait();
                } catch (::java::lang::InterruptedException* ie) {
                }
            }
        }
    }
}

void rice::pastry::testing::PastryTest::sendPings(int32_t k)
{
    auto n = npc(pingClients)->size();
    for (auto i = int32_t(0); i < k; i++) {
        auto from = npc(npc(environment)->getRandomSource())->nextInt(n);
        auto to = npc(npc(environment)->getRandomSource())->nextInt(n);
        auto pc = java_cast< PingClient* >(java_cast< ::java::lang::Object* >(npc(pingClients)->get(from)));
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->get(to)));
        npc(pc)->sendTrace(npc(pn)->getNodeId());
        while (simulate()) 
                        ;

        npc(::java::lang::System::out())->println(u"-------------------"_j);
    }
}

bool rice::pastry::testing::PastryTest::simulate()
{
    try {
        ::java::lang::Thread::sleep(300);
    } catch (::java::lang::InterruptedException* ie) {
    }
    return false;
}

void rice::pastry::testing::PastryTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto pt = new PastryTest(::rice::environment::Environment::directEnvironment());
    auto n = int32_t(4000);
    auto m = int32_t(100);
    auto k = int32_t(10);
    auto msgCount = int32_t(0);
    auto old = new ::java::util::Date();
    for (auto i = int32_t(0); i < n; i++) {
        npc(pt)->makePastryNode();
        if(i % int32_t(100) == 0)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Created node "_j)->append(i)
                ->append(u"/"_j)
                ->append(n)->toString());

        msgCount++;
        if((i + int32_t(1)) % m == 0) {
            auto now = new ::java::util::Date();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append((i + int32_t(1)))->append(u" "_j)
                ->append((npc(now)->getTime() - npc(old)->getTime()))
                ->append(u" "_j)
                ->append(msgCount)->toString());
            msgCount = 0;
            old = now;
        }
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(n)->append(u" nodes constructed"_j)->toString());
    npc(pt)->sendPings(k);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PastryTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PastryTest", 30);
    return c;
}

java::lang::Class* rice::pastry::testing::PastryTest::getClass0()
{
    return class_();
}

