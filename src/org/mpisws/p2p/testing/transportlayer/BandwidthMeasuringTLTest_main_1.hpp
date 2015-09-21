// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;

    // Generated

public:
    BandwidthMeasuringTLTest_main_1(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    BandwidthMeasuringTLTest_main_1(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTLTest;
    friend class BandwidthMeasuringTLTest_MyMsg;
    friend class BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1;
};
