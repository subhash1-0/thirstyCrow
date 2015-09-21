// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_exampleA_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <rice/pastry/PastryNode.hpp>
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

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleA_4::BandwidthLimitingTransportLayer_exampleA_4(int32_t amt, int32_t time, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , amt(amt)
    , time(time)
{
    clinit();
    ctor(nf, startPort, env);
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleA_4::BandwidthLimitingTransportLayer_exampleA_4(int32_t amt, int32_t time, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , amt(amt)
    , time(time)
{
    clinit();
    ctor(nf, bindAddress, startPort, env);
}

org::mpisws::p2p::transport::TransportLayer* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleA_4::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto wtl = java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(super::getWireTransportLayer(innermostAddress, pn));
    return new BandwidthLimitingTransportLayer(wtl, amt, time, npc(pn)->getEnvironment());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleA_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_exampleA_4::getClass0()
{
    return class_();
}

