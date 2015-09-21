// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_incomingSocket_4.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_IncomingPilot.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_incomingSocket_4::RendezvousTransportLayerImpl_incomingSocket_4(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_incomingSocket_4::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u").rSR("_j)
            ->append(canRead)
            ->append(u","_j)
            ->append(canWrite)
            ->append(u")"_j)->toString());

    auto buf = ::java::nio::ByteBuffer::allocate(1);
    auto bytesRead = npc(socket)->read(buf);
    if(bytesRead == 0) {
        npc(socket)->register_(true, false, this);
        return;
    }
    if(bytesRead < 0) {
        npc(socket)->close();
        return;
    }
    npc(buf)->flip();
    auto socketType = npc(buf)->get();
    switch (socketType) {
    case RendezvousTransportLayerImpl::NORMAL_SOCKET:
        if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u").rSR("_j)
                ->append(canRead)
                ->append(u","_j)
                ->append(canWrite)
                ->append(u"):NORMAL"_j)->toString());

        npc(RendezvousTransportLayerImpl_this->callback)->incomingSocket(socket);
        return;
    case RendezvousTransportLayerImpl::CONNECTOR_SOCKET:
        RendezvousTransportLayerImpl_this->readConnectHeader(socket);
        return;
    case RendezvousTransportLayerImpl::ACCEPTOR_SOCKET:
        RendezvousTransportLayerImpl_this->readAcceptHeader(socket);
        return;
    case RendezvousTransportLayerImpl::PILOT_SOCKET:
        new RendezvousTransportLayerImpl_IncomingPilot(RendezvousTransportLayerImpl_this, socket);
        return;
    }

}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_incomingSocket_4::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_incomingSocket_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_incomingSocket_4::getClass0()
{
    return class_();
}

