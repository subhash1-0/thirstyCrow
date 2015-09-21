// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest_main_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>
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

org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1::BandwidthMeasuringTLTest_main_1(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor(nf, startPort, env);
}

org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1::BandwidthMeasuringTLTest_main_1(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor(nf, bindAddress, startPort, env);
}

org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto wtl = java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(super::getWireTransportLayer(innermostAddress, pn));
    auto const ret = new ::rice::tutorial::transportlayer::BandwidthLimitingTransportLayer(wtl, int32_t(40000), int32_t(1000), npc(pn)->getEnvironment());
    auto const ret2 = new ::org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer(int32_t(5000), ret, npc(pn)->getEnvironment());
    npc(npc(npc(pn)->getEnvironment())->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1(this, ret2)), static_cast< int64_t >(int32_t(3000)), static_cast< int64_t >(int32_t(3000)));
    return ret2;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1::getClass0()
{
    return class_();
}

