// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testScan_16.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::MemoryStorageTest_testScan_16::MemoryStorageTest_testScan_16(MemoryStorageTest *MemoryStorageTest_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , c(c)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testScan_16::receiveResult(::java::lang::Object* o)
{
    MemoryStorageTest_this->stepDone(Test::FAILURE(), u"Query returned; should have thrown exception"_j);
}

void rice::persistence::testing::MemoryStorageTest_testScan_16::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepDone(Test::SUCCESS());
    MemoryStorageTest_this->sectionEnd();
    npc(c)->receiveResult(new ::java::lang::Boolean(true));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testScan_16::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testScan_16::getClass0()
{
    return class_();
}

