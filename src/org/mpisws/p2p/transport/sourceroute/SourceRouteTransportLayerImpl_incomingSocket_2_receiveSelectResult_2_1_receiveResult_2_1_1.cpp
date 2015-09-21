// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/Forwarder.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTap.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.hpp>

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

org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1(SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1 *SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_this, ::java::nio::ByteBuffer* b, SourceRoute* sr, ::org::mpisws::p2p::transport::P2PSocket* socka, ::org::mpisws::p2p::transport::P2PSocket* sockb)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_this(SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_this)
    , b(b)
    , sr(sr)
    , socka(socka)
    , sockb(sockb)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead || !canWrite)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected to write! "_j)->append(canRead)
            ->append(u","_j)
            ->append(canWrite)->toString());

    npc(socket)->write(b);
    if(npc(b)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        for (auto _i = npc(SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_this->SourceRouteTransportLayerImpl_incomingSocket_2_this->SourceRouteTransportLayerImpl_this->taps)->iterator(); _i->hasNext(); ) {
            SourceRouteTap* tap = java_cast< SourceRouteTap* >(_i->next());
            {
                npc(tap)->socketOpened(sr, socka, sockb);
            }
        }
        new Forwarder(sr, socka, sockb, SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_this->SourceRouteTransportLayerImpl_incomingSocket_2_this->SourceRouteTransportLayerImpl_this->logger);
    }
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_this->SourceRouteTransportLayerImpl_incomingSocket_2_this->SourceRouteTransportLayerImpl_this->errorHandler)->receivedException(sr, e);
    npc(socka)->close();
    npc(sockb)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1::getClass0()
{
    return class_();
}

