// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportlayer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLivenessProximity.hpp>

struct default_init_tag;

class rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity
{

public:
    typedef ::java::lang::Object super;
    ::org::mpisws::p2p::transport::TransportLayer* getTransportLayer() override;
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* getLivenessProvider() override;
    ::org::mpisws::p2p::transport::proximity::ProximityProvider* getProximityProvider() override;

    // Generated
    BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1(BandwidthLimitingTransportLayer_exampleB_5 *BandwidthLimitingTransportLayer_exampleB_5_this, BandwidthLimitingTransportLayer* bll, ::rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity* srm);
    static ::java::lang::Class *class_();
    BandwidthLimitingTransportLayer_exampleB_5 *BandwidthLimitingTransportLayer_exampleB_5_this;
    BandwidthLimitingTransportLayer* bll;
    ::rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity* srm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthLimitingTransportLayer;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1;
    friend class BandwidthLimitingTransportLayer_sendMessage_2;
    friend class BandwidthLimitingTransportLayer_openSocket_3;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingSocket;
    friend class BandwidthLimitingTransportLayer_exampleA_4;
    friend class BandwidthLimitingTransportLayer_exampleB_5;
};
