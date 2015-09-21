// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_11.hpp>

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

rice::persistence::testing::LRUCacheTest_testRandomInserts_11::LRUCacheTest_testRandomInserts_11(LRUCacheTest *LRUCacheTest_this, int32_t START_NUM, int32_t SKIP, int32_t END_NUM, int32_t LAST_NUM_REMAINING, ::rice::Continuation* removeRandom)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , START_NUM(START_NUM)
    , SKIP(SKIP)
    , END_NUM(END_NUM)
    , LAST_NUM_REMAINING(LAST_NUM_REMAINING)
    , removeRandom(removeRandom)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testRandomInserts_11::receiveResult(::java::lang::Object* o)
{
    LRUCacheTest_this->stepStart(u"Checking exists for all 50 objects"_j);
    for (auto count = START_NUM - SKIP; count < END_NUM; count += SKIP) {
        auto b = new ::java::lang::Boolean(npc(LRUCacheTest_this->cache)->exists((*LRUCacheTest_this->data)[int32_t(13) + count]));
        if(npc(b)->equals(static_cast< ::java::lang::Object* >(new ::java::lang::Boolean(count < LAST_NUM_REMAINING)))) {
            if(npc(b)->booleanValue()) {
                LRUCacheTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Element "_j)->append(count)
                    ->append(u" did exist - should not have."_j)->toString());
                return;
            } else {
                LRUCacheTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Element "_j)->append(count)
                    ->append(u" did not exist - should have."_j)->toString());
                return;
            }
        }
    }
    LRUCacheTest_this->stepDone(Test::SUCCESS());
    npc(removeRandom)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::testing::LRUCacheTest_testRandomInserts_11::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testRandomInserts_11::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testRandomInserts_11::getClass0()
{
    return class_();
}

