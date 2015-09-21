// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocket_1.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1::RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1(RendezvousTransportLayerImpl_openSocket_1 *RendezvousTransportLayerImpl_openSocket_1_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::SocketRequestHandle* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_openSocket_1_this(RendezvousTransportLayerImpl_openSocket_1_this)
    , deliverSocketToMe(deliverSocketToMe)
    , handle(handle)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1::receiveResult(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    npc(deliverSocketToMe)->receiveResult(handle, socket);
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(deliverSocketToMe)->receiveException(handle, exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1::getClass0()
{
    return class_();
}

