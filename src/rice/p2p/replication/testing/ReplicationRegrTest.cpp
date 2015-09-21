// Generated from /pastry-2.1/src/rice/p2p/replication/testing/ReplicationRegrTest.java
#include <rice/p2p/replication/testing/ReplicationRegrTest.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Destructable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/replication/Replication.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>
#include <rice/p2p/replication/ReplicationImpl.hpp>
#include <rice/p2p/replication/testing/ReplicationRegrTest_TestReplicationClient.hpp>
#include <Array.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

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
typedef ::SubArray< ::rice::Destructable, ::java::lang::ObjectArray > DestructableArray;

    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
typedef ::SubArray< ::rice::p2p::commonapi::Node, ::java::lang::ObjectArray > NodeArray;
        } // commonapi

        namespace replication
        {
typedef ::SubArray< ::rice::p2p::replication::Replication, ::java::lang::ObjectArray > ReplicationArray;
typedef ::SubArray< ::rice::p2p::replication::ReplicationClient, ::java::lang::ObjectArray > ReplicationClientArray;
typedef ::SubArray< ::rice::p2p::replication::ReplicationImpl, ::java::lang::ObjectArray, ReplicationArray, ::rice::p2p::commonapi::ApplicationArray, ::rice::DestructableArray > ReplicationImplArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient, ::java::lang::ObjectArray, ::rice::p2p::replication::ReplicationClientArray > ReplicationRegrTest_TestReplicationClientArray;
            } // testing
        } // replication
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::testing::ReplicationRegrTest::ReplicationRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::testing::ReplicationRegrTest::ReplicationRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : ReplicationRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

constexpr int32_t rice::p2p::replication::testing::ReplicationRegrTest::REPLICATION_FACTOR;

java::lang::String*& rice::p2p::replication::testing::ReplicationRegrTest::INSTANCE()
{
    clinit();
    return INSTANCE_;
}
java::lang::String* rice::p2p::replication::testing::ReplicationRegrTest::INSTANCE_;

void rice::p2p::replication::testing::ReplicationRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
    replications = new ::rice::p2p::replication::ReplicationImplArray(NUM_NODES);
    clients = new ReplicationRegrTest_TestReplicationClientArray(NUM_NODES);
}

void rice::p2p::replication::testing::ReplicationRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = parseArgs(args);
    auto test = new ReplicationRegrTest(env);
    npc(test)->start();
    npc(env)->destroy();
}

void rice::p2p::replication::testing::ReplicationRegrTest::processNode(int32_t num, ::rice::p2p::commonapi::Node* node)
{
    clients->set(num, new ReplicationRegrTest_TestReplicationClient(this, node));
    replications->set(num, new ::rice::p2p::replication::ReplicationImpl(node, (*clients)[num], REPLICATION_FACTOR, INSTANCE_));
}

void rice::p2p::replication::testing::ReplicationRegrTest::runTest()
{
    testBasic();
    testMaintenance();
}

void rice::p2p::replication::testing::ReplicationRegrTest::testBasic()
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

void rice::p2p::replication::testing::ReplicationRegrTest::testMaintenance()
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
    waitToRecoverFromKilling(5000);
    stepDone(SUCCESS());
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

void rice::p2p::replication::testing::ReplicationRegrTest::runMaintenance()
{
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc((*replications)[i])->replicate();
    }
    simulate();
}

rice::p2p::commonapi::Id* rice::p2p::replication::testing::ReplicationRegrTest::generateId()
{
    auto data = new ::int8_tArray(int32_t(20));
    npc(npc(environment)->getRandomSource())->nextBytes(data);
    return npc(FACTORY)->buildId(data);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::testing::ReplicationRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.testing.ReplicationRegrTest", 48);
    return c;
}

void rice::p2p::replication::testing::ReplicationRegrTest::clinit()
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

java::lang::Class* rice::p2p::replication::testing::ReplicationRegrTest::getClass0()
{
    return class_();
}

