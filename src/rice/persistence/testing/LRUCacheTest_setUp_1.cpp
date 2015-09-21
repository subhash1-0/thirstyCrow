// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java
#include <rice/persistence/testing/LRUCacheTest_setUp_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/persistence/testing/LRUCacheTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::LRUCacheTest_setUp_1::LRUCacheTest_setUp_1(LRUCacheTest *LRUCacheTest_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , LRUCacheTest_this(LRUCacheTest_this)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::testing::LRUCacheTest_setUp_1::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        LRUCacheTest_this->stepDone(Test::SUCCESS());
    } else {
        LRUCacheTest_this->stepDone(Test::FAILURE());
    }
    LRUCacheTest_this->sectionEnd();
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::persistence::testing::LRUCacheTest_setUp_1::receiveException(::java::lang::Exception* e)
{
    LRUCacheTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::LRUCacheTest_setUp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::LRUCacheTest_setUp_1::getClass0()
{
    return class_();
}

