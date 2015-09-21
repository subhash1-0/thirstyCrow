// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_openSocket_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1::SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1(SourceRouteTransportLayerImpl_openSocket_1 *SourceRouteTransportLayerImpl_openSocket_1_this, ::org::mpisws::p2p::transport::P2PSocket* result)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteTransportLayerImpl_openSocket_1_this(SourceRouteTransportLayerImpl_openSocket_1_this)
    , result(result)
{
    clinit();
    ctor();
}

bool org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1::cancel()
{
    npc(result)->close();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1::getClass0()
{
    return class_();
}

