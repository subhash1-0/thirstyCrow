// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/String.hpp>
#include <java/lang/Thread.hpp>
#include <java/util/HashSet.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/persistence/MemoryStorage.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRemoval_12.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRemoval_13.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRemoval_14.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRemoval_15.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testScan_16.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testScan_17.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testScan_18.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_19.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_20.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_21.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_22.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_23.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testErrors_24.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testErrors_25.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testErrors_26.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27.hpp>
#include <rice/persistence/testing/MemoryStorageTest_setUp_1.hpp>
#include <rice/persistence/testing/MemoryStorageTest_setUp_2.hpp>
#include <rice/persistence/testing/MemoryStorageTest_setUp_3.hpp>
#include <rice/persistence/testing/MemoryStorageTest_setUp_4.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRetreival_5.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRetreival_6.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRetreival_7.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRetreival_8.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRetreival_9.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testRetreival_10.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testExists_11.hpp>
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
typedef ::SubArray< ::java::lang::Number, ObjectArray, ::java::io::SerializableArray > NumberArray;
typedef ::SubArray< ::java::lang::Integer, NumberArray, ComparableArray > IntegerArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::MemoryStorageTest::MemoryStorageTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::testing::MemoryStorageTest::MemoryStorageTest(bool store, ::rice::environment::Environment* env) 
    : MemoryStorageTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(store,env);
}

void rice::persistence::testing::MemoryStorageTest::ctor(bool store, ::rice::environment::Environment* env)
{
    super::ctor(env);
    FACTORY = new ::rice::pastry::commonapi::PastryIdFactory(env);
    storage = new ::rice::persistence::MemoryStorage(FACTORY);
    data = new ::rice::p2p::commonapi::IdArray(int32_t(500));
    metadata = new ::java::lang::IntegerArray(int32_t(500));
    auto x = new ::int32_tArray(int32_t(5));
    for (auto i = int32_t(0); i < 500; i++) {
        (*x)[int32_t(3)] = i;
        data->set(i, npc(FACTORY)->buildId(x));
        metadata->set(i, new ::java::lang::Integer(i));
    }
    this->store = store;
}

void rice::persistence::testing::MemoryStorageTest::setUp(::rice::Continuation* c)
{
    ::rice::Continuation* const put4 = new MemoryStorageTest_setUp_1(this, c);
    ::rice::Continuation* const put3 = new MemoryStorageTest_setUp_2(this, put4);
    ::rice::Continuation* const put2 = new MemoryStorageTest_setUp_3(this, put3);
    ::rice::Continuation* put1 = new MemoryStorageTest_setUp_4(this, put2);
    sectionStart(u"Storing Objects"_j);
    stepStart(u"Storing First Object"_j);
    npc(storage)->store((*data)[int32_t(1)], (*metadata)[int32_t(1)], u"First Object"_j, put1);
}

void rice::persistence::testing::MemoryStorageTest::testRetreival(::rice::Continuation* c)
{
    ::rice::Continuation* const get5 = new MemoryStorageTest_testRetreival_5(this, c);
    ::rice::Continuation* const get4 = new MemoryStorageTest_testRetreival_6(this, get5);
    ::rice::Continuation* const get3 = new MemoryStorageTest_testRetreival_7(this, get4);
    ::rice::Continuation* const get2 = new MemoryStorageTest_testRetreival_8(this, get3);
    ::rice::Continuation* const get1 = new MemoryStorageTest_testRetreival_9(this, get2);
    ::rice::Continuation* get0 = new MemoryStorageTest_testRetreival_10(this, get1);
    if(store) {
        setUp(get0);
    } else {
        npc(get1)->receiveResult(u"First Object"_j);
    }
}

void rice::persistence::testing::MemoryStorageTest::testExists(::rice::Continuation* c)
{
    testRetreival(new MemoryStorageTest_testExists_11(this, c));
}

void rice::persistence::testing::MemoryStorageTest::testRemoval(::rice::Continuation* c)
{
    ::rice::Continuation* const done1 = new MemoryStorageTest_testRemoval_12(this, c);
    ::rice::Continuation* const retrieve1 = new MemoryStorageTest_testRemoval_13(this);
    ::rice::Continuation* const check1 = new MemoryStorageTest_testRemoval_14(this, done1);
    ::rice::Continuation* remove1 = new MemoryStorageTest_testRemoval_15(this, check1);
    testExists(remove1);
}

void rice::persistence::testing::MemoryStorageTest::testScan(::rice::Continuation* c)
{
    ::rice::Continuation* const handleBadScan = new MemoryStorageTest_testScan_16(this, c);
    ::rice::Continuation* const query = new MemoryStorageTest_testScan_17(this, handleBadScan);
    ::rice::Continuation* insertString = new MemoryStorageTest_testScan_18(this, query);
    testRemoval(insertString);
}

void rice::persistence::testing::MemoryStorageTest::testRandomInserts(::rice::Continuation* c)
{
    auto const START_NUM = int32_t(10);
    auto const END_NUM = int32_t(98);
    auto const SKIP = int32_t(2);
    auto const NUM_ELEMENTS = int32_t(1) + ((END_NUM - START_NUM) / SKIP);
    ::rice::Continuation* const checkRandom = new MemoryStorageTest_testRandomInserts_19(this, START_NUM, END_NUM, SKIP, NUM_ELEMENTS, c);
    ::rice::Continuation* const removeRandom = new MemoryStorageTest_testRandomInserts_20(this, START_NUM, END_NUM, checkRandom, SKIP);
    ::rice::Continuation* const checkScan = new MemoryStorageTest_testRandomInserts_21(this, START_NUM, END_NUM, SKIP, NUM_ELEMENTS, removeRandom);
    ::rice::Continuation* const checkExists = new MemoryStorageTest_testRandomInserts_22(this, START_NUM, END_NUM, SKIP, checkScan);
    ::rice::Continuation* const insert = new MemoryStorageTest_testRandomInserts_23(this, START_NUM, END_NUM, checkExists, SKIP);
    testScan(insert);
}

void rice::persistence::testing::MemoryStorageTest::testErrors(::rice::Continuation* c)
{
    ::rice::Continuation* const validateNullValue = new MemoryStorageTest_testErrors_24(this, c);
    ::rice::Continuation* const insertNullValue = new MemoryStorageTest_testErrors_25(this, validateNullValue);
    ::rice::Continuation* const insertNullKey = new MemoryStorageTest_testErrors_26(this, insertNullValue);
    testRandomInserts(insertNullKey);
}

void rice::persistence::testing::MemoryStorageTest::testVariableLength()
{
    auto const tmp = new ::java::util::HashSet();
    auto const all = new ::java::util::HashSet();
    testErrors(new MemoryStorageTest_testVariableLength_27(this, all, tmp));
}

void rice::persistence::testing::MemoryStorageTest::start()
{
    testVariableLength();
    try {
        ::java::lang::Thread::sleep(20000);
    } catch (::java::lang::InterruptedException* ie) {
        ;
    }
}

void rice::persistence::testing::MemoryStorageTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto test = new MemoryStorageTest(true, new ::rice::environment::Environment());
    npc(test)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.testing.MemoryStorageTest", 42);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest::getClass0()
{
    return class_();
}

