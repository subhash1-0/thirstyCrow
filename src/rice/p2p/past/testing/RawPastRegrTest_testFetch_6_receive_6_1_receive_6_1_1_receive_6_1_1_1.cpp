// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1(RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1 *RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastContent* file1, ::java::lang::Object* received1, ::rice::p2p::past::PastImpl* remote1, ::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastImpl* remote2)
    : super(RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this(RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this)
    , file2(file2)
    , file1(file1)
    , received1(received1)
    , remote1(remote1)
    , id(id)
    , remote2(remote2)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->assertTrue(u"Result should be non-null"_j, result != nullptr);
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->assertEquals(u"Result should be correct"_j, file2, result);
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->assertTrue(u"Result should not be file 1"_j, (!npc(file1)->equals(result)));
    auto const received2 = result;
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->stepDone();
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->stepStart(u"File 1 and 2 Different"_j);
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->assertTrue(u"Files should not be equal"_j, (!npc(received1)->equals(received2)));
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->stepDone();
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->stepStart(u"File 1 Removal"_j);
    npc(npc(remote1)->getStorageManager())->unstore(id, new RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1(this, remote2, id));
    RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_this->RawPastRegrTest_testFetch_6_receive_6_1_this->RawPastRegrTest_testFetch_6_this->RawPastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1::getClass0()
{
    return class_();
}

