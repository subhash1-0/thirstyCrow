// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java

#pragma once

#include <org/mpisws/p2p/transport/bandwidthmeasure/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this);
    static ::java::lang::Class *class_();
    BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTransportLayer;
    friend class BandwidthMeasuringTransportLayer_MySocket;
    friend class BandwidthMeasuringTransportLayer_openSocket_2;
};
