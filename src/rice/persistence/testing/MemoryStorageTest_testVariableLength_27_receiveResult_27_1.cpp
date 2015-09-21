// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27_receiveResult_27_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1.hpp>
#include <rice/persistence/testing/MemoryStorageTest_VariableId.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1::MemoryStorageTest_testVariableLength_27_receiveResult_27_1(MemoryStorageTest_testVariableLength_27 *MemoryStorageTest_testVariableLength_27_this, ::java::util::HashSet* all, ::java::util::HashSet* tmp)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_testVariableLength_27_this(MemoryStorageTest_testVariableLength_27_this)
    , all(all)
    , tmp(tmp)
{
    clinit();
    init();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1::init()
{
    num = int32_t(0);
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Insert of Id #"_j)->append(num)
            ->append(u" failed"_j)->toString());
        return;
    }
    if(num < 1000) {
        num++;
        npc(MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->storage)->store(new MemoryStorageTest_VariableId(MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this, num), nullptr, ::java::lang::StringBuilder().append(num)->append(u" length"_j)->toString(), this);
    } else {
        MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->stepDone(Test::SUCCESS());
        MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->stepStart(u"Reinserting same Ids"_j);
        (new MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1(this, all, tmp))->receiveResult(static_cast< ::java::lang::Object* >(::java::lang::Boolean::TRUE()));
    }
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1::getClass0()
{
    return class_();
}

