// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testExists_11_receiveResult_11_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testExists_11.hpp>
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

rice::persistence::testing::MemoryStorageTest_testExists_11_receiveResult_11_1::MemoryStorageTest_testExists_11_receiveResult_11_1(MemoryStorageTest_testExists_11 *MemoryStorageTest_testExists_11_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_testExists_11_this(MemoryStorageTest_testExists_11_this)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testExists_11_receiveResult_11_1::receiveResult(::java::lang::Object* o)
{
    MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->stepDone(Test::SUCCESS());
    MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->stepStart(u"Checking for New Metadata"_j);
    if((new ::java::lang::Integer(int32_t(5001)))->equals(static_cast< ::java::lang::Object* >(npc(MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->storage)->getMetadata((*MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->data)[int32_t(4)]))))
        MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->stepDone(Test::SUCCESS());
    else
        MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->stepDone(Test::FAILURE());
    MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->sectionEnd();
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::testing::MemoryStorageTest_testExists_11_receiveResult_11_1::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_testExists_11_this->MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testExists_11_receiveResult_11_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testExists_11_receiveResult_11_1::getClass0()
{
    return class_();
}

