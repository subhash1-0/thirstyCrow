// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_21.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
#include <rice/persistence/testing/Test.hpp>
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

rice::persistence::testing::MemoryStorageTest_testRandomInserts_21::MemoryStorageTest_testRandomInserts_21(MemoryStorageTest *MemoryStorageTest_this, int32_t START_NUM, int32_t END_NUM, int32_t SKIP, int32_t NUM_ELEMENTS, ::rice::Continuation* removeRandom)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , START_NUM(START_NUM)
    , END_NUM(END_NUM)
    , SKIP(SKIP)
    , NUM_ELEMENTS(NUM_ELEMENTS)
    , removeRandom(removeRandom)
{
    clinit();
    init();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_21::init()
{
    count = START_NUM;
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_21::receiveResult(::java::lang::Object* o)
{
    MemoryStorageTest_this->stepStart(u"Checking scans for all ranges"_j);
    for (auto count = START_NUM; count < END_NUM - SKIP; count += SKIP) {
        auto result = npc(MemoryStorageTest_this->storage)->scan(npc(MemoryStorageTest_this->FACTORY)->buildIdRange((*MemoryStorageTest_this->data)[int32_t(13) + (count += SKIP)], (*MemoryStorageTest_this->data)[int32_t(13) + END_NUM]));
        auto i = NUM_ELEMENTS - ((count - START_NUM + SKIP) / SKIP);
        if(npc(result)->numElements() != i) {
            MemoryStorageTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Expected "_j)->append(i)
                ->append(u" found "_j)
                ->append(npc(result)->numElements())
                ->append(u" keys in scan from "_j)
                ->append(count)
                ->append(u" to "_j)
                ->append(END_NUM)
                ->append(u"."_j)->toString());
            return;
        }
    }
    MemoryStorageTest_this->stepDone(Test::SUCCESS());
    npc(removeRandom)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_21::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRandomInserts_21::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRandomInserts_21::getClass0()
{
    return class_();
}

