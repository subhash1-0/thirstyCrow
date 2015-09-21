// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testLookupHandles_5.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testCaching_6.hpp>
#include <rice/p2p/past/testing/PastRegrTest_PastRegrTest_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3.hpp>
#include <rice/p2p/past/testing/PastRegrTest_NonMutableTestPastContent.hpp>
#include <rice/p2p/past/testing/PastRegrTest_NonOverwritingTestPastContent.hpp>
#include <rice/p2p/past/testing/PastRegrTest_TestPastContent.hpp>
#include <rice/p2p/past/testing/PastRegrTest_TestPastContentHandle.hpp>
#include <rice/p2p/past/testing/PastRegrTest_VersionedTestPastContent.hpp>
#include <rice/p2p/replication/Replication.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerClient.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/Catalog.hpp>
#include <rice/persistence/LRUCache.hpp>
#include <rice/persistence/MemoryStorage.hpp>
#include <rice/persistence/PersistentStorage.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/StorageManager.hpp>
#include <rice/persistence/StorageManagerImpl.hpp>
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
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::File, ::java::lang::ObjectArray, SerializableArray, ::java::lang::ComparableArray > FileArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
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
        } // commonapi

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::Past, ::java::lang::ObjectArray > PastArray;
        } // past

        namespace replication
        {
            namespace manager
            {
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManagerClient, ::java::lang::ObjectArray > ReplicationManagerClientArray;
            } // manager
        } // replication

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastImpl, ::java::lang::ObjectArray, PastArray, ::rice::p2p::commonapi::ApplicationArray, ::rice::p2p::replication::manager::ReplicationManagerClientArray > PastImplArray;
        } // past
    } // p2p

    namespace persistence
    {
typedef ::SubArray< ::rice::persistence::Catalog, ::java::lang::ObjectArray > CatalogArray;
typedef ::SubArray< ::rice::persistence::Cache, ::java::lang::ObjectArray, CatalogArray > CacheArray;
typedef ::SubArray< ::rice::persistence::Storage, ::java::lang::ObjectArray, CatalogArray > StorageArray;
typedef ::SubArray< ::rice::persistence::StorageManager, ::java::lang::ObjectArray, CacheArray, StorageArray > StorageManagerArray;
    } // persistence
} // rice

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

rice::p2p::past::testing::PastRegrTest::PastRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::PastRegrTest::PastRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : PastRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::p2p::past::testing::PastRegrTest::init()
{
    running = true;
}

java::lang::String*& rice::p2p::past::testing::PastRegrTest::INSTANCE()
{
    clinit();
    return INSTANCE_;
}
java::lang::String* rice::p2p::past::testing::PastRegrTest::INSTANCE_;

constexpr int32_t rice::p2p::past::testing::PastRegrTest::REPLICATION_FACTOR;

void rice::p2p::past::testing::PastRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
    init();
    pasts = new ::rice::p2p::past::PastImplArray(NUM_NODES);
    storages = new ::rice::persistence::StorageManagerArray(NUM_NODES);
    if(PROTOCOL == PROTOCOL_DIRECT()) {
        (new PastRegrTest_PastRegrTest_1(this))->start();
    }
}

void rice::p2p::past::testing::PastRegrTest::processNode(int32_t num, ::rice::p2p::commonapi::Node* node)
{
    try {
        storages->set(num, new ::rice::persistence::StorageManagerImpl(FACTORY, new ::rice::persistence::PersistentStorage(FACTORY, ::java::lang::StringBuilder().append(u"root-"_j)->append(num)->toString(), u"."_j, int32_t(1000000), environment), new ::rice::persistence::LRUCache(new ::rice::persistence::MemoryStorage(FACTORY), int32_t(100000), environment)));
        pasts->set(num, new ::rice::p2p::past::PastImpl(node, (*storages)[num], REPLICATION_FACTOR, INSTANCE_));
    } catch (::java::io::IOException* e) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
    }
}

void rice::p2p::past::testing::PastRegrTest::runTest()
{
    if(NUM_NODES < 2) {
        npc(::java::lang::System::out())->println(u"The DistPastRegrTest must be run with at least 2 nodes for proper testing.  Use the '-nodes n' to specify the number of nodes."_j);
        return;
    }
    testRouteRequest();
}

void rice::p2p::past::testing::PastRegrTest::testRouteRequest()
{
    auto const local = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const remote = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const remoteId = npc(npc(remote)->getLocalNodeHandle())->getId();
    ::rice::p2p::past::PastContent* const file = new PastRegrTest_TestPastContent(remoteId);
    sectionStart(u"Simple Route Request"_j);
    stepStart(u"Initial Lookup"_j);
    npc(local)->lookup(remoteId, static_cast< ::rice::Continuation* >(new PastRegrTest_testRouteRequest_2(this, local, file, remoteId, remote)));
    simulate();
}

void rice::p2p::past::testing::PastRegrTest::testVersionControl()
{
    auto const local = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const remote = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const remoteId = npc(npc(remote)->getLocalNodeHandle())->getId();
    ::rice::p2p::past::PastContent* const oldFile = new PastRegrTest_VersionedTestPastContent(remoteId, int32_t(0));
    ::rice::p2p::past::PastContent* const newFile = new PastRegrTest_VersionedTestPastContent(remoteId, int32_t(1));
    ::rice::p2p::past::PastContent* const newNewFile = new PastRegrTest_NonOverwritingTestPastContent(remoteId, int32_t(2));
    sectionStart(u"Version Control"_j);
    stepStart(u"File Insertion"_j);
    npc(local)->insert(oldFile, static_cast< ::rice::Continuation* >(new PastRegrTest_testVersionControl_3(this, local, remoteId, oldFile, newFile, newNewFile)));
    simulate();
}

void rice::p2p::past::testing::PastRegrTest::testFetch()
{
    auto const local = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const remote1 = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto tmp = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    while (tmp == remote1) {
        tmp = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    }
    auto const remote2 = tmp;
    auto const id = npc(npc((*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)])->getLocalNodeHandle())->getId();
    ::rice::p2p::past::PastContent* const file1 = new PastRegrTest_VersionedTestPastContent(id, int32_t(1));
    ::rice::p2p::past::PastContent* const file2 = new PastRegrTest_VersionedTestPastContent(id, int32_t(2));
    ::rice::p2p::past::PastContentHandle* const handle1 = new PastRegrTest_TestPastContentHandle(remote1, id);
    ::rice::p2p::past::PastContentHandle* const handle2 = new PastRegrTest_TestPastContentHandle(remote2, id);
    sectionStart(u"Fetch Testing"_j);
    stepStart(u"File 1 Insertion"_j);
    npc(npc(remote1)->getStorageManager())->store(id, nullptr, file1, new PastRegrTest_testFetch_4(this, remote2, id, file2, local, handle1, file1, handle2, remote1));
    simulate();
}

void rice::p2p::past::testing::PastRegrTest::testLookupHandles()
{
    auto const local = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const remote = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const remoteId = npc(npc(remote)->getLocalNodeHandle())->getId();
    ::rice::p2p::past::PastContent* const file = new PastRegrTest_TestPastContent(remoteId);
    sectionStart(u"Lookup Handles Testing"_j);
    stepStart(u"File Insertion"_j);
    npc(local)->insert(file, static_cast< ::rice::Continuation* >(new PastRegrTest_testLookupHandles_5(this, local, remoteId)));
    simulate();
}

void rice::p2p::past::testing::PastRegrTest::testCaching()
{
    auto const local = (*pasts)[npc(npc(environment)->getRandomSource())->nextInt(NUM_NODES)];
    auto const id1 = generateId();
    auto const id2 = generateId();
    ::rice::p2p::past::PastContent* const file1 = new PastRegrTest_TestPastContent(id1);
    ::rice::p2p::past::PastContent* const file2 = new PastRegrTest_TestPastContent(id2);
    ::rice::p2p::past::PastContent* const file3 = new PastRegrTest_NonMutableTestPastContent(id2);
    sectionStart(u"Caching Testing"_j);
    stepStart(u"Manually Inserting Object Into Cache"_j);
    npc(npc(npc(local)->getStorageManager())->getCache())->cache(id1, nullptr, file1, new PastRegrTest_testCaching_6(this, local, id1, file1, id2, file2, file3));
    simulate();
}

void rice::p2p::past::testing::PastRegrTest::runReplicaMaintence()
{
    for (auto i = int32_t(0); i < NUM_NODES; i++) {
        npc(npc((*pasts)[i])->getReplication())->replicate();
    }
    simulate();
}

rice::p2p::commonapi::Id* rice::p2p::past::testing::PastRegrTest::generateId()
{
    auto data = new ::int8_tArray(int32_t(20));
    npc(npc(environment)->getRandomSource())->nextBytes(data);
    return npc(FACTORY)->buildId(data);
}

void rice::p2p::past::testing::PastRegrTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto delme = new ::java::util::LinkedList();
    npc(delme)->add(static_cast< ::java::lang::Object* >(new ::java::io::File(u"FreePastry-Storage-Root"_j)));
    while (!npc(delme)->isEmpty()) {
        auto f = java_cast< ::java::io::File* >(java_cast< ::java::lang::Object* >(npc(delme)->removeFirst()));
        if(npc(f)->isDirectory()) {
            auto subs = npc(f)->listFiles();
            if(npc(subs)->length == 0) {
                npc(f)->delete_();
            } else {
                npc(delme)->addAll(static_cast< ::java::util::Collection* >(::java::util::Arrays::asList(subs)));
                npc(delme)->addLast(static_cast< ::java::lang::Object* >(f));
            }
        } else {
            npc(f)->delete_();
        }
    }
    auto env = parseArgs(args);
    npc(npc(env)->getParameters())->setDouble(u"p2p_past_successfulInsertThreshold"_j, 1.0);
    auto pastTest = new PastRegrTest(env);
    npc(pastTest)->start();
}

void rice::p2p::past::testing::PastRegrTest::cleanUp()
{
    running = false;
    npc(environment)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.PastRegrTest", 34);
    return c;
}

void rice::p2p::past::testing::PastRegrTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        INSTANCE_ = u"PastRegrTest"_j;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest::getClass0()
{
    return class_();
}

