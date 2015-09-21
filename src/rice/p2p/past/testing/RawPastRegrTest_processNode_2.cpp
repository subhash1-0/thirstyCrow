// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_processNode_2.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_NonOverwritingTestPastContent.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_TestPastContent.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest_VersionedTestPastContent.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

rice::p2p::past::testing::RawPastRegrTest_processNode_2::RawPastRegrTest_processNode_2(RawPastRegrTest *RawPastRegrTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor();
}

rice::p2p::past::PastContent* rice::p2p::past::testing::RawPastRegrTest_processNode_2::deserializePastContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */
{
    switch (contentType) {
    case RawPastRegrTest_TestPastContent::TYPE:
        return new RawPastRegrTest_TestPastContent(buf, endpoint, this);
    case RawPastRegrTest_VersionedTestPastContent::TYPE:
        return new RawPastRegrTest_VersionedTestPastContent(buf, endpoint, this);
    case RawPastRegrTest_NonOverwritingTestPastContent::TYPE:
        return new RawPastRegrTest_NonOverwritingTestPastContent(buf, endpoint, this);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type:"_j)->append(contentType)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_processNode_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_processNode_2::getClass0()
{
    return class_();
}

