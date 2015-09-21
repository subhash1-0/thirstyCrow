// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2_receive_2_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1(PastRegrTest_testRouteRequest_2_receive_2_1 *PastRegrTest_testRouteRequest_2_receive_2_1_this, ::rice::p2p::past::PastContent* file, ::rice::p2p::past::PastImpl* remote, ::rice::p2p::commonapi::Id* remoteId)
    : super(PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testRouteRequest_2_receive_2_1_this(PastRegrTest_testRouteRequest_2_receive_2_1_this)
    , file(file)
    , remote(remote)
    , remoteId(remoteId)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->assertTrue(u"File should not be null"_j, result != nullptr);
    PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->assertEquals(u"Lookup of file should be correct"_j, file, result);
    PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->stepDone();
    PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->stepStart(u"Local File Lookup"_j);
    npc(npc(remote)->getStorageManager())->getObject(remoteId, new PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1(this, file));
    PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1::getClass0()
{
    return class_();
}

