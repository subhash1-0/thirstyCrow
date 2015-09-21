// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testRemoval_13.hpp>

#include <rice/persistence/testing/MemoryStorageTest.hpp>

rice::persistence::testing::MemoryStorageTest_testRemoval_13::MemoryStorageTest_testRemoval_13(MemoryStorageTest *MemoryStorageTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testRemoval_13::receiveResult(::java::lang::Object* o)
{
}

void rice::persistence::testing::MemoryStorageTest_testRemoval_13::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRemoval_13::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testRemoval_13::getClass0()
{
    return class_();
}

