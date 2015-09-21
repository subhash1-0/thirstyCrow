// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribePolicy.java
#include <rice/p2p/scribe/ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage.hpp>

#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/ScribePolicy_DefaultScribePolicy.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>

rice::p2p::scribe::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage(ScribePolicy_DefaultScribePolicy *ScribePolicy_DefaultScribePolicy_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ScribePolicy_DefaultScribePolicy_this(ScribePolicy_DefaultScribePolicy_this)
{
    clinit();
}

rice::p2p::scribe::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage(ScribePolicy_DefaultScribePolicy *ScribePolicy_DefaultScribePolicy_this, ::rice::p2p::commonapi::NodeHandle* source, Topic* topic, int32_t i, ScribeContent* content) 
    : ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage(ScribePolicy_DefaultScribePolicy_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic,i,content);
}

void rice::p2p::scribe::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, Topic* topic, int32_t i, ScribeContent* content)
{
    super::ctor(source, topic, i, static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(nullptr));
    theContent = content;
}

rice::p2p::scribe::ScribeContent* rice::p2p::scribe::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage::getContent()
{
    return theContent;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.ScribePolicy.DefaultScribePolicy.BogusSubscribeMessage", 70);
    return c;
}

java::lang::Class* rice::p2p::scribe::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage::getClass0()
{
    return class_();
}

