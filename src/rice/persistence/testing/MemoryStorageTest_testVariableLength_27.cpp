// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27_receiveResult_27_1.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::MemoryStorageTest_testVariableLength_27::MemoryStorageTest_testVariableLength_27(MemoryStorageTest *MemoryStorageTest_this, ::java::util::HashSet* all, ::java::util::HashSet* tmp)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_this(MemoryStorageTest_this)
    , all(all)
    , tmp(tmp)
{
    clinit();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        MemoryStorageTest_this->stepDone(Test::FAILURE(), u"Error tests failed"_j);
        return;
    }
    MemoryStorageTest_this->sectionStart(u"Testing variable-length Ids"_j);
    MemoryStorageTest_this->stepStart(u"Inserting a whole bunch of Ids"_j);
    (new MemoryStorageTest_testVariableLength_27_receiveResult_27_1(this, all, tmp))->receiveResult(static_cast< ::java::lang::Object* >(::java::lang::Boolean::TRUE()));
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testVariableLength_27::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testVariableLength_27::getClass0()
{
    return class_();
}

