// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_exampleB_5.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLivenessProximity.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5::BandwidthLimitingTransportLayer_exampleB_5(int32_t amt, int32_t time, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , amt(amt)
    , time(time)
{
    clinit();
    ctor(nf, startPort, env);
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5::BandwidthLimitingTransportLayer_exampleB_5(int32_t amt, int32_t time, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , amt(amt)
    , time(time)
{
    clinit();
    ctor(nf, bindAddress, startPort, env);
}

rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5::getSourceRouteManagerLayer(::org::mpisws::p2p::transport::TransportLayer* ltl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::liveness::Pinger* pinger, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) /* throws(IOException) */
{
    auto const srm = java_cast< ::rice::pastry::socket::SocketPastryNodeFactory_TransLivenessProximity* >(super::getSourceRouteManagerLayer(ltl, livenessProvider, pinger, pn, proxyAddress, esrFactory));
    auto const bll = new BandwidthLimitingTransportLayer(npc(srm)->getTransportLayer(), amt, time, npc(pn)->getEnvironment());
    return new BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1(this, bll, srm);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleB_5::getClass0()
{
    return class_();
}

