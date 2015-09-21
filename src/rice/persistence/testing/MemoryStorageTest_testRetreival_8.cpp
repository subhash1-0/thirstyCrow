// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testRetreival_8.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
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

rice::persistence::testing::MemoryStorageTest_testRetreival_8::MemoryStorageTest_testRetreival_8(MemoryStorageTest *MemoryStorageTest_this, ::rice::Continuation* get3)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , get3(get3)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testRetreival_8::receiveResult(::java::lang::Object* o)
{
    if(o == nullptr) {
        MemoryStorageTest_this->stepDone(Test::FAILURE(), u"Returned object was null."_j);
        return;
    }
    if(npc(o)->equals(u"Second Object"_j)) {
        MemoryStorageTest_this->stepDone(Test::SUCCESS());
    } else {
        MemoryStorageTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Returned object was not correct: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());
        return;
    }
    MemoryStorageTest_this->stepStart(u"Retrieving Third Object"_j);
    npc(MemoryStorageTest_this->storage)->getObject((*MemoryStorageTest_this->data)[int32_t(3)], get3);
}

void rice::persistence::testing::MemoryStorageTest_testRetreival_8::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRetreival_8::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRetreival_8::getClass0()
{
    return class_();
}

