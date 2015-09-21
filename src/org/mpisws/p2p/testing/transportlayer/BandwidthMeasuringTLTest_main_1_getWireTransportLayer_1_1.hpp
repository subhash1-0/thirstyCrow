// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1(BandwidthMeasuringTLTest_main_1 *BandwidthMeasuringTLTest_main_1_this, ::org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer* ret2);
    static ::java::lang::Class *class_();
    BandwidthMeasuringTLTest_main_1 *BandwidthMeasuringTLTest_main_1_this;
    ::org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer* ret2;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTLTest;
    friend class BandwidthMeasuringTLTest_MyMsg;
    friend class BandwidthMeasuringTLTest_main_1;
};
