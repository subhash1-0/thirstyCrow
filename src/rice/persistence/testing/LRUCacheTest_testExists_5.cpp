// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testExists_5.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/testing/LRUCacheTest.hpp>
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

rice::persistence::testing::LRUCacheTest_testExists_5::LRUCacheTest_testExists_5(LRUCacheTest *LRUCacheTest_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testExists_5::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(true))) {
        LRUCacheTest_this->sectionStart(u"Checking for Objects"_j);
        LRUCacheTest_this->stepStart(u"Checking for First Object"_j);
        if(npc(LRUCacheTest_this->cache)->exists((*LRUCacheTest_this->data)[int32_t(1)]))
            LRUCacheTest_this->stepDone(Test::SUCCESS());
        else
            LRUCacheTest_this->stepDone(Test::FAILURE());
        LRUCacheTest_this->stepStart(u"Checking for Second Object"_j);
        if(npc(LRUCacheTest_this->cache)->exists((*LRUCacheTest_this->data)[int32_t(2)]))
            LRUCacheTest_this->stepDone(Test::SUCCESS());
        else
            LRUCacheTest_this->stepDone(Test::FAILURE());
        LRUCacheTest_this->stepStart(u"Checking for Third Object"_j);
        if(npc(LRUCacheTest_this->cache)->exists((*LRUCacheTest_this->data)[int32_t(3)]))
            LRUCacheTest_this->stepDone(Test::SUCCESS());
        else
            LRUCacheTest_this->stepDone(Test::FAILURE());
        LRUCacheTest_this->stepStart(u"Checking for Fourth Object"_j);
        if(npc(LRUCacheTest_this->cache)->exists((*LRUCacheTest_this->data)[int32_t(4)]))
            LRUCacheTest_this->stepDone(Test::SUCCESS());
        else
            LRUCacheTest_this->stepDone(Test::FAILURE());
        LRUCacheTest_this->stepStart(u"Checking for Fifth Object"_j);
        if(npc(LRUCacheTest_this->cache)->exists((*LRUCacheTest_this->data)[int32_t(5)]))
            LRUCacheTest_this->stepDone(Test::SUCCESS());
        else
            LRUCacheTest_this->stepDone(Test::FAILURE());
        LRUCacheTest_this->sectionEnd();
        npc(c)->receiveResult(new ::java::lang::Boolean(true));
    } else {
        throw new ::java::lang::RuntimeException(u"SetUp did not complete correctly!"_j);
    }
}

void rice::persistence::testing::LRUCacheTest_testExists_5::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testExists_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testExists_5::getClass0()
{
    return class_();
}

