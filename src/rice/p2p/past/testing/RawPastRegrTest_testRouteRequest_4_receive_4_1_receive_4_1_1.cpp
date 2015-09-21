// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4_receive_4_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1(RawPastRegrTest_testRouteRequest_4_receive_4_1 *RawPastRegrTest_testRouteRequest_4_receive_4_1_this, ::rice::p2p::past::PastContent* file, ::rice::p2p::past::PastImpl* remote, ::rice::p2p::commonapi::Id* remoteId)
    : super(RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_testRouteRequest_4_receive_4_1_this(RawPastRegrTest_testRouteRequest_4_receive_4_1_this)
    , file(file)
    , remote(remote)
    , remoteId(remoteId)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->assertTrue(u"File should not be null"_j, result != nullptr);
    RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->assertEquals(u"Lookup of file should be correct"_j, file, result);
    RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->stepDone();
    RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->stepStart(u"Local File Lookup"_j);
    npc(npc(remote)->getStorageManager())->getObject(remoteId, new RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1(this, file));
    RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->simulate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1::getClass0()
{
    return class_();
}

