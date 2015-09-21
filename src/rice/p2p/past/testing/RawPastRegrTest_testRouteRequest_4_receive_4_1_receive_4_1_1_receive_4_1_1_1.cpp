// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4_receive_4_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1(RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1 *RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this, ::rice::p2p::past::PastContent* file)
    : super(RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this->RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this(RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this)
    , file(file)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this->RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->assertTrue(u"File should be inserted at known node"_j, result != nullptr);
    RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this->RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->assertEquals(u"Retrieved local file should be the same"_j, file, result);
    RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this->RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->stepDone();
    RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this->RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->sectionDone();
    RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_this->RawPastRegrTest_testRouteRequest_4_receive_4_1_this->RawPastRegrTest_testRouteRequest_4_this->RawPastRegrTest_this->testVersionControl();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1::getClass0()
{
    return class_();
}

