// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_receive_3_1_1_1_1_1.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3_receive_3_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_receive_3_1_1_1_1_1::PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_receive_3_1_1_1_1_1(PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1 *PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this, ::rice::p2p::past::PastContent* newFile)
    : super(PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_this->PastRegrTest_testVersionControl_3_this->PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
    , PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this(PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this)
    , newFile(newFile)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_receive_3_1_1_1_1_1::receive(::java::lang::Object* result) /* throws(Exception) */
{
    PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_this->PastRegrTest_testVersionControl_3_this->PastRegrTest_this->assertTrue(u"Non-Overwriting file should not be null"_j, result != nullptr);
    PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_this->PastRegrTest_testVersionControl_3_this->PastRegrTest_this->assertEquals(u"Lookup of non-overwriting file should be correct (second) version"_j, newFile, result);
    PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_this->PastRegrTest_testVersionControl_3_this->PastRegrTest_this->stepDone();
    PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_this->PastRegrTest_testVersionControl_3_this->PastRegrTest_this->sectionDone();
    PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_this->PastRegrTest_testVersionControl_3_receive_3_1_this->PastRegrTest_testVersionControl_3_this->PastRegrTest_this->testFetch();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_receive_3_1_1_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_testVersionControl_3_receive_3_1_receive_3_1_1_receive_3_1_1_1_receive_3_1_1_1_1_receive_3_1_1_1_1_1::getClass0()
{
    return class_();
}

