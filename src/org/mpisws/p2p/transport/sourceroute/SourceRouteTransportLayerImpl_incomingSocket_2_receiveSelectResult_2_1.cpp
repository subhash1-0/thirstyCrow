// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1(SourceRouteTransportLayerImpl_incomingSocket_2 *SourceRouteTransportLayerImpl_incomingSocket_2_this, ::java::nio::ByteBuffer* b, SourceRoute* sr, ::org::mpisws::p2p::transport::P2PSocket* socka)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteTransportLayerImpl_incomingSocket_2_this(SourceRouteTransportLayerImpl_incomingSocket_2_this)
    , b(b)
    , sr(sr)
    , socka(socka)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sockb)
{
    npc(sockb)->register_(false, true, new SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1(this, b, sr, socka, sockb));
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(socka)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1::getClass0()
{
    return class_();
}

