// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testScan_18.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
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

rice::persistence::testing::MemoryStorageTest_testScan_18::MemoryStorageTest_testScan_18(MemoryStorageTest *MemoryStorageTest_this, ::rice::Continuation* query)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , query(query)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testScan_18::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(true))) {
        MemoryStorageTest_this->sectionStart(u"Testing Scan"_j);
        MemoryStorageTest_this->stepStart(u"Inserting String as Key"_j);
        npc(MemoryStorageTest_this->storage)->store((*MemoryStorageTest_this->data)[int32_t(11)], nullptr, u"Monkey"_j, query);
    } else {
        MemoryStorageTest_this->stepException(new ::java::lang::RuntimeException(u"Removal did not complete correctly."_j));
    }
}

void rice::persistence::testing::MemoryStorageTest_testScan_18::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testScan_18::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testScan_18::getClass0()
{
    return class_();
}

