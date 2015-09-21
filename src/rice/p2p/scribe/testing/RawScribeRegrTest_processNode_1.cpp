// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/RawScribeRegrTest.java
#include <rice/p2p/scribe/testing/RawScribeRegrTest_processNode_1.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/scribe/testing/RawScribeRegrTest_RawTestScribeContent.hpp>
#include <rice/p2p/scribe/testing/RawScribeRegrTest.hpp>

rice::p2p::scribe::testing::RawScribeRegrTest_processNode_1::RawScribeRegrTest_processNode_1(RawScribeRegrTest *RawScribeRegrTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawScribeRegrTest_this(RawScribeRegrTest_this)
{
    clinit();
    ctor();
}

rice::p2p::scribe::ScribeContent* rice::p2p::scribe::testing::RawScribeRegrTest_processNode_1::deserializeScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */
{
    switch (contentType) {
    case RawScribeRegrTest_RawTestScribeContent::TYPE:
        return new RawScribeRegrTest_RawTestScribeContent(buf, endpoint);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type: "_j)->append(contentType)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::RawScribeRegrTest_processNode_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::scribe::testing::RawScribeRegrTest_processNode_1::getClass0()
{
    return class_();
}

