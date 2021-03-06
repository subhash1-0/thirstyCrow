// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_setUp_4.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/testing/LRUCacheTest.hpp>
#include <rice/persistence/testing/Test.hpp>
#include <Array.hpp>
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

rice::persistence::testing::LRUCacheTest_setUp_4::LRUCacheTest_setUp_4(LRUCacheTest *LRUCacheTest_this, ::rice::Continuation* put2)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , put2(put2)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_setUp_4::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(true))) {
        LRUCacheTest_this->stepDone(Test::SUCCESS());
    } else {
        LRUCacheTest_this->stepDone(Test::FAILURE());
    }
    LRUCacheTest_this->stepStart(u"Inserting Second Object (40 bytes)"_j);
    npc(LRUCacheTest_this->cache)->cache((*LRUCacheTest_this->data)[int32_t(2)], nullptr, new ::int8_tArray(int32_t(13)), put2);
}

void rice::persistence::testing::LRUCacheTest_setUp_4::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_setUp_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_setUp_4::getClass0()
{
    return class_();
}

