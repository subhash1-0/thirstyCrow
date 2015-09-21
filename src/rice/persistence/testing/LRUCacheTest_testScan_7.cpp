// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testScan_7.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::LRUCacheTest_testScan_7::LRUCacheTest_testScan_7(LRUCacheTest *LRUCacheTest_this, ::rice::Continuation* handleBadScan)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , handleBadScan(handleBadScan)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testScan_7::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(true))) {
        LRUCacheTest_this->stepDone(Test::SUCCESS());
    } else {
        LRUCacheTest_this->stepDone(Test::FAILURE());
    }
    LRUCacheTest_this->stepStart(u"Requesting Scan from 3 to 6"_j);
    auto result = npc(LRUCacheTest_this->cache)->scan(npc(LRUCacheTest_this->FACTORY)->buildIdRange((*LRUCacheTest_this->data)[int32_t(3)], (*LRUCacheTest_this->data)[int32_t(6)]));
    if(npc(result)->numElements() != 1) {
        LRUCacheTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Result had "_j)->append(npc(result)->numElements())
            ->append(u" elements, expected 1."_j)->toString());
        return;
    }
    if(!npc(result)->isMemberId((*LRUCacheTest_this->data)[int32_t(3)])) {
        LRUCacheTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Result had incorrect element "_j)->append(static_cast< ::java::lang::Object* >((*LRUCacheTest_this->data)[int32_t(3)]))
            ->append(u", expected 3."_j)->toString());
        return;
    }
    LRUCacheTest_this->stepDone(Test::SUCCESS());
    LRUCacheTest_this->stepStart(u"Requesting Scan from 8 to 10"_j);
    result = npc(LRUCacheTest_this->cache)->scan(npc(LRUCacheTest_this->FACTORY)->buildIdRange((*LRUCacheTest_this->data)[int32_t(8)], (*LRUCacheTest_this->data)[int32_t(10)]));
    if(npc(result)->numElements() != 0) {
        LRUCacheTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Result had "_j)->append(npc(result)->numElements())
            ->append(u" elements, expected 0."_j)->toString());
        return;
    }
    LRUCacheTest_this->stepDone(Test::SUCCESS());
    LRUCacheTest_this->stepStart(u"Requesting Scan from 'Monkey' to 9"_j);
    npc(handleBadScan)->receiveException(new ::java::lang::Exception());
}

void rice::persistence::testing::LRUCacheTest_testScan_7::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testScan_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testScan_7::getClass0()
{
    return class_();
}

