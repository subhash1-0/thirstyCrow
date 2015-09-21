// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_readAcceptHeader_6.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1(RendezvousTransportLayerImpl_readAcceptHeader_6 *RendezvousTransportLayerImpl_readAcceptHeader_6_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_readAcceptHeader_6_this(RendezvousTransportLayerImpl_readAcceptHeader_6_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1::receiveException(::java::lang::Exception* exception)
{
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1::receiveResult(::org::mpisws::p2p::transport::P2PSocket* result)
{
    npc(result)->close();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::P2PSocket* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1::getClass0()
{
    return class_();
}

