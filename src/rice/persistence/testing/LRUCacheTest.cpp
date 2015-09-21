// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/LRUCache.hpp>
#include <rice/persistence/MemoryStorage.hpp>
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_11.hpp>
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_12.hpp>
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_13.hpp>
#include <rice/persistence/testing/LRUCacheTest_testErrors_14.hpp>
#include <rice/persistence/testing/LRUCacheTest_testErrors_15.hpp>
#include <rice/persistence/testing/LRUCacheTest_testErrors_16.hpp>
#include <rice/persistence/testing/LRUCacheTest_setUp_1.hpp>
#include <rice/persistence/testing/LRUCacheTest_setUp_2.hpp>
#include <rice/persistence/testing/LRUCacheTest_setUp_3.hpp>
#include <rice/persistence/testing/LRUCacheTest_setUp_4.hpp>
#include <rice/persistence/testing/LRUCacheTest_testExists_5.hpp>
#include <rice/persistence/testing/LRUCacheTest_testScan_6.hpp>
#include <rice/persistence/testing/LRUCacheTest_testScan_7.hpp>
#include <rice/persistence/testing/LRUCacheTest_testScan_8.hpp>
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_9.hpp>
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_10.hpp>
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

rice::persistence::testing::LRUCacheTest::LRUCacheTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::testing::LRUCacheTest::LRUCacheTest(::rice::environment::Environment* env) 
    : LRUCacheTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

constexpr int32_t rice::persistence::testing::LRUCacheTest::CACHE_SIZE;

void rice::persistence::testing::LRUCacheTest::ctor(::rice::environment::Environment* env)
{
    super::ctor(env);
    cache = new ::rice::persistence::LRUCache(new ::rice::persistence::MemoryStorage(FACTORY), CACHE_SIZE, env);
    FACTORY = new ::rice::pastry::commonapi::PastryIdFactory(env);
    data = new ::rice::p2p::commonapi::IdArray(int32_t(500));
    auto x = new ::int32_tArray(int32_t(5));
    for (auto i = int32_t(0); i < 500; i++) {
        (*x)[int32_t(3)] = i;
        data->set(i, npc(FACTORY)->buildId(x));
    }
}

void rice::persistence::testing::LRUCacheTest::setUp(::rice::Continuation* c)
{
    ::rice::Continuation* const put4 = new LRUCacheTest_setUp_1(this, c);
    ::rice::Continuation* const put3 = new LRUCacheTest_setUp_2(this, put4);
    ::rice::Continuation* const put2 = new LRUCacheTest_setUp_3(this, put3);
    ::rice::Continuation* put1 = new LRUCacheTest_setUp_4(this, put2);
    sectionStart(u"Inserting Objects"_j);
    stepStart(u"Inserting First Object (30 bytes)"_j);
    npc(cache)->cache((*data)[int32_t(1)], nullptr, new ::int8_tArray(int32_t(3)), put1);
}

void rice::persistence::testing::LRUCacheTest::testExists(::rice::Continuation* c)
{
    setUp(new LRUCacheTest_testExists_5(this, c));
}

void rice::persistence::testing::LRUCacheTest::testScan(::rice::Continuation* c)
{
    ::rice::Continuation* const handleBadScan = new LRUCacheTest_testScan_6(this, c);
    ::rice::Continuation* const query = new LRUCacheTest_testScan_7(this, handleBadScan);
    ::rice::Continuation* insertString = new LRUCacheTest_testScan_8(this, query);
    testExists(insertString);
}

void rice::persistence::testing::LRUCacheTest::testRandomInserts(::rice::Continuation* c)
{
    auto const START_NUM = int32_t(10);
    auto const END_NUM = int32_t(98);
    auto const SKIP = int32_t(2);
    auto const NUM_ELEMENTS = int32_t(17);
    auto const LAST_NUM_REMAINING = int32_t(66);
    ::rice::Continuation* const checkRandom = new LRUCacheTest_testRandomInserts_9(this, START_NUM, END_NUM, SKIP, NUM_ELEMENTS, c);
    ::rice::Continuation* const removeRandom = new LRUCacheTest_testRandomInserts_10(this, LAST_NUM_REMAINING, END_NUM, checkRandom, SKIP);
    ::rice::Continuation* const checkExists = new LRUCacheTest_testRandomInserts_11(this, START_NUM, SKIP, END_NUM, LAST_NUM_REMAINING, removeRandom);
    ::rice::Continuation* const insert = new LRUCacheTest_testRandomInserts_12(this, START_NUM, END_NUM, checkExists, SKIP);
    ::rice::Continuation* const setSize = new LRUCacheTest_testRandomInserts_13(this, insert);
    testScan(setSize);
}

void rice::persistence::testing::LRUCacheTest::testErrors()
{
    ::rice::Continuation* const validateNullValue = new LRUCacheTest_testErrors_14(this);
    ::rice::Continuation* const insertNullValue = new LRUCacheTest_testErrors_15(this, validateNullValue);
    ::rice::Continuation* const insertNullKey = new LRUCacheTest_testErrors_16(this, insertNullValue);
    testRandomInserts(insertNullKey);
}

void rice::persistence::testing::LRUCacheTest::start()
{
    testErrors();
}

void rice::persistence::testing::LRUCacheTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto test = new LRUCacheTest(new ::rice::environment::Environment());
    npc(test)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.testing.LRUCacheTest", 37);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest::getClass0()
{
    return class_();
}

