// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1_receive_6_1_1_1_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1(RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1 *RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this, ::rice::p2p::past::PastImpl* remote2, ::rice::p2p::commonapi::Id* id)
    : super(RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this(RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this)
    , remote2(remote2)
    , id(id)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->assertTrue(u"Removal of file 1 should succeed"_j, npc((java_cast< ::java::lang::Boolean* >(result)))->booleanValue());
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->stepDone();
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->stepStart(u"File 2 Removal"_j);
    npc(npc(remote2)->getStorageManager())->unstore(id, new RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1_receive_6_1_1_1_1_1(this));
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1::getClass0()
{
    return class_();
}

