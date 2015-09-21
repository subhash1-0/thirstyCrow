// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_NonOverwritingTestPastContent.hpp>

#include <rice/p2p/past/PastContent.hpp>

rice::p2p::past::testing::PastRegrTest_NonOverwritingTestPastContent::PastRegrTest_NonOverwritingTestPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::PastRegrTest_NonOverwritingTestPastContent::PastRegrTest_NonOverwritingTestPastContent(::rice::p2p::commonapi::Id* id, int32_t version) 
    : PastRegrTest_NonOverwritingTestPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,version);
}

void rice::p2p::past::testing::PastRegrTest_NonOverwritingTestPastContent::ctor(::rice::p2p::commonapi::Id* id, int32_t version)
{
    super::ctor(id, version);
}

rice::p2p::past::PastContent* rice::p2p::past::testing::PastRegrTest_NonOverwritingTestPastContent::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    return existingContent;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_NonOverwritingTestPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.PastRegrTest.NonOverwritingTestPastContent", 64);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_NonOverwritingTestPastContent::getClass0()
{
    return class_();
}

