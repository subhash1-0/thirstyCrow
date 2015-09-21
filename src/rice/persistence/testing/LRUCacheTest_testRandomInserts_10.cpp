// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testRandomInserts_10.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
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

rice::persistence::testing::LRUCacheTest_testRandomInserts_10::LRUCacheTest_testRandomInserts_10(LRUCacheTest *LRUCacheTest_this, int32_t LAST_NUM_REMAINING, int32_t END_NUM, ::rice::Continuation* checkRandom, int32_t SKIP)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , LAST_NUM_REMAINING(LAST_NUM_REMAINING)
    , END_NUM(END_NUM)
    , checkRandom(checkRandom)
    , SKIP(SKIP)
{
    clinit();
    init();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testRandomInserts_10::init()
{
    count = LAST_NUM_REMAINING;
    num_deleted = int32_t(0);
}

void rice::persistence::testing::LRUCacheTest_testRandomInserts_10::receiveResult(::java::lang::Object* o)
{
    if(count == LAST_NUM_REMAINING) {
        LRUCacheTest_this->stepStart(u"Removing random subset of objects"_j);
    }
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        LRUCacheTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Deletion of "_j)->append(count)
            ->append(u" failed."_j)->toString());
        return;
    }
    if(count == END_NUM) {
        LRUCacheTest_this->stepDone(Test::SUCCESS());
        npc(checkRandom)->receiveResult(new ::java::lang::Integer(num_deleted));
        return;
    }
    if(npc(npc(LRUCacheTest_this->environment)->getRandomSource())->nextBoolean()) {
        num_deleted++;
        npc(LRUCacheTest_this->cache)->uncache((*LRUCacheTest_this->data)[int32_t(13) + (count += SKIP)], this);
    } else {
        count += SKIP;
        receiveResult(static_cast< ::java::lang::Object* >(new ::java::lang::Boolean(true)));
    }
}

void rice::persistence::testing::LRUCacheTest_testRandomInserts_10::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testRandomInserts_10::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testRandomInserts_10::getClass0()
{
    return class_();
}

