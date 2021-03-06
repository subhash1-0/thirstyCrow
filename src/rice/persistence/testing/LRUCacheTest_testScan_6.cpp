// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_testScan_6.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/persistence/testing/LRUCacheTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::LRUCacheTest_testScan_6::LRUCacheTest_testScan_6(LRUCacheTest *LRUCacheTest_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_testScan_6::receiveResult(::java::lang::Object* o)
{
    LRUCacheTest_this->stepDone(Test::FAILURE(), u"Query returned; should have thrown exception"_j);
}

void rice::persistence::testing::LRUCacheTest_testScan_6::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepDone(Test::SUCCESS());
    LRUCacheTest_this->sectionEnd();
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_testScan_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_testScan_6::getClass0()
{
    return class_();
}

