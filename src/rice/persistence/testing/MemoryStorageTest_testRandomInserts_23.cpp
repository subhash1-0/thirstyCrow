// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testRandomInserts_23.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
#include <rice/persistence/testing/Test.hpp>
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

rice::persistence::testing::MemoryStorageTest_testRandomInserts_23::MemoryStorageTest_testRandomInserts_23(MemoryStorageTest *MemoryStorageTest_this, int32_t START_NUM, int32_t END_NUM, ::rice::Continuation* checkExists, int32_t SKIP)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , START_NUM(START_NUM)
    , END_NUM(END_NUM)
    , checkExists(checkExists)
    , SKIP(SKIP)
{
    clinit();
    init();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_23::init()
{
    count = START_NUM;
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_23::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        MemoryStorageTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Insertion of "_j)->append(count)
            ->append(u" failed."_j)->toString());
        return;
    }
    if(count == START_NUM) {
        MemoryStorageTest_this->sectionStart(u"Stress Testing"_j);
        MemoryStorageTest_this->stepStart(u"Inserting 40 objects from 100 to 1000000 bytes"_j);
    }
    if(count > END_NUM) {
        MemoryStorageTest_this->stepDone(Test::SUCCESS());
        npc(checkExists)->receiveResult(new ::java::lang::Boolean(true));
        return;
    }
    auto num = count;
    count += SKIP;
    npc(MemoryStorageTest_this->storage)->store((*MemoryStorageTest_this->data)[int32_t(13) + num], nullptr, new ::int8_tArray(num * num), this);
}

void rice::persistence::testing::MemoryStorageTest_testRandomInserts_23::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRandomInserts_23::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRandomInserts_23::getClass0()
{
    return class_();
}

