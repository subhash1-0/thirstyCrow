// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLivenessProximity.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_exampleB_5.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1(BandwidthLimitingTransportLayer_exampleB_5 *BandwidthLimitingTransportLayer_exampleB_5_this, BandwidthLimitingTransportLayer* bll, ::rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity* srm)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthLimitingTransportLayer_exampleB_5_this(BandwidthLimitingTransportLayer_exampleB_5_this)
    , bll(bll)
    , srm(srm)
{
    clinit();
    ctor();
}

org::mpisws::p2p::transport::TransportLayer* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1::getTransportLayer()
{
    return bll;
}

org::mpisws::p2p::transport::liveness::LivenessProvider* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1::getLivenessProvider()
{
    return npc(srm)->getLivenessProvider();
}

org::mpisws::p2p::transport::proximity::ProximityProvider* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1::getProximityProvider()
{
    return npc(srm)->getProximityProvider();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1::getClass0()
{
    return class_();
}

