// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openAcceptSocket_7.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/BindException.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7::RendezvousTransportLayerImpl_openAcceptSocket_7(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::java::nio::ByteBuffer* writeBuffer, RendezvousContact* requestor, RendezvousContact* middleMan, int32_t uid, ::java::nio::ByteBuffer* readBuffer)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousTransportLayerImpl_this(RendezvousTransportLayerImpl_this)
    , writeBuffer(writeBuffer)
    , requestor(requestor)
    , middleMan(middleMan)
    , uid(uid)
    , readBuffer(readBuffer)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    try {
        (new RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1(this, writeBuffer, requestor, middleMan, uid, readBuffer))->receiveSelectResult(sock, false, true);
    } catch (::java::io::IOException* ioe) {
        if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(RendezvousTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(middleMan))
                ->append(u","_j)
                ->append(uid)
                ->append(u")"_j)->toString(), ioe);

    }
}

void org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    if(dynamic_cast< ::java::net::BindException* >(ex) != nullptr) {
        RendezvousTransportLayerImpl_this->openAcceptSocket(requestor, middleMan, uid);
        return;
    }
    if(npc(RendezvousTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(RendezvousTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Failure opening socket in openAcceptSocket("_j)->append(static_cast< ::java::lang::Object* >(requestor))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(middleMan))
            ->append(u","_j)
            ->append(uid)
            ->append(u")"_j)->toString(), ex);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openAcceptSocket_7::getClass0()
{
    return class_();
}

