// Generated from /pastry-2.1/src/rice/tutorial/transportdirect/DistTutorial.java
#include <rice/tutorial/transportdirect/DistTutorial_DistTutorial_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/tutorial/transportdirect/DistTutorial.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::transportdirect::DistTutorial_DistTutorial_1::DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistTutorial_this(DistTutorial_this)
    , simulator(simulator)
{
    clinit();
    ctor(nf, startPort, env);
}

rice::tutorial::transportdirect::DistTutorial_DistTutorial_1::DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistTutorial_this(DistTutorial_this)
    , simulator(simulator)
{
    clinit();
    ctor(nf, bindAddress, startPort, env);
}

org::mpisws::p2p::transport::TransportLayer* rice::tutorial::transportdirect::DistTutorial_DistTutorial_1::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto tl = new ::org::mpisws::p2p::transport::direct::DirectTransportLayer(innermostAddress, simulator, npc(simulator)->generateNodeRecord(), npc(pn)->getEnvironment());
    return tl;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportdirect::DistTutorial_DistTutorial_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::transportdirect::DistTutorial_DistTutorial_1::getClass0()
{
    return class_();
}

