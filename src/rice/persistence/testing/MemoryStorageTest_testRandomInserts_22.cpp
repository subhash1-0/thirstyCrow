// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_22.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
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

rice::persistence::testing::MemoryStorageTest_testRandomInserts_22::MemoryStorageTest_testRandomInserts_22(MemoryStorageTest *MemoryStorageTest_this, int32_t START_NUM, int32_t END_NUM, int32_t SKIP, ::rice::Continuation* checkScan)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , START_NUM(START_NUM)
    , END_NUM(END_NUM)
    , SKIP(SKIP)
    , checkScan(checkScan)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_22::receiveResult(::java::lang::Object* o)
{
    MemoryStorageTest_this->stepStart(u"Checking exists for all 50 objects"_j);
    for (auto count = START_NUM; count < END_NUM; count += SKIP) {
        auto b = npc(MemoryStorageTest_this->storage)->exists((*MemoryStorageTest_this->data)[int32_t(13) + count]);
        if(!b) {
            MemoryStorageTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Element "_j)->append(count)
                ->append(u" did exist ("_j)
                ->append(npc((*MemoryStorageTest_this->data)[int32_t(13) + count])->toStringFull())
                ->append(u") - should not have (START "_j)
                ->append(START_NUM)
                ->append(u" END "_j)
                ->append(END_NUM)
                ->append(u")."_j)->toString());
            return;
        }
    }
    MemoryStorageTest_this->stepDone(Test::SUCCESS());
    npc(checkScan)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_22::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRandomInserts_22::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRandomInserts_22::getClass0()
{
    return class_();
}

