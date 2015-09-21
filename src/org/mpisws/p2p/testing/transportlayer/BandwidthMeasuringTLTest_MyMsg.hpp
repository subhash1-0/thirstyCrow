// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_MyMsg
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;
    int32_t getPriority() override;

    // Generated
    BandwidthMeasuringTLTest_MyMsg();
protected:
    BandwidthMeasuringTLTest_MyMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTLTest;
    friend class BandwidthMeasuringTLTest_main_1;
    friend class BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1;
};
