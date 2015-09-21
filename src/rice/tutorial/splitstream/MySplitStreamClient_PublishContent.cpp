// Generated from /pastry-2.1/src/rice/tutorial/splitstream/MySplitStreamClient.java
#include <rice/tutorial/splitstream/MySplitStreamClient_PublishContent.hpp>

#include <rice/p2p/commonapi/Message.hpp>
#include <rice/tutorial/splitstream/MySplitStreamClient.hpp>

rice::tutorial::splitstream::MySplitStreamClient_PublishContent::MySplitStreamClient_PublishContent(MySplitStreamClient *MySplitStreamClient_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MySplitStreamClient_this(MySplitStreamClient_this)
{
    clinit();
}

rice::tutorial::splitstream::MySplitStreamClient_PublishContent::MySplitStreamClient_PublishContent(MySplitStreamClient *MySplitStreamClient_this)
    : MySplitStreamClient_PublishContent(MySplitStreamClient_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t rice::tutorial::splitstream::MySplitStreamClient_PublishContent::getPriority()
{
    return ::rice::p2p::commonapi::Message::MEDIUM_PRIORITY;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::splitstream::MySplitStreamClient_PublishContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.splitstream.MySplitStreamClient.PublishContent", 60);
    return c;
}

java::lang::Class* rice::tutorial::splitstream::MySplitStreamClient_PublishContent::getClass0()
{
    return class_();
}

