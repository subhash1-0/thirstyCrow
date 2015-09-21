// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testErrors_26.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::MemoryStorageTest_testErrors_26::MemoryStorageTest_testErrors_26(MemoryStorageTest *MemoryStorageTest_this, ::rice::Continuation* insertNullValue)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , insertNullValue(insertNullValue)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testErrors_26::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        MemoryStorageTest_this->stepDone(Test::FAILURE(), u"Randon insert tests failed."_j);
        return;
    }
    MemoryStorageTest_this->sectionStart(u"Testing Error Cases"_j);
    MemoryStorageTest_this->stepStart(u"Inserting null key"_j);
    npc(MemoryStorageTest_this->storage)->store(nullptr, nullptr, u"null key"_j, insertNullValue);
}

void rice::persistence::testing::MemoryStorageTest_testErrors_26::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testErrors_26::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testErrors_26::getClass0()
{
    return class_();
}

