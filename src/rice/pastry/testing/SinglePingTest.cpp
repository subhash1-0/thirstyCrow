// Generated from /pastry-2.1/src/rice/pastry/testing/SinglePingTest.java
#include <rice/pastry/testing/SinglePingTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Date.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/TestRecord.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/testing/Ping.hpp>

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
rice::pastry::testing::SinglePingTest::SinglePingTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::SinglePingTest::SinglePingTest(::rice::pastry::direct::TestRecord* tr, ::rice::environment::Environment* env) 
    : SinglePingTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(tr,env);
}

void rice::pastry::testing::SinglePingTest::ctor(::rice::pastry::direct::TestRecord* tr, ::rice::environment::Environment* env)
{
    super::ctor();
    environment = env;
    simulator = new ::rice::pastry::direct::EuclideanNetwork(env);
    factory = new ::rice::pastry::direct::DirectPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(environment), simulator, env);
    npc(simulator)->setTestRecord(tr);
    testRecord = tr;
    pastryNodes = new ::java::util::Vector();
    pingClients = new ::java::util::Vector();
}

rice::pastry::NodeHandle* rice::pastry::testing::SinglePingTest::getBootstrap()
{
    ::rice::pastry::NodeHandle* bootstrap = nullptr;
    try {
        auto lastnode = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->lastElement()));
        bootstrap = npc(lastnode)->getLocalHandle();
    } catch (::java::util::NoSuchElementException* e) {
    }
    return bootstrap;
}

rice::pastry::PastryNode* rice::pastry::testing::SinglePingTest::makePastryNode()
{
    auto pn = npc(factory)->newNode(getBootstrap());
    npc(pastryNodes)->addElement(pn);
    auto pc = new Ping(pn);
    npc(pingClients)->addElement(pc);
    auto start = ::java::lang::System::currentTimeMillis();
    {
        synchronized synchronized_0(pn);
        {
            while (!npc(pn)->isReady()) {
                try {
                    npc(pn)->wait(300);
                } catch (::java::lang::InterruptedException* ie) {
                }
            }
        }
    }
    auto now = ::java::lang::System::currentTimeMillis();
    if(now - start > 10000)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Took "_j)->append((now - start))
            ->append(u" to create node "_j)
            ->append(static_cast< ::java::lang::Object* >(pn))->toString());

    return pn;
}

void rice::pastry::testing::SinglePingTest::sendPings(int32_t k)
{
    auto n = npc(pingClients)->size();
    for (auto i = int32_t(0); i < k; i++) {
        auto from = npc(npc(environment)->getRandomSource())->nextInt(n);
        auto to = npc(npc(environment)->getRandomSource())->nextInt(n);
        auto pc = java_cast< Ping* >(java_cast< ::java::lang::Object* >(npc(pingClients)->get(from)));
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->get(to)));
        npc(pc)->sendPing(npc(pn)->getNodeId());
        while (simulate()) 
                        ;

    }
}

bool rice::pastry::testing::SinglePingTest::simulate()
{
    return false;
}

void rice::pastry::testing::SinglePingTest::checkRoutingTable()
{
    int32_t i;
    auto prev = new ::java::util::Date();
    for (i = 0; i < npc(testRecord)->getNodeNumber(); i++) {
        auto pn = makePastryNode();
        while (simulate()) 
                        ;

        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(npc(pn)->getLeafSet()));
        if(i != 0 && i % int32_t(1000) == 0)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u" nodes constructed"_j)->toString());

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u" nodes constructed"_j)->toString());
    auto curr = new ::java::util::Date();
    auto msec = npc(curr)->getTime() - npc(prev)->getTime();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"time used "_j)->append((msec / int32_t(60000)))
        ->append(u":"_j)
        ->append(((msec % int32_t(60000)) / int32_t(1000)))
        ->append(u":"_j)
        ->append(((msec % int32_t(60000)) % int32_t(1000)))->toString());
}

void rice::pastry::testing::SinglePingTest::test()
{
    int32_t i;
    auto prev = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    npc(::java::lang::System::out())->println(u"-------------------------"_j);
    for (i = 0; i < npc(testRecord)->getNodeNumber(); i++) {
        auto pn = makePastryNode();
        {
            synchronized synchronized_1(pn);
            {
                while (!npc(pn)->isReady()) {
                    try {
                        npc(pn)->wait();
                    } catch (::java::lang::InterruptedException* ie) {
                    }
                }
            }
        }
        if(i != 0 && i % int32_t(100) == 0)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u" nodes constructed"_j)->toString());

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u" nodes constructed"_j)->toString());
    auto curr = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    auto msec = curr - prev;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"time used "_j)->append((msec / int32_t(60000)))
        ->append(u":"_j)
        ->append(((msec % int32_t(60000)) / int32_t(1000)))
        ->append(u":"_j)
        ->append(((msec % int32_t(60000)) % int32_t(1000)))->toString());
    prev = curr;
    sendPings(npc(testRecord)->getTestNumber());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(testRecord)->getTestNumber())->append(u" lookups done"_j)->toString());
    curr = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    msec = curr - prev;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"time used "_j)->append((msec / int32_t(60000)))
        ->append(u":"_j)
        ->append(((msec % int32_t(60000)) / int32_t(1000)))
        ->append(u":"_j)
        ->append(((msec % int32_t(60000)) % int32_t(1000)))->toString());
    npc(testRecord)->doneTest();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::SinglePingTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.SinglePingTest", 34);
    return c;
}

java::lang::Class* rice::pastry::testing::SinglePingTest::getClass0()
{
    return class_();
}

