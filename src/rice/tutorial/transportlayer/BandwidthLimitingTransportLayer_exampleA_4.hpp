// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportlayer/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleA_4
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;

    // Generated

public:
    BandwidthLimitingTransportLayer_exampleA_4(int32_t amt, int32_t time, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    BandwidthLimitingTransportLayer_exampleA_4(int32_t amt, int32_t time, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    int32_t amt;
    int32_t time;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthLimitingTransportLayer;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1;
    friend class BandwidthLimitingTransportLayer_sendMessage_2;
    friend class BandwidthLimitingTransportLayer_openSocket_3;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingSocket;
    friend class BandwidthLimitingTransportLayer_exampleB_5;
    friend class BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1;
};
