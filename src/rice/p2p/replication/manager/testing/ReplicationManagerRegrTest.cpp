// Generated from /pastry-2.1/src/rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.java
#include <rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>
#include <rice/p2p/replication/manager/ReplicationManager.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl.hpp>
#include <rice/p2p/replication/manager/testing/ReplicationManagerRegrTest_runMaintenance_1.hpp>
#include <rice/p2p/replication/manager/testing/ReplicationManagerRegrTest_TestReplicationManagerClient.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <Array.hpp>
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

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
typedef ::SubArray< ::rice::p2p::commonapi::Node, ::java::lang::ObjectArray > NodeArray;
        } // commonapi

        namespace replication
        {
typedef ::SubArray< ::rice::p2p::replication::ReplicationClient, ::java::lang::ObjectArray > ReplicationClientArray;

            namespace manager
            {
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManager, ::java::lang::ObjectArray > ReplicationManagerArray;
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManagerClient, ::java::lang::ObjectArray > ReplicationManagerClientArray;
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManagerImpl, ::java::lang::ObjectArray, ReplicationManagerArray, ::rice::p2p::replication::ReplicationClientArray, ::rice::p2p::commonapi::ApplicationArray > ReplicationManagerImplArray;

                namespace testing
                {
typedef ::SubArray< ::rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient, ::java::lang::ObjectArray, ::rice::p2p::replication::manager::ReplicationManagerClientArray > ReplicationManagerRegrTest_TestReplicationManagerClientArray;
                } // testing
            } // manager
        } // replication
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::ReplicationManagerRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::ReplicationManagerRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : ReplicationManagerRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

constexpr int32_t rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::REPLICATION_FACTOR;

java::lang::String*& rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::INSTANCE()
{
    clinit();
    return INSTANCE_;
}
java::lang::String* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::INSTANCE_;

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
    replications = new ::rice::p2p::replication::manager::ReplicationManagerImplArray(NUM_NODES);
    clients = new ReplicationManagerRegrTest_TestReplicationManagerClientArray(NUM_NODES);
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = parseArgs(args);
    auto param = npc(env)->getParameters();
    npc(param)->setString(u"fileLogManager_filePrefix"_j, u"retest_"_j);
    npc(param)->setString(u"fileLogManager_fileSuffix"_j, u".log"_j);
    auto test = new ReplicationManagerRegrTest(env);
    npc(test)->start();
    npc(env)->destroy();
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::processNode(int32_t num, ::rice::p2p::commonapi::Node* node)
{
    clients->set(num, new ReplicationManagerRegrTest_TestReplicationManagerClient(this, node));
    replications->set(num, new ::rice::p2p::replication::manager::ReplicationManagerImpl(node, (*clients)[num], REPLICATION_FACTOR, INSTANCE_));
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::runTest()
{
    for (auto i = int32_t(0); i < NUM_NODES; i++) 
                simulate();

    testBasic();
    testOverload();
    testStress();
    testMaintenance();
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::testBasic()
{
    auto num = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES);
    auto id = npc((*nodes)[num])->getId();
    auto all = npc(FACTORY)->buildIdRange(npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))), npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))));
    sectionStart(u"Testing Basic Functionality"_j);
    stepStart(u"Inserting Object"_j);
    npc((*clients)[num])->insert(id);
    stepDone(SUCCESS());
    stepStart(u"Initiating Maintenance"_j);
    runMaintenance();
    for (auto i = int32_t(0); i < NUM_NODES; i++) 
                simulate();

    auto count = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        if(npc(npc((*clients)[i])->scan(all))->isMemberId(id))
            count++;

    }
    assertTrue(::java::lang::StringBuilder().append(u"Correct number of replicas should be "_j)->append((REPLICATION_FACTOR + int32_t(1)))
        ->append(u" was "_j)
        ->append(count)->toString(), count == REPLICATION_FACTOR + int32_t(1));
    stepDone(SUCCESS());
    sectionDone();
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::testMaintenance()
{
    auto num = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES);
    auto id = npc((*nodes)[num])->getId();
    auto all = npc(FACTORY)->buildIdRange(npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))), npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))));
    sectionStart(u"Testing Maintenance Functionality"_j);
    stepStart(u"Inserting Object"_j);
    npc((*clients)[num])->insert(id);
    stepDone(SUCCESS());
    stepStart(u"Initiating Maintenance"_j);
    runMaintenance();
    simulate();
    auto count = int32_t(0);
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        if(npc(npc((*clients)[i])->scan(all))->isMemberId(id))
            count++;

    }
    assertTrue(::java::lang::StringBuilder().append(u"Correct number of replicas should be "_j)->append((REPLICATION_FACTOR + int32_t(1)))
        ->append(u" was "_j)
        ->append(count)->toString(), count == REPLICATION_FACTOR + int32_t(1));
    stepDone(SUCCESS());
    stepStart(u"Killing Primary Replica"_j);
    kill(num);
    stepDone(SUCCESS());
    waitToRecoverFromKilling(5000);
    waitToRecoverFromKilling(5000);
    stepStart(u"Initiating Maintenance"_j);
    runMaintenance();
    simulate();
    count = 0;
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        if(npc(npc((*clients)[i])->scan(all))->isMemberId(id))
            count++;

    }
    assertTrue(::java::lang::StringBuilder().append(u"Correct number of replicas should be "_j)->append((REPLICATION_FACTOR + int32_t(2)))
        ->append(u" was "_j)
        ->append(count)->toString(), count == REPLICATION_FACTOR + int32_t(2));
    stepDone(SUCCESS());
    sectionDone();
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::testOverload()
{
    auto NUM_TO_INSERT = int32_t(16);
    auto num = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES);
    auto id = npc((*nodes)[num])->getId();
    auto all = npc(FACTORY)->buildIdRange(npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))), npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))));
    sectionStart(u"Testing Overload Functionality"_j);
    stepStart(::java::lang::StringBuilder().append(u"Inserting "_j)->append(NUM_TO_INSERT)
        ->append(u" Objects"_j)->toString());
    for (auto i = int32_t(0); i < NUM_TO_INSERT; i++) {
        npc((*clients)[num])->insert(addToId(id, i));
        simulate();
    }
    stepDone(SUCCESS());
    stepStart(u"Initiating Maintenance"_j);
    runMaintenance();
    simulate();
    for (auto i = int32_t(0); i < NUM_TO_INSERT + int32_t(1); i++) {
        try {
            ::java::lang::Thread::sleep(npc((*replications)[int32_t(0)])->FETCH_DELAY);
        } catch (::java::lang::InterruptedException* e) {
            npc(::java::lang::System::out())->println(npc(e)->toString());
        }
        simulate();
    }
    for (auto j = int32_t(0); j < NUM_TO_INSERT; j++) {
        auto count = int32_t(0);
        auto thisId = addToId(id, j);
        for (auto i = int32_t(0); i < NUM_NODES; i++) {
            if(npc(npc((*clients)[i])->scan(all))->isMemberId(thisId))
                count++;

        }
        assertTrue(::java::lang::StringBuilder().append(u"Correct number of replicas for "_j)->append(j)
            ->append(u":"_j)
            ->append(static_cast< ::java::lang::Object* >(thisId))
            ->append(u" should be "_j)
            ->append((REPLICATION_FACTOR + int32_t(1)))
            ->append(u" was "_j)
            ->append(count)->toString(), count == REPLICATION_FACTOR + int32_t(1));
    }
    stepDone(SUCCESS());
    sectionDone();
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::testStress()
{
    auto NUM_TO_INSERT = int32_t(45);
    auto ids = new ::rice::p2p::commonapi::IdArray(NUM_TO_INSERT);
    auto num = npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES);
    auto id = npc((*nodes)[num])->getId();
    auto all = npc(FACTORY)->buildIdRange(npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))), npc(FACTORY)->buildId(new ::int8_tArray(int32_t(20))));
    sectionStart(u"Testing Stressed Functionality"_j);
    stepStart(::java::lang::StringBuilder().append(u"Inserting "_j)->append(NUM_TO_INSERT)
        ->append(u" Objects"_j)->toString());
    for (auto i = int32_t(0); i < NUM_TO_INSERT; i++) {
        ids->set(i, addToId(id, i));
        npc((*clients)[num])->insert((*ids)[i]);
    }
    stepDone(SUCCESS());
    stepStart(u"Initiating Maintenance"_j);
    runMaintenance();
    simulate();
    try {
        ::java::lang::Thread::sleep(25000);
    } catch (::java::lang::InterruptedException* e) {
        npc(::java::lang::System::out())->println(npc(e)->toString());
    }
    simulate();
    for (auto j = int32_t(0); j < NUM_TO_INSERT; j++) {
        auto count = int32_t(0);
        auto thisId = (*ids)[j];
        for (auto i = int32_t(0); i < NUM_NODES; i++) {
            if(npc(npc((*clients)[i])->scan(all))->isMemberId(thisId))
                count++;

        }
        assertTrue(::java::lang::StringBuilder().append(u"Correct number of replicas for "_j)->append(j)
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(thisId))
            ->append(u" should be "_j)
            ->append((REPLICATION_FACTOR + int32_t(1)))
            ->append(u" was "_j)
            ->append(count)->toString(), count == REPLICATION_FACTOR + int32_t(1));
    }
    stepDone(SUCCESS());
    sectionDone();
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::printValsForRange(::rice::p2p::commonapi::IdRange* range)
{
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(i)->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >((*clients)[i]))
            ->append(u":"_j)
            ->append(static_cast< ::java::lang::Object* >(npc((*clients)[i])->scan(range)))->toString());
    }
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::runMaintenance()
{
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        auto const j = i;
        npc(npc(environment)->getSelectorManager())->invoke(new ReplicationManagerRegrTest_runMaintenance_1(this, j));
    }
    simulate();
}

rice::p2p::commonapi::Id* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::generateId()
{
    auto data = new ::int8_tArray(int32_t(20));
    npc(npc(environment)->getRandomSource())->nextBytes(data);
    return npc(FACTORY)->buildId(data);
}

rice::p2p::commonapi::Id* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::addToId(::rice::p2p::commonapi::Id* id, int32_t num)
{
    auto bytes = npc(id)->toByteArray_();
    (*bytes)[int32_t(0)] += num;
    return npc(FACTORY)->buildId(bytes);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.manager.testing.ReplicationManagerRegrTest", 63);
    return c;
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        INSTANCE_ = u"ReplicationRegrTest"_j;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest::getClass0()
{
    return class_();
}

