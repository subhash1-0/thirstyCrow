// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1.hpp>

#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.hpp>

org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1::BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthMeasuringTransportLayer_this(BandwidthMeasuringTransportLayer_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1::run()
{
    BandwidthMeasuringTransportLayer_this->measure();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1::getClass0()
{
    return class_();
}

