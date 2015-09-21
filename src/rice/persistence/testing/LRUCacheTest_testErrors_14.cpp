// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testErrors_14.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/persistence/testing/LRUCacheTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::LRUCacheTest_testErrors_14::LRUCacheTest_testErrors_14(LRUCacheTest *LRUCacheTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testErrors_14::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(true))) {
        LRUCacheTest_this->stepDone(Test::FAILURE(), u"Null value should return false"_j);
        return;
    }
    LRUCacheTest_this->stepDone(Test::SUCCESS());
    LRUCacheTest_this->sectionEnd();
}

void rice::persistence::testing::LRUCacheTest_testErrors_14::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testErrors_14::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testErrors_14::getClass0()
{
    return class_();
}

