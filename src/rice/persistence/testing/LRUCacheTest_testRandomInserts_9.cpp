// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_9.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
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

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::LRUCacheTest_testRandomInserts_9::LRUCacheTest_testRandomInserts_9(LRUCacheTest *LRUCacheTest_this, int32_t START_NUM, int32_t END_NUM, int32_t SKIP, int32_t NUM_ELEMENTS, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , START_NUM(START_NUM)
    , END_NUM(END_NUM)
    , SKIP(SKIP)
    , NUM_ELEMENTS(NUM_ELEMENTS)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testRandomInserts_9::receiveResult(::java::lang::Object* o)
{
    LRUCacheTest_this->stepStart(u"Checking object deletion"_j);
    auto NUM_DELETED = npc((java_cast< ::java::lang::Integer* >(o)))->intValue();
    auto length = npc(npc(LRUCacheTest_this->cache)->scan(npc(LRUCacheTest_this->FACTORY)->buildIdRange((*LRUCacheTest_this->data)[int32_t(13) + START_NUM], (*LRUCacheTest_this->data)[int32_t(13) + END_NUM + SKIP])))->numElements();
    auto desired = NUM_ELEMENTS - NUM_DELETED;
    if(length == desired) {
        LRUCacheTest_this->stepDone(Test::SUCCESS());
        LRUCacheTest_this->sectionEnd();
        npc(c)->receiveResult(new ::java::lang::Boolean(true));
    } else {
        LRUCacheTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Expected "_j)->append(desired)
            ->append(u" objects after deletes, found "_j)
            ->append(length)
            ->append(u"."_j)->toString());
        return;
    }
}

void rice::persistence::testing::LRUCacheTest_testRandomInserts_9::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testRandomInserts_9::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testRandomInserts_9::getClass0()
{
    return class_();
}

