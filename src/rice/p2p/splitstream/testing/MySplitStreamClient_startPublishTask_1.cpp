// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/MySplitStreamClient.java
#include <rice/p2p/splitstream/testing/MySplitStreamClient_startPublishTask_1.hpp>

#include <rice/p2p/splitstream/testing/MySplitStreamClient.hpp>

rice::p2p::splitstream::testing::MySplitStreamClient_startPublishTask_1::MySplitStreamClient_startPublishTask_1(MySplitStreamClient *MySplitStreamClient_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MySplitStreamClient_this(MySplitStreamClient_this)
{
    clinit();
    ctor();
}

void rice::p2p::splitstream::testing::MySplitStreamClient_startPublishTask_1::run()
{
    MySplitStreamClient_this->publishNext();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::testing::MySplitStreamClient_startPublishTask_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::splitstream::testing::MySplitStreamClient_startPublishTask_1::getClass0()
{
    return class_();
}

