// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.java
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient_PublishContent.hpp>

#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.hpp>

org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient_PublishContent::MyScribeClient_PublishContent(MyScribeClient *MyScribeClient_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , MyScribeClient_this(MyScribeClient_this)
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient_PublishContent::MyScribeClient_PublishContent(MyScribeClient *MyScribeClient_this)
    : MyScribeClient_PublishContent(MyScribeClient_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient_PublishContent::getPriority()
{
    return MAX_PRIORITY;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient_PublishContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.MyScribeClient.PublishContent", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient_PublishContent::getClass0()
{
    return class_();
}

