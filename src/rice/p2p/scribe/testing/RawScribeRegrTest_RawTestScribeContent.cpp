// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/RawScribeRegrTest.java
#include <rice/p2p/scribe/testing/RawScribeRegrTest_RawTestScribeContent.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/scribe/Topic.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::RawScribeRegrTest_RawTestScribeContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::RawScribeRegrTest_RawTestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num) 
    : RawScribeRegrTest_RawTestScribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(topic,num);
}

rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::RawScribeRegrTest_RawTestScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : RawScribeRegrTest_RawTestScribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::TYPE;

void rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::ctor(::rice::p2p::scribe::Topic* topic, int32_t num)
{
    super::ctor(topic, num);
}

int16_t rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::getType()
{
    return TYPE;
}

void rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(new ::rice::p2p::scribe::Topic(buf, endpoint), npc(buf)->readInt());
}

void rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(topic)->serialize(buf);
    npc(buf)->writeInt(num);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.testing.RawScribeRegrTest.RawTestScribeContent", 62);
    return c;
}

java::lang::Class* rice::p2p::scribe::testing::RawScribeRegrTest_RawTestScribeContent::getClass0()
{
    return class_();
}

