// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2_receive_2_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1(PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1 *PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this, ::rice::p2p::past::PastContent* file)
    : super(PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this->PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this(PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this)
    , file(file)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this->PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->assertTrue(u"File should be inserted at known node"_j, result != nullptr);
    PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this->PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->assertEquals(u"Retrieved local file should be the same"_j, file, result);
    PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this->PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->stepDone();
    PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this->PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->sectionDone();
    PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_this->PastRegrTest_testRouteRequest_2_receive_2_1_this->PastRegrTest_testRouteRequest_2_this->PastRegrTest_this->testVersionControl();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testRouteRequest_2_receive_2_1_receive_2_1_1_receive_2_1_1_1::getClass0()
{
    return class_();
}

