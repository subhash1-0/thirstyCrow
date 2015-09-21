// Generated from /pastry-2.1/src/rice/tutorial/scribe/MyScribeClient.java
#include <rice/tutorial/scribe/MyScribeClient_PublishContent.hpp>

#include <rice/tutorial/scribe/MyScribeClient.hpp>

rice::tutorial::scribe::MyScribeClient_PublishContent::MyScribeClient_PublishContent(MyScribeClient *MyScribeClient_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyScribeClient_this(MyScribeClient_this)
{
    clinit();
}

rice::tutorial::scribe::MyScribeClient_PublishContent::MyScribeClient_PublishContent(MyScribeClient *MyScribeClient_this)
    : MyScribeClient_PublishContent(MyScribeClient_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t rice::tutorial::scribe::MyScribeClient_PublishContent::getPriority()
{
    return MAX_PRIORITY;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::scribe::MyScribeClient_PublishContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.scribe.MyScribeClient.PublishContent", 50);
    return c;
}

java::lang::Class* rice::tutorial::scribe::MyScribeClient_PublishContent::getClass0()
{
    return class_();
}

