// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testExists_11.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testExists_11_receiveResult_11_1.hpp>
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
typedef ::SubArray< ::java::lang::Number, ObjectArray, ::java::io::SerializableArray > NumberArray;
typedef ::SubArray< ::java::lang::Integer, NumberArray, ComparableArray > IntegerArray;
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

rice::persistence::testing::MemoryStorageTest_testExists_11::MemoryStorageTest_testExists_11(MemoryStorageTest *MemoryStorageTest_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testExists_11::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(true))) {
        MemoryStorageTest_this->sectionStart(u"Checking for Objects"_j);
        MemoryStorageTest_this->stepStart(u"Checking for First Object"_j);
        if(npc(MemoryStorageTest_this->storage)->exists((*MemoryStorageTest_this->data)[int32_t(1)]))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Second Object"_j);
        if(npc(MemoryStorageTest_this->storage)->exists((*MemoryStorageTest_this->data)[int32_t(2)]))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Third Object"_j);
        if(npc(MemoryStorageTest_this->storage)->exists((*MemoryStorageTest_this->data)[int32_t(3)]))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Fourth Object"_j);
        if(npc(MemoryStorageTest_this->storage)->exists((*MemoryStorageTest_this->data)[int32_t(4)]))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Fifth Object"_j);
        if(!npc(MemoryStorageTest_this->storage)->exists((*MemoryStorageTest_this->data)[int32_t(5)]))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->sectionEnd();
        MemoryStorageTest_this->sectionStart(u"Checking for Metadata"_j);
        MemoryStorageTest_this->stepStart(u"Checking for First Object Metadata"_j);
        if(npc((*MemoryStorageTest_this->metadata)[int32_t(1)])->equals(static_cast< ::java::lang::Object* >(npc(MemoryStorageTest_this->storage)->getMetadata((*MemoryStorageTest_this->data)[int32_t(1)]))))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Second Object Metadata"_j);
        if(npc((*MemoryStorageTest_this->metadata)[int32_t(2)])->equals(static_cast< ::java::lang::Object* >(npc(MemoryStorageTest_this->storage)->getMetadata((*MemoryStorageTest_this->data)[int32_t(2)]))))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Third Object Metadata"_j);
        if(npc((*MemoryStorageTest_this->metadata)[int32_t(3)])->equals(static_cast< ::java::lang::Object* >(npc(MemoryStorageTest_this->storage)->getMetadata((*MemoryStorageTest_this->data)[int32_t(3)]))))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Fourth Object Metadata"_j);
        if(npc((*MemoryStorageTest_this->metadata)[int32_t(4)])->equals(static_cast< ::java::lang::Object* >(npc(MemoryStorageTest_this->storage)->getMetadata((*MemoryStorageTest_this->data)[int32_t(4)]))))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->stepStart(u"Checking for Fifth Object Metadata"_j);
        if(!npc((*MemoryStorageTest_this->metadata)[int32_t(5)])->equals(static_cast< ::java::lang::Object* >(npc(MemoryStorageTest_this->storage)->getMetadata((*MemoryStorageTest_this->data)[int32_t(5)]))))
            MemoryStorageTest_this->stepDone(Test::SUCCESS());
        else
            MemoryStorageTest_this->stepDone(Test::FAILURE());
        MemoryStorageTest_this->sectionEnd();
        MemoryStorageTest_this->sectionStart(u"Modifying Metadata"_j);
        MemoryStorageTest_this->stepStart(u"Changing Metadata"_j);
        npc(MemoryStorageTest_this->storage)->setMetadata((*MemoryStorageTest_this->data)[int32_t(4)], new ::java::lang::Integer(int32_t(5001)), new MemoryStorageTest_testExists_11_receiveResult_11_1(this, c));
    } else {
        throw new ::java::lang::RuntimeException(u"SetUp did not complete correctly!"_j);
    }
}

void rice::persistence::testing::MemoryStorageTest_testExists_11::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testExists_11::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testExists_11::getClass0()
{
    return class_();
}

