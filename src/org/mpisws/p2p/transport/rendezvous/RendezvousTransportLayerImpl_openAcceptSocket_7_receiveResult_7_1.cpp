// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openAcceptSocket_7.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1::RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1(RendezvousTransportLayerImpl_openAcceptSocket_7 *RendezvousTransportLayerImpl_openAcceptSocket_7_this, ::java::nio::ByteBuffer* writeBuffer, RendezvousContact* requestor, RendezvousContact* middleMan, int32_t uid, ::java::nio::ByteBuffer* readBuffer)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_openAcceptSocket_7_this(RendezvousTransportLayerImpl_openAcceptSocket_7_this)
    , writeBuffer(writeBuffer)
    , requestor(requestor)
    , middleMan(middleMan)
    , uid(uid)
    , readBuffer(readBuffer)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(writeBuffer)->hasRemaining()) {
        auto bytesWritten = npc(socket)->write(writeBuffer);
        if(bytesWritten < 0) {
            if(npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Channel closed in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(middleMan))
                    ->append(u","_j)
                    ->append(uid)
                    ->append(u")"_j)->toString());

            return;
        }
        if(npc(writeBuffer)->hasRemaining()) {
            npc(socket)->register_(false, true, this);
            return;
        }
    }
    if(!npc(writeBuffer)->hasRemaining()) {
        if(npc(readBuffer)->hasRemaining()) {
            auto bytesRead = npc(socket)->read(readBuffer);
            if(bytesRead < 0) {
                if(npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Channel closed in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
                        ->append(u","_j)
                        ->append(static_cast< ::java::lang::Object* >(middleMan))
                        ->append(u","_j)
                        ->append(uid)
                        ->append(u")"_j)->toString());

                return;
            }
            if(npc(readBuffer)->hasRemaining()) {
                npc(socket)->register_(true, false, this);
                return;
            }
        }
        npc(readBuffer)->flip();
        auto response = npc(readBuffer)->get();
        switch (response) {
        case RendezvousTransportLayerImpl::CONNECTION_RESPONSE_SUCCESS:
            if(npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"success in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(middleMan))
                    ->append(u","_j)
                    ->append(uid)
                    ->append(u")"_j)->toString());

            npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->callback)->incomingSocket(socket);
            return;
        default:
            if(npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Failed to connect in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(middleMan))
                    ->append(u","_j)
                    ->append(uid)
                    ->append(u")"_j)->toString());

            return;
        }

    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* s, ::java::lang::Exception* ex)
{
    if(npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(RendezvousTransportLayerImpl_openAcceptSocket_7_this->RendezvousTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Failure opening socket in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(middleMan))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString(), ex);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1::getClass0()
{
    return class_();
}

