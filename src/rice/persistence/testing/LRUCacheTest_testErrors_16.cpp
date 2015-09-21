// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testErrors_16.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/testing/LRUCacheTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::LRUCacheTest_testErrors_16::LRUCacheTest_testErrors_16(LRUCacheTest *LRUCacheTest_this, ::rice::Continuation* insertNullValue)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , insertNullValue(insertNullValue)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testErrors_16::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        LRUCacheTest_this->stepDone(Test::FAILURE(), u"Randon insert tests failed."_j);
        return;
    }
    LRUCacheTest_this->sectionStart(u"Testing Error Cases"_j);
    LRUCacheTest_this->stepStart(u"Inserting null key"_j);
    npc(LRUCacheTest_this->cache)->cache(nullptr, nullptr, u"null key"_j, insertNullValue);
}

void rice::persistence::testing::LRUCacheTest_testErrors_16::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testErrors_16::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testErrors_16::getClass0()
{
    return class_();
}

