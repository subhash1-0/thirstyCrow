// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testRemoval_14.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
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

rice::persistence::testing::MemoryStorageTest_testRemoval_14::MemoryStorageTest_testRemoval_14(MemoryStorageTest *MemoryStorageTest_this, ::rice::Continuation* done1)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , done1(done1)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testRemoval_14::receiveResult(::java::lang::Object* o)
{
    if((!MemoryStorageTest_this->store) || npc(o)->equals(new ::java::lang::Boolean(true))) {
        MemoryStorageTest_this->stepDone(Test::SUCCESS());
    } else {
        MemoryStorageTest_this->stepDone(Test::FAILURE());
    }
    MemoryStorageTest_this->stepStart(u"Checking for First Object"_j);
    auto result = npc(MemoryStorageTest_this->storage)->exists((*MemoryStorageTest_this->data)[int32_t(1)]);
    if((!MemoryStorageTest_this->store) || (!result)) {
        MemoryStorageTest_this->stepDone(Test::SUCCESS());
    } else {
        MemoryStorageTest_this->stepDone(Test::FAILURE());
    }
    MemoryStorageTest_this->stepStart(u"Attempting to Retrieve First Object"_j);
    npc(MemoryStorageTest_this->storage)->getObject((*MemoryStorageTest_this->data)[int32_t(1)], done1);
}

void rice::persistence::testing::MemoryStorageTest_testRemoval_14::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRemoval_14::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRemoval_14::getClass0()
{
    return class_();
}

