// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest_MyMsg.hpp>

org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_MyMsg::BandwidthMeasuringTLTest_MyMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_MyMsg::BandwidthMeasuringTLTest_MyMsg()
    : BandwidthMeasuringTLTest_MyMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_MyMsg::getPriority()
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_MyMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.BandwidthMeasuringTLTest.MyMsg", 68);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_MyMsg::getClass0()
{
    return class_();
}

