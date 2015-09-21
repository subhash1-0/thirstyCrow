// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4_receive_4_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1_receive_4_1_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1::PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1(PastRegrTest_testFetch_4_receive_4_1 *PastRegrTest_testFetch_4_receive_4_1_this, ::rice::p2p::past::PastContent* file1, ::rice::p2p::past::PastContent* file2, ::rice::p2p::past::PastImpl* local, ::rice::p2p::past::PastContentHandle* handle2, ::rice::p2p::past::PastImpl* remote1, ::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastImpl* remote2)
    : super(PastRegrTest_testFetch_4_receive_4_1_this->PastRegrTest_testFetch_4_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testFetch_4_receive_4_1_this(PastRegrTest_testFetch_4_receive_4_1_this)
    , file1(file1)
    , file2(file2)
    , local(local)
    , handle2(handle2)
    , remote1(remote1)
    , id(id)
    , remote2(remote2)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testFetch_4_receive_4_1_this->PastRegrTest_testFetch_4_this->PastRegrTest_this->assertTrue(u"Result should be non-null"_j, result != nullptr);
    PastRegrTest_testFetch_4_receive_4_1_this->PastRegrTest_testFetch_4_this->PastRegrTest_this->assertEquals(u"Result should be correct"_j, file1, result);
    PastRegrTest_testFetch_4_receive_4_1_this->PastRegrTest_testFetch_4_this->PastRegrTest_this->assertTrue(u"Result should not be file 2"_j, (!npc(file2)->equals(result)));
    auto const received1 = result;
    PastRegrTest_testFetch_4_receive_4_1_this->PastRegrTest_testFetch_4_this->PastRegrTest_this->stepDone();
    PastRegrTest_testFetch_4_receive_4_1_this->PastRegrTest_testFetch_4_this->PastRegrTest_this->stepStart(u"File 2 Fetch"_j);
    npc(local)->fetch(handle2, static_cast< ::rice::Continuation* >(new PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1_receive_4_1_1_1(this, file2, file1, received1, remote1, id, remote2)));
    PastRegrTest_testFetch_4_receive_4_1_this->PastRegrTest_testFetch_4_this->PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testFetch_4_receive_4_1_receive_4_1_1::getClass0()
{
    return class_();
}

