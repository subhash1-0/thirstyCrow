// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openSocketViaPilot_3.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1::RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1(RendezvousTransportLayerImpl_openSocketViaPilot_3 *RendezvousTransportLayerImpl_openSocketViaPilot_3_this, ::java::nio::ByteBuffer* writeBuffer, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, int32_t uid, RendezvousContact* dest, RendezvousContact* middleMan, ::java::nio::ByteBuffer* readBuffer, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_openSocketViaPilot_3_this(RendezvousTransportLayerImpl_openSocketViaPilot_3_this)
    , writeBuffer(writeBuffer)
    , deliverSocketToMe(deliverSocketToMe)
    , handle(handle)
    , uid(uid)
    , dest(dest)
    , middleMan(middleMan)
    , readBuffer(readBuffer)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(writeBuffer)->hasRemaining()) {
        auto bytesWritten = npc(socket)->write(writeBuffer);
        if(bytesWritten < 0) {
            npc(deliverSocketToMe)->receiveException(handle, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Channel closed detected to <"_j)->append(uid)
                ->append(u"> "_j)
                ->append(static_cast< ::java::lang::Object* >(dest))
                ->append(u" via "_j)
                ->append(static_cast< ::java::lang::Object* >(middleMan))
                ->append(u" in "_j)
                ->append(static_cast< ::java::lang::Object* >(RendezvousTransportLayerImpl_openSocketViaPilot_3_this->RendezvousTransportLayerImpl_this))->toString()));
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
                npc(deliverSocketToMe)->receiveException(handle, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Channel closed detected to <"_j)->append(uid)
                    ->append(u"> "_j)
                    ->append(static_cast< ::java::lang::Object* >(dest))
                    ->append(u" via "_j)
                    ->append(static_cast< ::java::lang::Object* >(middleMan))
                    ->append(u" in "_j)
                    ->append(static_cast< ::java::lang::Object* >(RendezvousTransportLayerImpl_openSocketViaPilot_3_this->RendezvousTransportLayerImpl_this))->toString()));
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
            if(npc(RendezvousTransportLayerImpl_openSocketViaPilot_3_this->RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(RendezvousTransportLayerImpl_openSocketViaPilot_3_this->RendezvousTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"success in openSocketViaPilot<"_j)->append(uid)
                    ->append(u">("_j)
                    ->append(static_cast< ::java::lang::Object* >(dest))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(middleMan))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(handle))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(options))
                    ->append(u")"_j)->toString());

            npc(deliverSocketToMe)->receiveResult(handle, socket);
            return;
        default:
            npc(deliverSocketToMe)->receiveException(handle, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Failed to connect to <"_j)->append(uid)
                ->append(u"> "_j)
                ->append(static_cast< ::java::lang::Object* >(dest))
                ->append(u" via "_j)
                ->append(static_cast< ::java::lang::Object* >(middleMan))
                ->append(u" in "_j)
                ->append(static_cast< ::java::lang::Object* >(RendezvousTransportLayerImpl_openSocketViaPilot_3_this->RendezvousTransportLayerImpl_this))
                ->append(u" response:"_j)
                ->append(response)->toString()));
            return;
        }

    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverSocketToMe)->receiveException(handle, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1::getClass0()
{
    return class_();
}

