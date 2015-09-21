// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/persistence/Storage.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27_receiveResult_27_1.hpp>
#include <rice/persistence/testing/MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1.hpp>
#include <rice/persistence/testing/MemoryStorageTest.hpp>
#include <rice/persistence/testing/Test.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1::MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1(MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1 *MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this, ::java::util::HashSet* tmp)
    : super(*static_cast< ::default_init_tag* >(0))
    , MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this(MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this)
    , tmp(tmp)
{
    clinit();
    init();
    ctor();
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1::init()
{
    id = nullptr;
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1::receiveResult(::java::lang::Object* o)
{
    if(npc(o)->equals(new ::java::lang::Boolean(false))) {
        MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this->MemoryStorageTest_testVariableLength_27_receiveResult_27_1_this->MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->stepDone(Test::FAILURE(), ::java::lang::StringBuilder().append(u"Delete of Id "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" failed"_j)->toString());
        return;
    }
    if(npc(tmp)->size() > 0) {
        id = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(npc(tmp)->iterator())->next()));
        npc(tmp)->remove(static_cast< ::java::lang::Object* >(id));
        npc(MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this->MemoryStorageTest_testVariableLength_27_receiveResult_27_1_this->MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->storage)->unstore(id, this);
    } else {
        MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this->MemoryStorageTest_testVariableLength_27_receiveResult_27_1_this->MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->stepDone(Test::SUCCESS());
        MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this->MemoryStorageTest_testVariableLength_27_receiveResult_27_1_this->MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->sectionEnd();
        npc(::java::lang::System::out())->println(u"All tests completed successfully - exiting."_j);
        ::java::lang::System::exit(0);
    }
}

void rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1::receiveException(::java::lang::Exception* e)
{
    MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_this->MemoryStorageTest_testVariableLength_27_receiveResult_27_1_this->MemoryStorageTest_testVariableLength_27_this->MemoryStorageTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::testing::MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1::getClass0()
{
    return class_();
}

